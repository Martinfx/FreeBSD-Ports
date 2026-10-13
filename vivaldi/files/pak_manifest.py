#!/usr/bin/env python3
#
# Print the manifest of the Vivaldi UI app from the .pak files of the
# official Linux package.  The source tarball only has a template of it
# (vivapp/src/manifest.template.json), without the version and with other
# file names than the UI that is built from the closed vivapp sources, and
# the browser refuses to load the app with that.
#
# usage: pak_manifest.py FILE.pak ...

import gzip
import json
import struct
import sys


def resources(data):
    version = struct.unpack_from('<I', data)[0]
    if version == 4:
        count, _encoding = struct.unpack_from('<IB', data, 4)
        offset, entry = 9, '<HI'
        aliases = 0
    elif version == 5:
        _encoding, count, aliases = struct.unpack_from('<BxxxHH', data, 4)
        offset, entry = 12, '<HI'
    else:
        raise ValueError('unknown pak version %d' % version)
    size = struct.calcsize(entry)
    entries = [struct.unpack_from(entry, data, offset + i * size)
               for i in range(count + 1)]
    for (rid, start), (_next_id, end) in zip(entries, entries[1:]):
        yield rid, data[start:end]


def decode(blob):
    if blob[:2] == b'\x1f\x8b':
        return gzip.decompress(blob)
    if blob[:2] == b'\x1e\x9b':
        # Brotli, with a 6 byte size after the magic
        import brotli
        return brotli.decompress(blob[8:])
    return blob


def main():
    for path in sys.argv[1:]:
        with open(path, 'rb') as f:
            data = f.read()
        for rid, blob in resources(data):
            try:
                text = decode(blob).decode('utf-8')
                manifest = json.loads(text)
            except Exception:
                continue
            if (isinstance(manifest, dict) and manifest.get('name') == 'Vivaldi'
                    and 'manifest_version' in manifest and 'app' in manifest):
                sys.stdout.write(text)
                return 0
    sys.stderr.write('no Vivaldi app manifest in %s\n' % ' '.join(sys.argv[1:]))
    return 1


if __name__ == '__main__':
    sys.exit(main())
