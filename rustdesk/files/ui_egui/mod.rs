//! Native desktop UI built with egui/eframe.
//!
//! Used on platforms where neither the Sciter runtime nor Flutter is
//! available (e.g. FreeBSD). It mirrors the look of the official Flutter
//! desktop UI. Every window runs in its own process, the same way as the
//! Sciter UI does:
//!
//! * no arguments       - main window (own ID/password, connect to a peer)
//! * `--connect <id>`   - remote desktop session
//! * `--cm`             - connection manager for incoming connections

use eframe::egui;
use hbb_common::log;
use std::sync::Arc;

mod cm;
mod main_window;
mod remote;
mod svg;
mod widgets;

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

/// Colors of the Flutter desktop UI (MyTheme, light theme).
pub(crate) mod theme {
    use eframe::egui::Color32;

    pub const GRAY_BG: Color32 = Color32::from_rgb(0xEF, 0xEF, 0xF2);
    pub const ACCENT: Color32 = Color32::from_rgb(0x00, 0x71, 0xFF);
    pub const PRIMARY: Color32 = Color32::from_rgb(0x21, 0x96, 0xF3);
    pub const BUTTON: Color32 = Color32::from_rgb(0x2C, 0x8C, 0xFF);
    pub const TEXT: Color32 = Color32::from_rgba_premultiplied(0, 0, 0, 0xDD);
    pub const TEXT_50: Color32 = Color32::from_rgba_premultiplied(0, 0, 0, 0x6F);
    pub const HINT: Color32 = Color32::from_rgb(0xAA, 0xAA, 0xAA);
    pub const DIVIDER: Color32 = Color32::from_rgba_premultiplied(0, 0, 0, 0x1F);
    pub const INPUT_BORDER: Color32 = Color32::from_rgba_premultiplied(0, 0, 0, 0x61);
    pub const HOVER: Color32 = Color32::from_rgb(0xE0, 0xE0, 0xE0);
    pub const TAB_UNSELECTED: Color32 = Color32::from_rgb(0x70, 0x70, 0x70);
    pub const WINDOW_ICON: Color32 = Color32::from_rgb(0x60, 0x60, 0x60);
    pub const WHITE_54: Color32 = Color32::from_rgba_premultiplied(0x8A, 0x8A, 0x8A, 0x8A);
    pub const CLOSE_HOVER: Color32 = Color32::from_rgb(0xC4, 0x2B, 0x1C);
    pub const READY: Color32 = Color32::from_rgb(0x32, 0xBE, 0xA6);
    pub const WARN: Color32 = Color32::from_rgb(0xF5, 0x85, 0x3B);
    pub const NOT_READY: Color32 = Color32::from_rgb(0xE0, 0x4F, 0x5F);
    pub const ONLINE: Color32 = Color32::from_rgb(0x4C, 0xAF, 0x50);
    pub const RED: Color32 = Color32::from_rgb(0xFF, 0x52, 0x52);
    pub const RED_HOVER: Color32 = Color32::from_rgb(0xF4, 0x43, 0x36);
    pub const BLUE_HOVER: Color32 = ACCENT;
    pub const INACTIVE: Color32 = Color32::from_rgb(0x42, 0x42, 0x42);
    pub const GREY_700: Color32 = Color32::from_rgb(0x61, 0x61, 0x61);
    pub const BORDER3: Color32 = Color32::from_rgba_premultiplied(0, 0, 0, 0x42);
}

fn setup_style(ctx: &egui::Context) {
    let mut fonts = egui::FontDefinitions::default();
    for (name, data) in [
        ("Tabbar", &include_bytes!("../../flutter/assets/tabbar.ttf")[..]),
        ("PeerSearchbar", &include_bytes!("../../flutter/assets/peer_searchbar.ttf")[..]),
        ("AddressBook", &include_bytes!("../../flutter/assets/address_book.ttf")[..]),
        ("DeviceGroup", &include_bytes!("../../flutter/assets/device_group.ttf")[..]),
        ("More", &include_bytes!("../../flutter/assets/more.ttf")[..]),
    ] {
        fonts
            .font_data
            .insert(name.to_owned(), Arc::new(egui::FontData::from_static(data)));
        fonts
            .families
            .insert(egui::FontFamily::Name(name.into()), vec![name.to_owned()]);
    }
    ctx.set_fonts(fonts);

    ctx.set_visuals(egui::Visuals::light());
    ctx.style_mut(|style| {
        use egui::{FontFamily::Proportional, FontId, TextStyle};
        style.text_styles = [
            (TextStyle::Heading, FontId::new(19., Proportional)),
            (TextStyle::Body, FontId::new(14., Proportional)),
            (TextStyle::Button, FontId::new(14., Proportional)),
            (TextStyle::Small, FontId::new(12., Proportional)),
            (TextStyle::Monospace, FontId::new(14., egui::FontFamily::Monospace)),
        ]
        .into();
        let v = &mut style.visuals;
        v.panel_fill = egui::Color32::WHITE;
        v.window_fill = egui::Color32::WHITE;
        v.extreme_bg_color = egui::Color32::WHITE;
        v.override_text_color = Some(theme::TEXT);
        v.hyperlink_color = theme::ACCENT;
        v.selection.bg_fill = theme::PRIMARY.gamma_multiply(0.35);
        v.selection.stroke = egui::Stroke::new(2., theme::PRIMARY);
        v.window_corner_radius = egui::CornerRadius::same(18);
        v.window_stroke = egui::Stroke::new(1., theme::GRAY_BG);
        v.menu_corner_radius = egui::CornerRadius::same(8);
        v.widgets.noninteractive.bg_stroke = egui::Stroke::new(1., theme::DIVIDER);
        for w in [
            &mut v.widgets.inactive,
            &mut v.widgets.hovered,
            &mut v.widgets.active,
            &mut v.widgets.open,
        ] {
            w.corner_radius = egui::CornerRadius::same(8);
        }
        v.widgets.inactive.bg_stroke = egui::Stroke::new(1., theme::INPUT_BORDER);
        v.widgets.inactive.weak_bg_fill = theme::GRAY_BG;
        v.widgets.inactive.bg_fill = theme::GRAY_BG;
        v.widgets.hovered.weak_bg_fill = theme::HOVER;
        v.widgets.hovered.bg_stroke = egui::Stroke::new(1., theme::INPUT_BORDER);
        v.widgets.active.bg_stroke = egui::Stroke::new(2., theme::PRIMARY);
        style.spacing.item_spacing = egui::vec2(8., 6.);
        style.spacing.button_padding = egui::vec2(12., 4.);
        style.spacing.scroll.bar_width = 6.;
        style.spacing.scroll.floating = true;
    });
}

pub(crate) fn run_window<A, F>(title: &str, size: [f32; 2], min_size: [f32; 2], create: F)
where
    A: eframe::App + 'static,
    F: FnOnce(&egui::Context) -> A + 'static,
{
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_title(title)
            .with_app_id(crate::get_app_name().to_lowercase())
            .with_inner_size(size)
            .with_min_inner_size(min_size)
            // Frameless like the Flutter UI, which draws its own title bar.
            .with_decorations(false),
        ..Default::default()
    };
    let res = eframe::run_native(
        title,
        options,
        Box::new(move |cc| {
            setup_style(&cc.egui_ctx);
            Ok(Box::new(create(&cc.egui_ctx)))
        }),
    );
    if let Err(err) = res {
        log::error!("Failed to run egui window: {}", err);
    }
}
