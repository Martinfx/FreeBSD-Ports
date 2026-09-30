//! Shared widgets reproducing the Flutter desktop UI.

use super::{svg::IconCache, theme};
use eframe::egui::{
    self, pos2, vec2, Color32, CornerRadius, CursorIcon, FontFamily, FontId, Rect, ResizeDirection,
    Sense, Stroke, StrokeKind, Ui, ViewportCommand,
};

pub const TITLE_BAR_HEIGHT: f32 = 28.;

// Icon font code points (flutter/assets/*.ttf, IconFont in common.dart).
pub const ICON_MENU: char = '\u{e628}';
pub const ICON_MIN: char = '\u{e609}';
pub const ICON_MAX: char = '\u{e606}';
pub const ICON_RESTORE: char = '\u{e607}';
pub const ICON_CLOSE: char = '\u{e668}';
pub const ICON_SEARCH: char = '\u{e6a4}';
pub const ICON_ADDRESS_BOOK: char = '\u{e602}';
pub const ICON_MORE: char = '\u{e609}';

pub fn icon_font(family: &str, size: f32) -> FontId {
    FontId::new(size, FontFamily::Name(family.into()))
}

/// The peer color of the Flutter UI: `str2color(id + platform, 0x7F)`.
pub fn str2color(s: &str, alpha: u8) -> Color32 {
    let mut hash: u64 = 0;
    for c in s.encode_utf16() {
        hash = (c as u64).wrapping_add(hash.wrapping_mul(31));
    }
    let rgb = (hash & 0xFF_FFFF) & 0xFF_7FFF;
    Color32::from_rgba_unmultiplied((rgb >> 16) as u8, (rgb >> 8) as u8, rgb as u8, alpha)
}

/// "123456789" -> "123 456 789", like formatID() of the Flutter UI.
pub fn format_id(id: &str) -> String {
    let id2 = id.replace(' ', "");
    if id2.is_empty() || !id2.chars().all(|c| c.is_ascii_digit()) {
        return id.to_owned();
    }
    let n = id2.len();
    let a = if n % 3 != 0 { n % 3 } else { 3 };
    let mut out = id2[..a].to_owned();
    let mut i = a;
    while i < n {
        out.push(' ');
        out.push_str(&id2[i..i + 3]);
        i += 3;
    }
    out
}

pub fn open_url(url: &str) {
    let _ = std::process::Command::new("xdg-open").arg(url).spawn();
}

/// Material icons used by the Flutter UI, drawn with the painter.
#[derive(Clone, Copy, PartialEq)]
pub enum Glyph {
    MoreVert,
    Refresh,
    Edit,
    Help,
    Clock,
    Star,
    Explore,
    Grid,
    List,
    Sort,
    Home,
    Sad,
    ExpandLess,
    ExpandMore,
    Keyboard,
    Clipboard,
    Audio,
    File,
    Restart,
    Record,
    Block,
    LinkOff,
}

