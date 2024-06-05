--- libs/scrap/build.rs.orig	2024-06-05 08:28:09 UTC
+++ libs/scrap/build.rs
@@ -4,7 +4,7 @@ use std::{
     println,
 };
 
-#[cfg(all(target_os = "linux", feature = "linux-pkg-config"))]
+#[cfg(all(target_os = "freebsd", feature = "linux-pkg-config"))]
 fn link_pkg_config(name: &str) -> Vec<PathBuf> {
     // sometimes an override is needed
     let pc_name = match name {
@@ -15,134 +15,21 @@ fn link_pkg_config(name: &str) -> Vec<PathBuf> {
         .expect(format!(
             "unable to find '{pc_name}' development headers with pkg-config (feature linux-pkg-config is enabled).
             try installing '{pc_name}-dev' from your system package manager.").as_str());
+    
 
     lib.include_paths
 }
-#[cfg(not(all(target_os = "linux", feature = "linux-pkg-config")))]
-fn link_pkg_config(_name: &str) -> Vec<PathBuf> {
-    unimplemented!()
-}
 
-/// Link vcpkg package.
-fn link_vcpkg(mut path: PathBuf, name: &str) -> PathBuf {
-    let target_os = std::env::var("CARGO_CFG_TARGET_OS").unwrap();
-    let mut target_arch = std::env::var("CARGO_CFG_TARGET_ARCH").unwrap();
-    if target_arch == "x86_64" {
-        target_arch = "x64".to_owned();
-    } else if target_arch == "x86" {
-        target_arch = "x86".to_owned();
-    } else if target_arch == "loongarch64" {
-        target_arch = "loongarch64".to_owned();
-    } else if target_arch == "aarch64" {
-        target_arch = "arm64".to_owned();
-    } else {
-        target_arch = "arm".to_owned();
-    }
-    let mut target = if target_os == "macos" {
-        if target_arch == "x64" {
-            "x64-osx".to_owned()
-        } else if target_arch == "arm64" {
-            "arm64-osx".to_owned()
-        } else {
-            format!("{}-{}", target_arch, target_os)
-        }
-    } else if target_os == "windows" {
-        "x64-windows-static".to_owned()
-    } else {
-        format!("{}-{}", target_arch, target_os)
-    };
-    if target_arch == "x86" {
-        target = target.replace("x64", "x86");
-    }
-    println!("cargo:info={}", target);
-    path.push("installed");
-    path.push(target);
-    println!(
-        "{}",
-        format!(
-            "cargo:rustc-link-lib=static={}",
-            name.trim_start_matches("lib")
-        )
-    );
-    println!(
-        "{}",
-        format!(
-            "cargo:rustc-link-search={}",
-            path.join("lib").to_str().unwrap()
-        )
-    );
-    let include = path.join("include");
-    println!("{}", format!("cargo:include={}", include.to_str().unwrap()));
-    include
-}
-
-/// Link homebrew package(for Mac M1).
-fn link_homebrew_m1(name: &str) -> PathBuf {
-    let target_os = std::env::var("CARGO_CFG_TARGET_OS").unwrap();
-    let target_arch = std::env::var("CARGO_CFG_TARGET_ARCH").unwrap();
-    if target_os != "macos" || target_arch != "aarch64" {
-        panic!("Couldn't find VCPKG_ROOT, also can't fallback to homebrew because it's only for macos aarch64.");
-    }
-    let mut path = PathBuf::from("/opt/homebrew/Cellar");
-    path.push(name);
-    let entries = if let Ok(dir) = std::fs::read_dir(&path) {
-        dir
-    } else {
-        panic!("Could not find package in {}. Make sure your homebrew and package {} are all installed.", path.to_str().unwrap(),&name);
-    };
-    let mut directories = entries
-        .into_iter()
-        .filter(|x| x.is_ok())
-        .map(|x| x.unwrap().path())
-        .filter(|x| x.is_dir())
-        .collect::<Vec<_>>();
-    // Find the newest version.
-    directories.sort_unstable();
-    if directories.is_empty() {
-        panic!(
-            "There's no installed version of {} in /opt/homebrew/Cellar",
-            name
-        );
-    }
-    path.push(directories.pop().unwrap());
-    // Link the library.
-    println!(
-        "{}",
-        format!(
-            "cargo:rustc-link-lib=static={}",
-            name.trim_start_matches("lib")
-        )
-    );
-    // Add the library path.
-    println!(
-        "{}",
-        format!(
-            "cargo:rustc-link-search={}",
-            path.join("lib").to_str().unwrap()
-        )
-    );
-    // Add the include path.
-    let include = path.join("include");
-    println!("{}", format!("cargo:include={}", include.to_str().unwrap()));
-    include
-}
-
 /// Find package. By default, it will try to find vcpkg first, then homebrew(currently only for Mac M1).
 /// If building for linux and feature "linux-pkg-config" is enabled, will try to use pkg-config
 /// unless check fails (e.g. NO_PKG_CONFIG_libyuv=1)
+#[cfg(any(
+    all(target_os = "linux", feature = "linux-pkg-config"),
+    all(target_os = "freebsd")
+))]
 fn find_package(name: &str) -> Vec<PathBuf> {
-    let no_pkg_config_var_name = format!("NO_PKG_CONFIG_{name}");
-    println!("cargo:rerun-if-env-changed={no_pkg_config_var_name}");
-    if cfg!(all(target_os = "linux", feature = "linux-pkg-config"))
-        && std::env::var(no_pkg_config_var_name).as_deref() != Ok("1")
-    {
-        link_pkg_config(name)
-    } else if let Ok(vcpkg_root) = std::env::var("VCPKG_ROOT") {
-        vec![link_vcpkg(vcpkg_root.into(), name)]
-    } else {
-        // Try using homebrew
-        vec![link_homebrew_m1(name)]
-    }
+    link_pkg_config(name)
+ 
 }
 
 fn generate_bindings(
