//! Native desktop UI built with egui/eframe.
//!
//! Used on platforms where neither the Sciter runtime nor Flutter is
//! available (e.g. FreeBSD). Every window runs in its own process, the same
//! way as the Sciter UI does:
//!
//! * no arguments       - main window (own ID/password, connect to a peer)
//! * `--connect <id>`   - remote desktop session
//! * `--cm`             - connection manager for incoming connections

use eframe::egui;
use hbb_common::log;

mod cm;
mod main_window;
mod remote;

pub fn start(args: &mut [String]) {
    if args.is_empty() {
        main_window::run();
    } else if args[0] == "--cm" {
        cm::run();
    } else if args[0] == "--connect" && args.len() > 1 {
        remote::run(args);
    } else {
        log::error!("Unsupported command in egui UI: {:?}", args);
    }
}

#[inline]
pub(crate) fn t(name: &str) -> String {
    crate::client::translate(name.to_owned())
}

pub(crate) fn run_window<A, F>(title: &str, size: [f32; 2], create: F)
where
    A: eframe::App + 'static,
    F: FnOnce(&egui::Context) -> A + 'static,
{
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_title(title)
            .with_app_id(crate::get_app_name().to_lowercase())
            .with_inner_size(size),
        ..Default::default()
    };
    let res = eframe::run_native(
        title,
        options,
        Box::new(move |cc| Ok(Box::new(create(&cc.egui_ctx)))),
    );
    if let Err(err) = res {
        log::error!("Failed to run egui window: {}", err);
    }
}
