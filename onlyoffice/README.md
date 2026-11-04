# editors/onlyoffice: the offline npm build

The JavaScript parts of ONLYOFFICE Desktop Editors (web-apps, sdkjs and
the start page in desktop-apps/common/loginpage) are built with grunt and
need a few hundred npm modules.  A port must build without network
access, so the port never lets npm talk to the registry: everything is
served from an npm cache that is a distfile.

## How it works

* `fsbruva/onlyoffice-DS-npm-cache` (the `npm_cache` tuple in `GH_TUPLE`)
  is the `~/.npm` cache captured while building ONLYOFFICE Document
  Server of the same version.  `post-extract` links it as
  `${WRKDIR}/.npm`.
* The start page needs a few modules that the Document Server does not.
  They are listed in `_NPM_DISTFILES`, fetched from the npm registry as
  ordinary distfiles (checked by `distinfo`) and added to that cache with
  `npm cache add` at the start of `do-build`.
* `files/npm` is a wrapper installed first in `PATH` for the whole build.
  It runs the real npm with `--offline --cache ${WRKDIR}/.npm`, so every
  `npm install` of the build_tools scripts and of the Makefile can only
  use the cache.
* `files/sdkjs-package-lock.json` is a lockfileVersion 3 lockfile for
  `sdkjs/build`, installed by `post-patch` in place of the
  `npm-shrinkwrap.json` (lockfileVersion 1) that sdkjs ships.  It pins the
  same versions.  See below for why it is needed.

## The error "cache mode is 'only-if-cached' but no cached response is available"

```
npm error code ENOTCACHED
npm error request to https://registry.npmjs.org/google-closure-compiler failed: cache mode is 'only-if-cached' but no cached response is available.
```

npm (run offline by the wrapper) asked for something the cache does not
hold.  The URL tells what:

* `https://registry.npmjs.org/<package>` (no `/-/`): the registry
  *metadata* of a package.  npm needs it when it has to resolve a version
  range itself, that is when there is no lockfile, the lockfile is ignored
  or does not match `package.json`.  The cache holds the metadata in the
  form the npm that built it requested; npm 12 (www/npm-node22 and
  www/npm-node24 since October 2026) always requests the full form, which
  the cache made with npm 10/11 only has for some packages.  Nothing can
  be added to the cache for this, so each `npm install` of the build must
  be driven by a lockfileVersion 3 lockfile: npm then takes the resolved
  tarball URLs and integrity hashes from it and asks for no metadata at
  all.  web-apps and the start page have such a `package-lock.json`,
  sdkjs only has a lockfileVersion 1 `npm-shrinkwrap.json`, which npm 12
  does not use (that is the google-closure-compiler error above), hence
  `files/sdkjs-package-lock.json`.
* `https://registry.npmjs.org/<package>/-/<package>-<version>.tgz`: a
  *tarball* is missing from the cache, typically after a port update that
  moved to new versions of web-apps, sdkjs or desktop-apps.  Add it to
  `_NPM_DISTFILES` and run `make makesum`.  This works for tarballs that
  a lockfile references with an `integrity` field (npm then finds them in
  the cache by hash); it does not help for a package that npm has to
  resolve from metadata.

Things to check first when the error shows up on a build that used to
work: that the real npm did not get a different cache or registry from
`${LOCALBASE}/etc/npmrc` or `npm_config_*` variables in the environment
(the wrapper passes `--cache` and `--offline` explicitly for this
reason), and that `${WRKDIR}/.npm/_cacache` exists and is writable (npm
rewrites index files even when only reading).

## Updating the port

1. Pick the `onlyoffice-DS-npm-cache` tag made for the new Document
   Server version (`_DS_TAGNAME`); the tags of that repository carry the
   version and the date.
2. Regenerate `files/sdkjs-package-lock.json` from the shrinkwrap of the
   new sdkjs.  npm 10 and 11 convert the lockfileVersion 1 file in place
   offline, with the metadata in the cache; npm 12 cannot.  After
   `make extract` (the shrinkwrap is still there, `post-patch` removes
   it), with network access for npx to fetch npm 11:

   ```sh
   cd work/DesktopEditors-*/sdkjs/build
   npx -y npm@11 install --package-lock-only --offline --cache ../../../.npm
   cp npm-shrinkwrap.json /path/to/ports/editors/onlyoffice/files/sdkjs-package-lock.json
   ```

   The file now says `"lockfileVersion": 3` and keeps the versions of
   the shrinkwrap.  Then `make clean` and build.
3. Build; for every tarball reported missing add it to `_NPM_DISTFILES`
   and run `make makesum`.

## Building online as a last resort

To find out what a build is missing it can be useful to let npm go
online once: remove `--offline` from `files/npm`, `make clean`, and build
with network access.  The build then fetches whatever it needs and the
cache in `${WRKDIR}/.npm` grows with it; the result is not reproducible
and such a change must not be committed.  Put `--offline` back and fix
the cause as described above.
