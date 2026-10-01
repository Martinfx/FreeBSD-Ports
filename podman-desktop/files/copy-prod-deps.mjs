// Copy the runtime dependencies of the root package.json out of the pnpm
// node_modules layout (symlinks into node_modules/.pnpm) into a standalone
// node_modules directory, the way electron-builder does it when packaging.
//
// usage: node copy-prod-deps.mjs <source dir> <destination node_modules dir>

import fs from 'node:fs';
import path from 'node:path';

const [srcDir, destArg] = process.argv.slice(2);
const destRoot = destArg && path.resolve(destArg);
if (!srcDir || !destArg) {
	console.error('usage: copy-prod-deps.mjs <source dir> <destination node_modules dir>');
	process.exit(1);
}

const readJson = file => JSON.parse(fs.readFileSync(file, 'utf8'));

// Node.js module resolution: walk up from dir looking for node_modules/name
function resolvePackage(fromDir, name) {
	let dir = fromDir;
	for (;;) {
		const candidate = path.join(dir, 'node_modules', name, 'package.json');
		if (fs.existsSync(candidate)) return path.dirname(fs.realpathSync(candidate));
		const parent = path.dirname(dir);
		if (parent === dir) return undefined;
		dir = parent;
	}
}

// Same walk inside the destination tree, stopping at its root.
function findInstalled(fromDir, name) {
	let dir = fromDir;
	for (;;) {
		const candidate = path.join(dir, name, 'package.json');
		if (fs.existsSync(candidate)) return readJson(candidate).version;
		if (dir === destRoot) return undefined;
		// go to the node_modules directory holding the package owning dir
		dir = path.dirname(dir);
		while (path.basename(dir) !== 'node_modules') {
			if (dir === destRoot || dir === path.dirname(dir)) return undefined;
			dir = path.dirname(dir);
		}
	}
}

function copyPackage(realDir, target) {
	fs.cpSync(realDir, target, {
		recursive: true,
		dereference: true,
		// nested node_modules of a package are pnpm symlinks, deps are handled below
		filter: src => !path.relative(realDir, src).split(path.sep).includes('node_modules'),
	});
}

// install the dependencies of the package whose sources are in realDir and
// which is installed in installDir (destRoot for the root package)
function installDeps(realDir, installDir, pkg, chain) {
	const deps = {
		...pkg.dependencies,
		...pkg.optionalDependencies,
		...pkg.peerDependencies,
	};
	for (const name of Object.keys(deps).sort()) {
		const depReal = resolvePackage(realDir, name);
		if (!depReal) {
			if (pkg.dependencies?.[name]) throw new Error(`cannot resolve ${name} from ${realDir}`);
			continue; // missing optional or peer dependency
		}
		const depPkg = readJson(path.join(depReal, 'package.json'));
		const lookupDir = installDir === destRoot ? destRoot : path.join(installDir, 'node_modules');
		const installed = findInstalled(lookupDir, name);
		if (installed === depPkg.version) continue;
		let target;
		if (installed === undefined && !fs.existsSync(path.join(destRoot, name))) {
			target = path.join(destRoot, name);
		} else {
			target = path.join(installDir === destRoot ? destRoot : path.join(installDir, 'node_modules'), name);
			if (installed !== undefined && fs.existsSync(target)) continue;
		}
		const key = `${name}@${depPkg.version}`;
		if (chain.includes(key)) continue;
		copyPackage(depReal, target);
		installDeps(depReal, target, depPkg, [...chain, key]);
	}
}

const rootPkg = readJson(path.join(srcDir, 'package.json'));
fs.mkdirSync(destRoot, { recursive: true });
installDeps(path.resolve(srcDir), destRoot, { dependencies: rootPkg.dependencies }, []);
