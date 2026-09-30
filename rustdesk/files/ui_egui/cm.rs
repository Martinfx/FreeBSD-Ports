//! Connection manager window, laid out like the Flutter server_page.

use super::{
    run_window,
    svg::IconCache,
    t, theme,
    widgets::{self, paint_glyph, str2color, Glyph, Tab},
};
use crate::ui_cm_interface::{self, start_ipc, Client, ConnectionManager, InvokeUiCM};
use eframe::egui::{
    self, pos2, vec2, Align2, Color32, CornerRadius, FontId, Margin, Rect, Sense,
};
use hbb_common::log;
use std::{
    sync::{
        atomic::{AtomicBool, Ordering},
        Arc, Mutex,
    },
    time::{Duration, Instant},
};

#[derive(Clone)]
struct CmClient {
    client: Client,
    since: Instant,
}

#[derive(Clone, Default)]
struct EguiCmHandler {
    clients: Arc<Mutex<Vec<CmClient>>>,
    had_clients: Arc<AtomicBool>,
    ctx: Arc<Mutex<Option<egui::Context>>>,
}

impl EguiCmHandler {
    fn repaint(&self) {
        if let Some(ctx) = self.ctx.lock().unwrap().as_ref() {
            ctx.request_repaint();
        }
    }
}

impl InvokeUiCM for EguiCmHandler {
    fn add_connection(&self, client: &Client) {
        {
            let mut clients = self.clients.lock().unwrap();
            if let Some(c) = clients.iter_mut().find(|c| c.client.id == client.id) {
                if !c.client.authorized && client.authorized {
                    c.since = Instant::now();
                }
                c.client = client.clone();
            } else {
                clients.push(CmClient {
                    client: client.clone(),
                    since: Instant::now(),
                });
            }
        }
        self.had_clients.store(true, Ordering::SeqCst);
        self.repaint();
    }

    fn remove_connection(&self, id: i32, close: bool) {
        {
            let mut clients = self.clients.lock().unwrap();
            if close {
                clients.retain(|c| c.client.id != id);
            } else if let Some(c) = clients.iter_mut().find(|c| c.client.id == id) {
                c.client.disconnected = true;
            }
        }
        self.repaint();
    }

    fn new_message(&self, id: i32, text: String) {
        log::info!("cm: message from connection {}: {}", id, text);
    }

    fn change_theme(&self, _dark: String) {}

    fn change_language(&self) {}

    fn show_elevation(&self, _show: bool) {}

    fn update_voice_call_state(&self, _client: &Client) {}

    fn file_transfer_log(&self, action: &str, log: &str) {
        log::info!("cm file transfer {}: {}", action, log);
    }
}

struct CmWindow {
    handler: EguiCmHandler,
    icons: IconCache,
    selected: usize,
    gradient: Option<egui::TextureHandle>,
}

pub fn run() {
    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
    std::thread::spawn(crate::ipc::start_pa);
    let handler = EguiCmHandler::default();
    let cm = ConnectionManager {
        ui_handler: handler.clone(),
    };
    std::thread::spawn(move || start_ipc(cm));
    let title = format!("{} - {}", crate::get_app_name(), t("Connection Manager"));
    run_window(&title, [300., 490.], [300., 400.], move |ctx| {
        *handler.ctx.lock().unwrap() = Some(ctx.clone());
        CmWindow {
            handler,
            icons: IconCache::default(),
            selected: 0,
            gradient: None,
        }
    });
}

const PERMISSIONS: [(&str, Glyph, &str); 7] = [
    ("keyboard", Glyph::Keyboard, "Enable keyboard/mouse"),
    ("clipboard", Glyph::Clipboard, "Enable clipboard"),
    ("audio", Glyph::Audio, "Enable audio"),
    ("file", Glyph::File, "Enable file copy and paste"),
    ("restart", Glyph::Restart, "Enable remote restart"),
    ("recording", Glyph::Record, "Enable recording session"),
    ("block_input", Glyph::Block, "Enable blocking user input"),
];

fn permission(c: &Client, name: &str) -> bool {
    match name {
        "keyboard" => c.keyboard,
        "clipboard" => c.clipboard,
        "audio" => c.audio,
        "file" => c.file,
        "restart" => c.restart,
        "recording" => c.recording,
        "block_input" => c.block_input,
        _ => false,
    }
}