pub fn paint_glyph(ui: &Ui, icons: &mut IconCache, rect: Rect, glyph: Glyph, color: Color32) {
    let p = ui.painter();
    let c = rect.center();
    let s = rect.width().min(rect.height()) / 24.; // Material icons use a 24 grid
    let pt = |x: f32, y: f32| pos2(c.x + (x - 12.) * s, c.y + (y - 12.) * s);
    let stroke = Stroke::new(2. * s, color);
    match glyph {
        Glyph::MoreVert => {
            for y in [5., 12., 19.] {
                p.circle_filled(pt(12., y), 2. * s, color);
            }
        }
        Glyph::Refresh => {
            let tint = Some(color);
            icons.paint(ui, rect, "refresh", tint);
        }
        Glyph::Home => icons.paint(ui, rect, "home", Some(color)),
        Glyph::Edit => {
            let body = vec![pt(3., 17.25), pt(14.06, 6.19), pt(17.81, 9.94), pt(6.75, 21.), pt(3., 21.)];
            p.add(egui::Shape::convex_polygon(body, color, Stroke::NONE));
            let tip = vec![pt(15.13, 5.12), pt(17.0, 3.25), pt(20.75, 7.0), pt(18.88, 8.87)];
            p.add(egui::Shape::convex_polygon(tip, color, Stroke::NONE));
        }
        Glyph::Help => {
            p.circle_stroke(pt(12., 12.), 9. * s, stroke);
            p.text(
                pt(12., 12.5),
                egui::Align2::CENTER_CENTER,
                "?",
                FontId::proportional(13. * s),
                color,
            );
        }
        Glyph::Clock => {
            p.circle_filled(pt(12., 12.), 10. * s, color);
            let bg = ui.visuals().panel_fill;
            p.line_segment([pt(12., 12.), pt(12., 6.5)], Stroke::new(2. * s, bg));
            p.line_segment([pt(12., 12.), pt(16., 14.5)], Stroke::new(2. * s, bg));
        }
        Glyph::Star => {
            let mut pts = Vec::new();
            for i in 0..10 {
                let r = if i % 2 == 0 { 10. } else { 4.2 };
                let a = std::f32::consts::PI * (i as f32) / 5. - std::f32::consts::FRAC_PI_2;
                pts.push(pt(12. + r * a.cos(), 12.6 + r * a.sin()));
            }
            // Concave: draw as a fan of triangles around the center.
            let center = pt(12., 12.6);
            for i in 0..10 {
                p.add(egui::Shape::convex_polygon(
                    vec![center, pts[i], pts[(i + 1) % 10]],
                    color,
                    Stroke::NONE,
                ));
            }
        }
        Glyph::Explore => {
            p.circle_filled(pt(12., 12.), 10. * s, color);
            let bg = ui.visuals().panel_fill;
            p.add(egui::Shape::convex_polygon(
                vec![pt(16.5, 7.5), pt(13.4, 13.4), pt(7.5, 16.5), pt(10.6, 10.6)],
                bg,
                Stroke::NONE,
            ));
            p.circle_filled(pt(12., 12.), 1.1 * s, color);
        }
        Glyph::Grid => {
            for (x, y) in [(4., 4.), (13., 4.), (4., 13.), (13., 13.)] {
                p.rect_filled(
                    Rect::from_min_max(pt(x, y), pt(x + 7., y + 7.)),
                    CornerRadius::same((1.5 * s) as u8),
                    color,
                );
            }
        }
        Glyph::List => {
            for y in [5., 10.5, 16.] {
                p.rect_filled(
                    Rect::from_min_max(pt(3., y), pt(21., y + 3.)),
                    CornerRadius::same(1),
                    color,
                );
            }
        }
        Glyph::Sort => {
            for (y, w) in [(6., 18.), (11., 12.), (16., 6.)] {
                p.rect_filled(
                    Rect::from_min_max(pt(3., y), pt(3. + w, y + 2.)),
                    CornerRadius::same(1),
                    color,
                );
            }
        }
        Glyph::Sad => {
            p.circle_stroke(pt(12., 12.), 9.5 * s, Stroke::new(1.6 * s, color));
            p.circle_filled(pt(8.8, 9.5), 1.3 * s, color);
            p.circle_filled(pt(15.2, 9.5), 1.3 * s, color);
            let mouth: Vec<_> = (0..=12)
                .map(|i| {
                    let a = std::f32::consts::PI * (1.15 + 0.7 * i as f32 / 12.);
                    pt(12. + 4. * a.cos(), 18.5 + 3.2 * a.sin())
                })
                .collect();
            p.add(egui::Shape::line(mouth, Stroke::new(1.6 * s, color)));
        }
        Glyph::ExpandLess | Glyph::ExpandMore => {
            let (a, b) = if glyph == Glyph::ExpandLess { (15., 9.) } else { (9., 15.) };
            p.line_segment([pt(6., a), pt(12., b)], stroke);
            p.line_segment([pt(12., b), pt(18., a)], stroke);
        }
        Glyph::Keyboard => {
            p.rect_stroke(
                Rect::from_min_max(pt(2., 6.), pt(22., 18.)),
                CornerRadius::same((2. * s) as u8),
                Stroke::new(1.8 * s, color),
                StrokeKind::Inside,
            );
            for row in 0..2 {
                for col in 0..5 {
                    let (x, y) = (5. + col as f32 * 3.5, 9. + row as f32 * 3.);
                    p.rect_filled(
                        Rect::from_min_max(pt(x, y), pt(x + 1.8, y + 1.8)),
                        CornerRadius::ZERO,
                        color,
                    );
                }
            }
            p.rect_filled(Rect::from_min_max(pt(8., 15.), pt(16., 16.6)), CornerRadius::ZERO, color);
        }
        Glyph::Clipboard => {
            p.rect_stroke(
                Rect::from_min_max(pt(5., 4.), pt(19., 21.)),
                CornerRadius::same((2. * s) as u8),
                Stroke::new(1.8 * s, color),
                StrokeKind::Inside,
            );
            p.rect_filled(Rect::from_min_max(pt(9., 2.5), pt(15., 6.)), CornerRadius::same(2), color);
            for y in [10., 13.5, 17.] {
                p.line_segment([pt(8., y), pt(16., y)], Stroke::new(1.5 * s, color));
            }
        }
        Glyph::Audio => {
            p.add(egui::Shape::convex_polygon(
                vec![pt(3., 9.), pt(7., 9.), pt(12., 4.), pt(12., 20.), pt(7., 15.), pt(3., 15.)],
                color,
                Stroke::NONE,
            ));
            for r in [4., 7.5] {
                let arc: Vec<_> = (0..=8)
                    .map(|i| {
                        let a = -0.9 + 1.8 * i as f32 / 8.;
                        pt(12. + r * a.cos(), 12. + r * a.sin())
                    })
                    .collect();
                p.add(egui::Shape::line(arc, Stroke::new(1.8 * s, color)));
            }
        }
        Glyph::File => {
            p.add(egui::Shape::convex_polygon(
                vec![pt(6., 2.), pt(14., 2.), pt(20., 8.), pt(20., 22.), pt(6., 22.)],
                color,
                Stroke::NONE,
            ));
            let bg = ui.visuals().panel_fill;
            p.line_segment([pt(13., 18.), pt(13., 11.)], Stroke::new(1.8 * s, bg));
            p.line_segment([pt(10., 14.), pt(13., 11.)], Stroke::new(1.8 * s, bg));
            p.line_segment([pt(16., 14.), pt(13., 11.)], Stroke::new(1.8 * s, bg));
        }
        Glyph::Restart => {
            let arc: Vec<_> = (0..=16)
                .map(|i| {
                    let a = -2.4 + 4.3 * i as f32 / 16.;
                    pt(12. + 7. * a.cos(), 13. + 7. * a.sin())
                })
                .collect();
            p.add(egui::Shape::line(arc, stroke));
            p.add(egui::Shape::convex_polygon(
                vec![pt(4., 3.5), pt(10., 5.5), pt(5., 10.)],
                color,
                Stroke::NONE,
            ));
        }
        Glyph::Record => {
            p.rect_filled(Rect::from_min_max(pt(2., 6.), pt(16., 18.)), CornerRadius::same(2), color);
            p.add(egui::Shape::convex_polygon(
                vec![pt(16., 10.5), pt(22., 7.), pt(22., 17.), pt(16., 13.5)],
                color,
                Stroke::NONE,
            ));
        }
        Glyph::Block => {
            p.circle_stroke(pt(12., 12.), 9. * s, stroke);
            p.line_segment([pt(5.6, 5.6), pt(18.4, 18.4)], stroke);
        }
        Glyph::LinkOff => {
            p.rect_stroke(
                Rect::from_min_max(pt(2., 8.), pt(11., 16.)),
                CornerRadius::same((4. * s) as u8),
                stroke,
                StrokeKind::Inside,
            );
            p.rect_stroke(
                Rect::from_min_max(pt(13., 8.), pt(22., 16.)),
                CornerRadius::same((4. * s) as u8),
                stroke,
                StrokeKind::Inside,
            );
            p.line_segment([pt(3., 3.), pt(21., 21.)], stroke);
        }
    }
}

