--- libs/scrap/build.rs.orig	2025-02-22 05:17:11 UTC
+++ libs/scrap/build.rs
@@ -4,7 +4,7 @@ use std::{
     println,
 };
 
-#[cfg(all(target_os = "linux", feature = "linux-pkg-config"))]
+#[cfg(all(target_os = "freebsd", feature = "linux-pkg-config"))]
 fn link_pkg_config(name: &str) -> Vec<PathBuf> {
     // sometimes an override is needed
     let pc_name = match name {
@@ -18,68 +18,7 @@ fn link_pkg_config(name: &str) -> Vec<PathBuf> {
 
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
-    if let Ok(vcpkg_root) = std::env::var("VCPKG_INSTALLED_ROOT") {
-        path = vcpkg_root.into();
-    } else {
-        path.push("installed");
-    }
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
 /// Link homebrew package(for Mac M1).
 fn link_homebrew_m1(name: &str) -> PathBuf {
     let target_os = std::env::var("CARGO_CFG_TARGET_OS").unwrap();
@@ -137,16 +76,8 @@ fn find_package(name: &str) -> Vec<PathBuf> {
 fn find_package(name: &str) -> Vec<PathBuf> {
     let no_pkg_config_var_name = format!("NO_PKG_CONFIG_{name}");
     println!("cargo:rerun-if-env-changed={no_pkg_config_var_name}");
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
+
+	link_pkg_config(name)
 }
 
 fn generate_bindings(
