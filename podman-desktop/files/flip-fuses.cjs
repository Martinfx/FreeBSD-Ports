// Flip the same electron fuses as the upstream builds do in
// .electron-builder.config.cjs (addElectronFuses).
//
// usage: node flip-fuses.cjs <electron binary>  (run from the source tree)

const { flipFuses, FuseVersion, FuseV1Options } = require(require.resolve('@electron/fuses', { paths: [process.cwd()] }));

flipFuses(process.argv[2], {
  version: FuseVersion.V1,
  [FuseV1Options.RunAsNode]: false,
  [FuseV1Options.EnableNodeOptionsEnvironmentVariable]: false,
  [FuseV1Options.EnableNodeCliInspectArguments]: false,
}).catch(error => {
  console.error(error);
  process.exit(1);
});