/// A clickable icon with the hover background of the Flutter toolbars.
pub fn glyph_button(
    ui: &mut Ui,
    icons: &mut IconCache,
    glyph: Glyph,
    icon_size: f32,
    color: Color32,
    tooltip: &str,
) -> egui::Response {
    let (rect, resp) = ui.allocate_exact_size(vec2(icon_size + 8., icon_size + 8.), Sense::click());
    if resp.hovered() {
        ui.painter()
            .rect_filled(rect, CornerRadius::same(6), theme::GRAY_BG);
    }
    paint_glyph(ui, icons, rect.shrink(4.), glyph, color);
    if tooltip.is_empty() {
        resp
    } else {
        resp.on_hover_text(tooltip)
    }
}

/// Filled button (ElevatedButton of MyTheme).
pub fn primary_button(ui: &mut Ui, text: &str, color: Color32, min_width: f32) -> egui::Response {
    ui.add(
        egui::Button::new(egui::RichText::new(text).color(Color32::WHITE).size(14.))
            .fill(color)
            .stroke(Stroke::NONE)
            .corner_radius(CornerRadius::same(8))
            .min_size(vec2(min_width, 28.)),
    )
}

/// Outlined button (OutlinedButton of MyTheme).
pub fn outlined_button(ui: &mut Ui, text: &str, min_width: f32) -> egui::Response {
    ui.add(
        egui::Button::new(egui::RichText::new(text).color(theme::TEXT).size(14.))
            .fill(theme::GRAY_BG)
            .stroke(Stroke::new(1., Color32::from_rgb(0x9E, 0x9E, 0x9E)))
            .corner_radius(CornerRadius::same(8))
            .min_size(vec2(min_width, 28.)),
    )
}