fn set_permission(c: &mut Client, name: &str, v: bool) {
    match name {
        "keyboard" => c.keyboard = v,
        "clipboard" => c.clipboard = v,
        "audio" => c.audio = v,
        "file" => c.file = v,
        "restart" => c.restart = v,
        "recording" => c.recording = v,
        "block_input" => c.block_input = v,
        _ => {}
    }
}

impl CmWindow {
    // Gradient FF00BFE1 (top right) -> FF0071FF (bottom left) as a 2x2 texture.
    fn gradient(&mut self, ctx: &egui::Context) -> egui::TextureId {
        self.gradient
            .get_or_insert_with(|| {
                let a = Color32::from_rgb(0x00, 0xBF, 0xE1);
                let b = Color32::from_rgb(0x00, 0x71, 0xFF);
                let mid = Color32::from_rgb(0x00, 0x98, 0xF0);
                let image = egui::ColorImage {
                    size: [2, 2],
                    pixels: vec![mid, a, b, mid],
                };
                ctx.load_texture("cm-gradient", image, egui::TextureOptions::LINEAR)
            })
            .id()
    }

    fn header(&mut self, ui: &mut egui::Ui, c: &CmClient) {
        let tex = self.gradient(ui.ctx());
        let (outer, _) = ui.allocate_exact_size(vec2(ui.available_width(), 110.), Sense::hover());
        let rect = outer.shrink2(vec2(5., 10.));
        ui.painter().add(
            egui::epaint::RectShape::filled(rect, CornerRadius::same(10), Color32::WHITE).with_texture(
                tex,
                Rect::from_min_max(pos2(0.25, 0.25), pos2(0.75, 0.75)),
            ),
        );
        let client = &c.client;
        let avatar = Rect::from_min_size(pos2(rect.left() + 10., rect.center().y - 35.), vec2(70., 70.));
        ui.painter()
            .rect_filled(avatar, CornerRadius::same(15), str2color(&client.name, 0xFF));
        let letter = client.name.chars().next().map(|c| c.to_uppercase().to_string()).unwrap_or_default();
        ui.painter().text(
            avatar.center(),
            Align2::CENTER_CENTER,
            letter,
            FontId::proportional(48.),
            Color32::WHITE,
        );
        let x = avatar.right() + 10.;
        let mut y = avatar.top() + 2.;
        let text = |ui: &egui::Ui, y: f32, s: String, size: f32, color: Color32| {
            ui.painter().text(pos2(x, y), Align2::LEFT_TOP, s, FontId::proportional(size), color);
        };
        text(ui, y, client.name.clone(), 20., Color32::WHITE);
        y += 25.;
        text(ui, y, format!("({})", widgets::format_id(&client.peer_id)), 14., Color32::WHITE);
        y += 18.;
        let kind = if client.is_file_transfer {
            Some("Transfer file")
        } else if client.is_view_camera {
            Some("View camera")
        } else if client.is_terminal {
            Some("Terminal")
        } else {
            None
        };
        if let Some(kind) = kind {
            text(ui, y, t(kind), 12., Color32::from_white_alpha(0xB3));
            y += 15.;
        }
        let state = if client.disconnected {
            t("Disconnected")
        } else if client.authorized {
            let s = c.since.elapsed().as_secs();
            format!("{}  {:02}:{:02}:{:02}", t("Connected"), s / 3600, s / 60 % 60, s % 60)
        } else {
            t("Request access to your device...")
        };
        text(ui, y.max(avatar.bottom() - 16.), state, 14., Color32::WHITE);
    }

