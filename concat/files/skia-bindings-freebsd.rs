//! FreeBSD, with Skia's dependencies taken from the system (ports) instead
//! of from its `third_party` tree.

use super::prelude::*;

pub struct FreeBsd;

impl PlatformDetails for FreeBsd {
    fn uses_freetype(&self) -> bool {
        true
    }

    fn gn_args(&self, _config: &BuildConfiguration, builder: &mut GnArgsBuilder) {
        // Skia's GN files do not know FreeBSD, and its Linux configuration
        // (fontconfig, FreeType, POSIX) is the one that fits.
        builder.target_os_and_default_cpu("linux");
        builder.cflags(flags());
    }

    fn bindgen_args(&self, _target: &Target, builder: &mut BindgenArgsBuilder) {
        builder.args(flags())
    }

    fn link_libraries(&self, features: &Features) -> Vec<String> {
        let mut libs: Vec<String> = ["c++", "freetype", "fontconfig"]
            .into_iter()
            .map(String::from)
            .collect();

        if skia::env::use_system_libraries() {
            libs.extend(["png16", "z", "expat", "jpeg"].map(String::from));
            if features[feature::TEXTLAYOUT] {
                libs.extend(["harfbuzz", "icuuc", "icui18n", "icuio"].map(String::from));
            }
            if features[feature::WEBP_ENCODE] || features[feature::WEBP_DECODE] {
                libs.push("webp".into());
            }
        }

        libs
    }
}

fn localbase() -> String {
    cargo::env_var("LOCALBASE").unwrap_or_else(|| "/usr/local".into())
}

fn flags() -> Vec<String> {
    let localbase = localbase();
    vec![
        format!("-I{localbase}/include"),
        format!("-I{localbase}/include/freetype2"),
    ]
}