pub struct Tab {
    pub label: String,
    pub glyph: Option<Glyph>,
    pub closable: bool,
}

pub enum TitleBarEvent {
    SelectTab(usize),
    CloseTab,
    Settings,
}

/// The 28px Flutter title bar: app icon, tabs, drag area and window buttons.
pub fn title_bar(
    ctx: &egui::Context,
    icons: &mut IconCache,
    tabs: &[Tab],
    selected: usize,
    show_settings: bool,
    show_maximize: bool,
) -> Option<TitleBarEvent> {
    let mut event = None;
    egui::TopBottomPanel::top("title_bar")
        .exact_height(TITLE_BAR_HEIGHT - 1.)
        .frame(egui::Frame::NONE.fill(theme::GRAY_BG))
        .show_separator_line(true)
        .show(ctx, |ui| {
            ui.spacing_mut().item_spacing.x = 0.;
            ui.horizontal_centered(|ui| {
                ui.add_space(5.);
                let (r, _) = ui.allocate_exact_size(vec2(16., 16.), Sense::hover());
                icons.paint(ui, r, "icon", None);
                ui.add_space(10.);
                for (i, tab) in tabs.iter().enumerate() {
                    let sel = i == selected;
                    let font = FontId::proportional(14.);
                    let galley = ui.painter().layout_no_wrap(
                        tab.label.clone(),
                        font,
                        if sel { Color32::BLACK } else { theme::TAB_UNSELECTED },
                    );
                    let icon_w = if tab.glyph.is_some() { 23. } else { 0. };
                    let close_w = if tab.closable { 28. } else { 0. };
                    let w = 10. + icon_w + galley.size().x + close_w + 5.;
                    let (rect, resp) =
                        ui.allocate_exact_size(vec2(w, TITLE_BAR_HEIGHT - 1.), Sense::click());
                    if sel {
                        ui.painter().rect_filled(rect, CornerRadius::ZERO, theme::WHITE_54);
                    }
                    let mut x = rect.left() + 10.;
                    if let Some(g) = tab.glyph {
                        let ir = Rect::from_center_size(pos2(x + 9., rect.center().y), vec2(18., 18.));
                        paint_glyph(
                            ui,
                            icons,
                            ir,
                            g,
                            if sel { theme::ACCENT } else { Color32::from_rgb(0xA2, 0xCB, 0xF1) },
                        );
                        x += icon_w;
                    }
                    ui.painter().galley(
                        pos2(x, rect.center().y - galley.size().y / 2.),
                        galley.clone(),
                        Color32::BLACK,
                    );
                    x += galley.size().x;
                    if resp.clicked() {
                        event = Some(TitleBarEvent::SelectTab(i));
                    }
                    if tab.closable {
                        let cr = Rect::from_center_size(pos2(x + 19., rect.center().y), vec2(18., 18.));
                        let cresp = ui.interact(cr, ui.id().with(("tab_close", i)), Sense::click());
                        if resp.hovered() || cresp.hovered() || sel {
                            ui.painter().text(
                                cr.center(),
                                egui::Align2::CENTER_CENTER,
                                ICON_CLOSE,
                                icon_font("Tabbar", 10.),
                                theme::WINDOW_ICON,
                            );
                        }
                        if cresp.clicked() {
                            event = Some(TitleBarEvent::CloseTab);
                        }
                    }
                    if i + 1 < tabs.len() {
                        let (d, _) = ui.allocate_exact_size(vec2(1., TITLE_BAR_HEIGHT - 1.), Sense::hover());
                        ui.painter().line_segment(
                            [pos2(d.center().x, d.top() + 10.), pos2(d.center().x, d.bottom())],
                            Stroke::new(1., Color32::from_rgb(0xEE, 0xEE, 0xEE)),
                        );
                    }
                }
                // Buttons are laid out right to left.
                let buttons = 2. + show_maximize as i32 as f32 + show_settings as i32 as f32;
                let drag_w = (ui.available_width() - buttons * 27. - 10.).max(0.);
                let (drag, dresp) =
                    ui.allocate_exact_size(vec2(drag_w, TITLE_BAR_HEIGHT - 1.), Sense::click_and_drag());
                let _ = drag;
                if dresp.drag_started() {
                    ctx.send_viewport_cmd(ViewportCommand::StartDrag);
                }
                let maximized = ctx.input(|i| i.viewport().maximized.unwrap_or(false));
                if dresp.double_clicked() && show_maximize {
                    ctx.send_viewport_cmd(ViewportCommand::Maximized(!maximized));
                }
                ui.add_space(10.);
                if show_settings && window_button(ui, ICON_MENU, false).on_hover_text(super::t("Settings")).clicked() {
                    event = Some(TitleBarEvent::Settings);
                }
                if window_button(ui, ICON_MIN, false).clicked() {
                    ctx.send_viewport_cmd(ViewportCommand::Minimized(true));
                }
                if show_maximize
                    && window_button(ui, if maximized { ICON_RESTORE } else { ICON_MAX }, false)
                        .clicked()
                {
                    ctx.send_viewport_cmd(ViewportCommand::Maximized(!maximized));
                }
                if window_button(ui, ICON_CLOSE, true).clicked() {
                    ctx.send_viewport_cmd(ViewportCommand::Close);
                }
            });
        });
    event
}