    fn permissions(&mut self, ui: &mut egui::Ui, c: &CmClient) {
        let (outer, _) = ui.allocate_exact_size(vec2(ui.available_width(), 170.), Sense::hover());
        let rect = outer.shrink(5.);
        ui.painter().add(egui::Shadow {
            offset: [0, 2],
            blur: 2,
            spread: 1,
            color: Color32::from_black_alpha(0x33),
        }
        .as_shape(rect, CornerRadius::same(10)));
        ui.painter().rect_filled(rect, CornerRadius::same(10), theme::GRAY_BG);
        ui.painter().text(
            pos2(rect.left() + 10., rect.top() + 8.),
            Align2::LEFT_TOP,
            t("Permissions"),
            FontId::proportional(16.),
            theme::TEXT,
        );
        let cols = 4.;
        let spacing = 10.;
        let inner_w = rect.width() - 20.;
        let tile = ((inner_w - spacing * (cols - 1.)) / cols).min(52.);
        let x0 = rect.left() + 10.;
        let y0 = rect.top() + 36.;
        for (i, (name, glyph, tip)) in PERMISSIONS.iter().enumerate() {
            let (col, row) = ((i % 4) as f32, (i / 4) as f32);
            let r = Rect::from_min_size(
                pos2(x0 + col * (tile + spacing), y0 + row * (tile + spacing)),
                vec2(tile, tile),
            );
            let enabled = permission(&c.client, name);
            let resp = ui.interact(r, ui.id().with(("perm", c.client.id, *name)), Sense::click());
            ui.painter().rect_filled(
                r,
                CornerRadius::same(10),
                if enabled { theme::ACCENT } else { theme::GREY_700 },
            );
            paint_glyph(ui, &mut self.icons, r.shrink(tile * 0.22), *glyph, Color32::WHITE);
            if resp.on_hover_text(t(tip)).clicked() && !c.client.disconnected {
                ui_cm_interface::switch_permission(c.client.id, name.to_string(), !enabled);
                let mut clients = self.handler.clients.lock().unwrap();
                if let Some(x) = clients.iter_mut().find(|x| x.client.id == c.client.id) {
                    set_permission(&mut x.client, name, !enabled);
                }
            }
        }
    }
}

impl eframe::App for CmWindow {
    fn clear_color(&self, _visuals: &egui::Visuals) -> [f32; 4] {
        [1., 1., 1., 1.]
    }

    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        let clients = self.handler.clients.lock().unwrap().clone();
        // The server starts a new connection manager when needed.
        if clients.is_empty() && self.handler.had_clients.load(Ordering::SeqCst) {
            ctx.send_viewport_cmd(egui::ViewportCommand::Close);
        }
        if self.selected >= clients.len() {
            self.selected = clients.len().saturating_sub(1);
        }
        let tabs: Vec<Tab> = clients
            .iter()
            .map(|c| Tab { label: c.client.name.chars().take(14).collect(), glyph: None, closable: false })
            .collect();
        if let Some(widgets::TitleBarEvent::SelectTab(i)) =
            widgets::title_bar(ctx, &mut self.icons, &tabs, self.selected, false, false)
        {
            self.selected = i;
        }
        let current = clients.get(self.selected).cloned();
        if let Some(c) = current.as_ref() {
            egui::TopBottomPanel::bottom("cm_buttons")
                .frame(egui::Frame::NONE.fill(Color32::WHITE).inner_margin(Margin { left: 12, right: 12, top: 4, bottom: 12 }))
                .show_separator_line(false)
                .show(ctx, |ui| {
                    let id = c.client.id;
                    let w = ui.available_width();
                    if c.client.disconnected {
                        if widgets::flat_button(ui, &mut self.icons, &t("Close"), None, theme::ACCENT, Color32::WHITE, w, 10, false).clicked() {
                            ui_cm_interface::remove(id);
                            self.handler.remove_connection(id, true);
                        }
                    } else if c.client.authorized {
                        if widgets::flat_button(ui, &mut self.icons, &t("Disconnect"), Some(Glyph::LinkOff), theme::RED, Color32::WHITE, w, 10, false).clicked() {
                            ui_cm_interface::close(id);
                        }
                    } else {
                        ui.horizontal(|ui| {
                            let half = (w - 8.) / 2.;
                            if widgets::flat_button(ui, &mut self.icons, &t("Accept"), None, theme::ACCENT, Color32::WHITE, half, 10, false).clicked() {
                                ui_cm_interface::authorize(id);
                            }
                            if widgets::flat_button(ui, &mut self.icons, &t("Cancel"), None, Color32::TRANSPARENT, theme::TEXT, half, 10, true).clicked() {
                                ui_cm_interface::close(id);
                            }
                        });
                    }
                });
        }
        egui::CentralPanel::default()
            .frame(egui::Frame::NONE.fill(Color32::WHITE).inner_margin(Margin::symmetric(8, 4)))
            .show(ctx, |ui| {
                let Some(c) = current.as_ref() else {
                    ui.centered_and_justified(|ui| ui.label(t("Waiting")));
                    return;
                };
                self.header(ui, c);
                self.permissions(ui, c);
            });
        if clients.iter().any(|c| c.client.authorized && !c.client.disconnected) {
            ctx.request_repaint_after(Duration::from_secs(1));
        }
    }
}
