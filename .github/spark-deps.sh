#!/bin/sh
# Run in the FreeBSD VM of .github/workflows/spark-deps.yml: build devel/spark
# online, pack its maven repository into spark-<version>-deps.tgz, then build
# the port offline from that tarball like the package builders do.  Results
# go to out/ of the workspace.
set -e
W=$PWD
V=$SPARK_VERSION
D=spark-$V-deps.tgz
mkdir -p $W/out
freebsd-version; df -h /; sysctl -n hw.physmem hw.ncpu
mvn --version

git clone -q --depth 1 https://git.FreeBSD.org/ports.git /usr/ports
rm -rf /usr/ports/devel/spark
cp -R spark /usr/ports/devel/spark
grep PORTVERSION= /usr/ports/devel/spark/Makefile
cd /usr/ports/devel/spark
export BATCH=yes

# online build, which fills ${WRKDIR}/m2
make -DMAINTAINER_MODE makesum < /dev/null
if ! make -DMAINTAINER_MODE build > $W/out/build-online.log 2>&1 < /dev/null; then
	tail -n 300 $W/out/build-online.log
	exit 1
fi
tail -n 60 $W/out/build-online.log
make -DMAINTAINER_MODE make-deps < /dev/null
cp /usr/ports/distfiles/$D $W/out/
ls -l $W/out/$D

# offline build from the deps tarball, like the package builders
set +e
make clean < /dev/null
make makesum < /dev/null
cp distinfo $W/out/distinfo
if make stage > $W/out/build-offline.log 2>&1 < /dev/null; then
	tail -n 60 $W/out/build-offline.log
	(cd work/stage && find -s . -type f -o -type l | sed 's|^\./||') \
		> $W/out/staged-files.txt
	echo ok > $W/out/offline-status
else
	tail -n 300 $W/out/build-offline.log
	echo failed > $W/out/offline-status
fi
df -h /
exit 0