fn window_button(ui: &mut Ui, glyph: char, close: bool) -> egui::Response {
    let (rect, resp) = ui.allocate_exact_size(vec2(27., 27.), Sense::click());
    let mut color = theme::WINDOW_ICON;
    if resp.hovered() {
        if close {
            ui.painter().rect_filled(rect, CornerRadius::ZERO, theme::CLOSE_HOVER);
            color = Color32::WHITE;
        } else {
            ui.painter().rect_filled(rect, CornerRadius::ZERO, theme::WHITE_54);
        }
    }
    ui.painter().text(
        rect.center(),
        egui::Align2::CENTER_CENTER,
        glyph,
        icon_font("Tabbar", 12.),
        color,
    );
    resp
}

/// Resize handles along the edges of a frameless window.
pub fn resize_handles(ctx: &egui::Context) {
    let maximized = ctx.input(|i| i.viewport().maximized.unwrap_or(false));
    if maximized {
        return;
    }
    let screen = ctx.screen_rect();
    let Some(pos) = ctx.input(|i| i.pointer.hover_pos()) else {
        return;
    };
    const B: f32 = 5.;
    let (l, r) = (pos.x - screen.left() < B, screen.right() - pos.x < B);
    let (t, b) = (pos.y - screen.top() < B, screen.bottom() - pos.y < B);
    let dir = match (l, r, t, b) {
        (true, _, true, _) => ResizeDirection::NorthWest,
        (_, true, true, _) => ResizeDirection::NorthEast,
        (true, _, _, true) => ResizeDirection::SouthWest,
        (_, true, _, true) => ResizeDirection::SouthEast,
        (true, ..) => ResizeDirection::West,
        (_, true, ..) => ResizeDirection::East,
        (_, _, true, _) => ResizeDirection::North,
        (_, _, _, true) => ResizeDirection::South,
        _ => return,
    };
    ctx.set_cursor_icon(match dir {
        ResizeDirection::North | ResizeDirection::South => CursorIcon::ResizeVertical,
        ResizeDirection::East | ResizeDirection::West => CursorIcon::ResizeHorizontal,
        ResizeDirection::NorthWest | ResizeDirection::SouthEast => CursorIcon::ResizeNwSe,
        ResizeDirection::NorthEast | ResizeDirection::SouthWest => CursorIcon::ResizeNeSw,
    });
    if ctx.input(|i| i.pointer.primary_pressed()) {
        ctx.send_viewport_cmd(ViewportCommand::BeginResize(dir));
    }
}

