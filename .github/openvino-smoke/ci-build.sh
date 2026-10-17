#!/bin/sh
# Run by .github/workflows/openvino-build.yml in the FreeBSD VM, from the
# top of the repository: build devel/openvino, test the package and leave
# the logs in out/.
set -e
W=$PWD
O=$W/out
freebsd-version
sysctl hw.ncpu hw.physmem
df -h

# the ports tree of the quarterly branch the packages come from
Y=$(date -u +%Y)
Q=$(( ($(date -u +%m | sed 's/^0//') - 1) / 3 + 1 ))
git clone -q --depth 1 -b ${Y}Q$Q \
  https://github.com/freebsd/freebsd-ports.git /usr/ports < /dev/null
echo "ports ${Y}Q$Q $(git -C /usr/ports log -1 --format=%h)"
rm -rf /usr/ports/devel/openvino
cp -R $W/openvino /usr/ports/devel/openvino
P=/usr/ports/devel/openvino

# the largest file system holds the work and distfiles
B=$(df -k | awk 'NR > 1 && $1 !~ /^(devfs|tmpfs|fdescfs|procfs)/ { if ($4 > m) { m = $4; d = $6 } } END { print d }')
echo "work on $B"
mkdir -p $B/ovwork $B/distfiles
export BATCH=yes DISTDIR=$B/distfiles WRKDIRPREFIX=$B/ovwork
MK="make -C $P NO_DEPENDS=yes"

$MK makesum < /dev/null
cp $P/distinfo $O/distinfo
cat $O/distinfo

# dependencies from packages
: > $O/missing-deps.txt
for d in $($MK build-depends-list run-depends-list < /dev/null | \
    sed -e 's,^/usr/ports/,,' -e 's,@.*,,' | sort -u); do
  pkg install -y $d < /dev/null >> $O/pkg.log 2>&1 || echo $d >> $O/missing-deps.txt
done
echo "missing dependency packages:"; cat $O/missing-deps.txt

# libraries the port bundles: installed, so that the build shows it uses
# the bundled copies, as it must on a system that has them
for d in math/onnx math/onednn devel/xbyak devel/nlohmann-json devel/flatbuffers; do
  if pkg install -y $d < /dev/null >> $O/pkg.log 2>&1; then
    echo "installed $d"
  else
    echo "could not install $d"
  fi
done

export CCACHE_DIR=$W/ccache CCACHE_MAXSIZE=8G
ccache -z > /dev/null
df -h $B
rc=0
timeout 280m $MK WITH_CCACHE_BUILD=yes stage < /dev/null \
  > $O/build.log 2>&1 || rc=$?
ccache -s | tee $O/ccache.txt
df -h $B
if [ $rc != 0 ]; then
  tail -n 300 $O/build.log
  echo "stage failed ($rc)"
  exit 1
fi
tail -n 20 $O/build.log

status=0
$MK stage-qa < /dev/null > $O/stage-qa.txt 2>&1 || status=1
cat $O/stage-qa.txt
$MK check-plist < /dev/null > $O/check-plist.txt 2>&1 || status=1
cat $O/check-plist.txt
$MK makeplist < /dev/null 2> /dev/null | \
  sed '1{/^\/you\/have\/to/d;}' > $O/pkg-plist.new || true
diff -u $P/pkg-plist $O/pkg-plist.new > $O/pkg-plist.diff || true
cat $O/pkg-plist.diff
(cd $($MK -V STAGEDIR) && find . -name '*.so*' | sort) > $O/stage-libs.txt
find $($MK -V WRKSRC)/bin -name '*.so' -path '*python*' | sort

$MK package < /dev/null > $O/package.log 2>&1 || { tail -n 50 $O/package.log; exit 1; }
# make package leaves the package in ${WRKDIR}/pkg without /usr/ports/packages
ls -l $($MK -V WRKDIR < /dev/null)/pkg/*.pkg
$MK install < /dev/null > $O/install.log 2>&1 || { tail -n 50 $O/install.log; exit 1; }
pkg info -x openvino

# smoke tests against the installed package
S=$W/.github/openvino-smoke
mkdir -p /tmp/smoke
if c++ -std=c++17 -O1 -I/usr/local/include $S/smoke.cpp \
    -L/usr/local/lib -lopenvino -o /tmp/smoke/smoke > $O/smoke-cpp.txt 2>&1 && \
  /tmp/smoke/smoke /tmp/smoke/smoke.xml >> $O/smoke-cpp.txt 2>&1 < /dev/null; then
  echo "C++ smoke test OK"
else
  echo "C++ smoke test FAILED"; status=1
fi
cat $O/smoke-cpp.txt
if (cd /tmp/smoke && benchmark_app -m /tmp/smoke/smoke.xml -d CPU \
    -niter 200 -hint latency) > $O/benchmark-app.txt 2>&1 < /dev/null; then
  echo "benchmark_app OK"
else
  echo "benchmark_app FAILED"; status=1
fi
cat $O/benchmark-app.txt
# the GPU plugin has to use the system OpenCL ICD loader, which
# finds the ICDs in /usr/local/etc/OpenCL/vendors
ldd /usr/local/lib/libopenvino_intel_gpu_plugin.so | tee $O/gpu-plugin-ldd.txt
grep -q '/usr/local/lib/libOpenCL.so' $O/gpu-plugin-ldd.txt || \
  { echo "GPU plugin does not use the system libOpenCL"; status=1; }
PY=$($MK -V PYTHON_CMD < /dev/null)
if (cd /tmp/smoke && $PY -I $S/smoke.py /tmp/smoke/smoke_py.xml) \
    > $O/smoke-py.txt 2>&1 < /dev/null; then
  echo "Python smoke test OK"
else
  echo "Python smoke test FAILED"; status=1
fi
cat $O/smoke-py.txt
exit $status