/// Flutter style dialog frame (radius 18, padding 24).
pub fn dialog<R>(
    ctx: &egui::Context,
    title: &str,
    add_contents: impl FnOnce(&mut Ui) -> R,
) -> Option<R> {
    // Dim the page behind the dialog.
    let screen = ctx.screen_rect();
    egui::Area::new(egui::Id::new("dialog_barrier"))
        .order(egui::Order::Middle)
        .fixed_pos(screen.min)
        .show(ctx, |ui| {
            ui.painter()
                .rect_filled(screen, CornerRadius::ZERO, Color32::from_black_alpha(0x55));
            ui.allocate_rect(screen, Sense::click());
        });
    egui::Window::new(title)
        .title_bar(false)
        .collapsible(false)
        .resizable(false)
        .anchor(egui::Align2::CENTER_CENTER, [0., 0.])
        .order(egui::Order::Foreground)
        .frame(
            egui::Frame::window(&ctx.style())
                .fill(Color32::WHITE)
                .corner_radius(CornerRadius::same(18))
                .inner_margin(egui::Margin::same(24)),
        )
        .show(ctx, |ui| {
            ui.set_min_width(340.);
            ui.label(egui::RichText::new(title).size(19.));
            ui.add_space(12.);
            add_contents(ui)
        })
        .and_then(|r| r.inner)
}

/// Text input in the style of the Flutter InputDecoration (radius 8).
pub fn text_input(
    ui: &mut Ui,
    text: &mut String,
    hint: &str,
    password: bool,
    width: f32,
) -> egui::Response {
    egui::Frame::NONE
        .show(ui, |ui| {
            ui.add(
                egui::TextEdit::singleline(text)
                    .hint_text(egui::RichText::new(hint).color(theme::HINT))
                    .password(password)
                    .margin(egui::Margin::symmetric(10, 8))
                    .desired_width(width),
            )
        })
        .inner
}

/// A row of dialog buttons, laid out right to left, 28px high.
pub fn button_row<R>(ui: &mut Ui, add: impl FnOnce(&mut Ui) -> R) -> R {
    let size = vec2(ui.available_width(), 28.);
    ui.allocate_ui_with_layout(size, egui::Layout::right_to_left(egui::Align::Center), add)
        .inner
}

/// Material style checkbox (radius 3, accent when checked).
pub fn checkbox(ui: &mut Ui, checked: &mut bool, text: &str) -> egui::Response {
    let galley = ui
        .painter()
        .layout_no_wrap(text.to_owned(), FontId::proportional(14.), theme::TEXT);
    let size = vec2(18. + 8. + galley.size().x, galley.size().y.max(22.));
    let (rect, mut resp) = ui.allocate_exact_size(size, Sense::click());
    if resp.clicked() {
        *checked = !*checked;
        resp.mark_changed();
    }
    let b = Rect::from_min_size(pos2(rect.left(), rect.center().y - 9.), vec2(18., 18.));
    if *checked {
        ui.painter().rect_filled(b, CornerRadius::same(3), theme::ACCENT);
        ui.painter().add(egui::Shape::line(
            vec![
                pos2(b.left() + 4., b.center().y),
                pos2(b.left() + 7.5, b.bottom() - 5.),
                pos2(b.right() - 4., b.top() + 5.),
            ],
            Stroke::new(2., Color32::WHITE),
        ));
    } else {
        ui.painter().rect_stroke(
            b,
            CornerRadius::same(3),
            Stroke::new(2., Color32::from_rgb(0x75, 0x75, 0x75)),
            StrokeKind::Inside,
        );
    }
    ui.painter().galley(
        pos2(b.right() + 8., rect.center().y - galley.size().y / 2.),
        galley,
        theme::TEXT,
    );
    resp
}

/// Painted button with centered text and an optional leading glyph.
#[allow(clippy::too_many_arguments)]
pub fn flat_button(
    ui: &mut Ui,
    icons: &mut IconCache,
    text: &str,
    glyph: Option<Glyph>,
    fill: Color32,
    text_color: Color32,
    width: f32,
    radius: u8,
    outline: bool,
) -> egui::Response {
    let (rect, resp) = ui.allocate_exact_size(vec2(width, 28.), Sense::click());
    let fill = if resp.hovered() && fill != Color32::TRANSPARENT {
        fill.gamma_multiply(0.9)
    } else {
        fill
    };
    ui.painter().rect_filled(rect, CornerRadius::same(radius), fill);
    if outline {
        ui.painter().rect_stroke(
            rect,
            CornerRadius::same(radius),
            Stroke::new(1., Color32::from_rgb(0x9E, 0x9E, 0x9E)),
            StrokeKind::Inside,
        );
    }
    let galley = ui
        .painter()
        .layout_no_wrap(text.to_owned(), FontId::proportional(14.), text_color);
    let icon_w = if glyph.is_some() { 14. + 5. } else { 0. };
    let x = rect.center().x - (icon_w + galley.size().x) / 2.;
    if let Some(g) = glyph {
        let r = Rect::from_center_size(pos2(x + 7., rect.center().y), vec2(14., 14.));
        paint_glyph(ui, icons, r, g, text_color);
    }
    ui.painter().galley(
        pos2(x + icon_w, rect.center().y - galley.size().y / 2.),
        galley,
        text_color,
    );
    resp.on_hover_cursor(CursorIcon::PointingHand)
}
