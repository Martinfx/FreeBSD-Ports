use super::{
    run_window,
    svg::IconCache,
    t, theme,
    widgets::{self, format_id, paint_glyph, Glyph},
};
use crate::{
    client::*,
    common::input::*,
    ui_session_interface::{InvokeUiSession, Session},
};
use eframe::egui::{
    self, vec2, Align2, Color32, CornerRadius, Margin, Rect, Sense, Stroke, StrokeKind,
};
use base::message_proto::*;
use hbb_common::rendezvous_proto::ConnType;
use std::{
    sync::{Arc, Mutex, RwLock},
    time::{Duration, Instant},
};

#[derive(Default)]
struct Frame {
    w: usize,
    h: usize,
    rgba: Vec<u8>,
    dirty: bool,
}

#[derive(Clone)]
struct MsgBox {
    msgtype: String,
    title: String,
    text: String,
    link: String,
    retry: bool,
}

#[derive(Default)]
struct State {
    frame: Frame,
    // Origin and size of the currently displayed remote display.
    display: (i32, i32, i32, i32),
    displays: Vec<(i32, i32, i32, i32)>,
    current_display: i32,
    peer: String,
    msgbox: Option<MsgBox>,
    messages: Vec<String>,
}

#[derive(Clone, Default)]
pub struct EguiHandler {
    state: Arc<Mutex<State>>,
    ctx: Arc<Mutex<Option<egui::Context>>>,
}

impl EguiHandler {
    fn repaint(&self) {
        if let Some(ctx) = self.ctx.lock().unwrap().as_ref() {
            ctx.request_repaint();
        }
    }

    fn update<F: FnOnce(&mut State)>(&self, f: F) {
        f(&mut self.state.lock().unwrap());
        self.repaint();
    }
}

impl InvokeUiSession for EguiHandler {
    fn set_cursor_data(&self, _cd: CursorData) {}

    fn set_cursor_id(&self, _id: String) {}

    fn set_cursor_position(&self, _cp: CursorPosition) {}

    fn set_display(&self, x: i32, y: i32, w: i32, h: i32, _cursor_embedded: bool, _scale: f64) {
        self.update(|s| s.display = (x, y, w, h));
    }

    fn switch_display(&self, display: &SwitchDisplay) {
        self.update(|s| {
            s.current_display = display.display;
            s.display = (display.x, display.y, display.width, display.height);
        });
    }

    fn set_peer_info(&self, pi: &PeerInfo) {
        self.update(|s| {
            s.peer = format!("{}@{} ({})", pi.username, pi.hostname, pi.platform);
            s.displays = pi
                .displays
                .iter()
                .map(|d| (d.x, d.y, d.width, d.height))
                .collect();
            s.current_display = pi.current_display;
            if let Some(d) = s.displays.get(pi.current_display as usize) {
                s.display = *d;
            }
            if s.msgbox.as_ref().map(|m| m.msgtype == "connecting") == Some(true) {
                s.msgbox = None;
            }
        });
    }

    fn set_displays(&self, displays: &Vec<DisplayInfo>) {
        self.update(|s| {
            s.displays = displays
                .iter()
                .map(|d| (d.x, d.y, d.width, d.height))
                .collect();
        });
    }

    fn set_platform_additions(&self, _data: &str) {}

    fn on_connected(&self, _conn_type: ConnType) {}

    fn update_privacy_mode(&self) {}

    fn set_permission(&self, _name: &str, _value: bool) {}

    // Login succeeded, close the password dialog.
    fn close_success(&self) {
        self.update(|s| s.msgbox = None);
    }

    fn update_quality_status(&self, _qs: QualityStatus) {}

    fn set_connection_type(&self, _is_secured: bool, _direct: bool, _stream_type: &str) {}

    fn set_fingerprint(&self, _fingerprint: String) {}

    fn job_error(&self, _id: i32, _err: String, _file_num: i32) {}

    fn job_done(&self, _id: i32, _file_num: i32) {}

    fn clear_all_jobs(&self) {}

    fn new_message(&self, msg: String) {
        self.update(|s| s.messages.push(msg));
    }

    fn update_transfer_list(&self) {}

    fn load_last_job(&self, _cnt: i32, _job_json: &str, _auto_start: bool) {}

    fn update_folder_files(
        &self,
        _id: i32,
        _entries: &Vec<FileEntry>,
        _path: String,
        _is_local: bool,
        _only_count: bool,
    ) {
    }

    fn confirm_delete_files(&self, _id: i32, _i: i32, _name: String) {}

    fn override_file_confirm(
        &self,
        _id: i32,
        _file_num: i32,
        _to: String,
        _is_upload: bool,
        _is_identical: bool,
    ) {
    }

    fn update_block_input_state(&self, _on: bool) {}

    fn job_progress(&self, _id: i32, _file_num: i32, _speed: f64, _finished_size: f64) {}

    fn adapt_size(&self) {}

    fn on_rgba(&self, _display: usize, rgba: &mut scrap::ImageRgb) {
        let (w, h) = (rgba.w, rgba.h);
        if w == 0 || h == 0 || rgba.raw.len() < w * h * 4 {
            return;
        }
        let stride = rgba.raw.len() / h;
        // ARGB in scrap (libyuv) is B, G, R, A in memory, ABGR is R, G, B, A.
        let swap = !matches!(rgba.fmt, scrap::ImageFormat::ABGR);
        {
            let mut s = self.state.lock().unwrap();
            let frame = &mut s.frame;
            frame.rgba.resize(w * h * 4, 0);
            for y in 0..h {
                let src = &rgba.raw[y * stride..y * stride + w * 4];
                let dst = &mut frame.rgba[y * w * 4..(y + 1) * w * 4];
                for (d, p) in dst.chunks_exact_mut(4).zip(src.chunks_exact(4)) {
                    if swap {
                        d[0] = p[2];
                        d[1] = p[1];
                        d[2] = p[0];
                    } else {
                        d[..3].copy_from_slice(&p[..3]);
                    }
                    d[3] = 255;
                }
            }
            frame.w = w;
            frame.h = h;
            frame.dirty = true;
            if s.msgbox.as_ref().map(|m| m.msgtype == "connecting") == Some(true) {
                s.msgbox = None;
            }
        }
        self.repaint();
    }

    fn msgbox(&self, msgtype: &str, title: &str, text: &str, link: &str, retry: bool) {
        let m = MsgBox {
            msgtype: msgtype.to_owned(),
            title: title.to_owned(),
            text: text.to_owned(),
            link: link.to_owned(),
            retry,
        };
        self.update(|s| s.msgbox = Some(m));
    }

    fn cancel_msgbox(&self, _tag: &str) {
        self.update(|s| s.msgbox = None);
    }

    fn switch_back(&self, _id: &str) {}

    fn portable_service_running(&self, _running: bool) {}

    fn on_voice_call_started(&self) {}

    fn on_voice_call_closed(&self, _reason: &str) {}

    fn on_voice_call_waiting(&self) {}

    fn on_voice_call_incoming(&self) {}

    fn get_rgba(&self, _display: usize) -> *const u8 {
        std::ptr::null()
    }

    fn next_rgba(&self, _display: usize) {}

    fn set_multiple_windows_session(&self, _sessions: Vec<WindowsSession>) {}

    fn set_current_display(&self, disp_idx: i32) {
        self.update(|s| s.current_display = disp_idx);
    }

    fn update_record_status(&self, _start: bool) {}

    fn printer_request(&self, _id: i32, _path: String) {}

    fn handle_screenshot_resp(&self, _sid: String, _msg: String) {}

    fn handle_terminal_response(&self, _response: TerminalResponse) {}
}

struct RemoteWindow {
    session: Session<EguiHandler>,
    handler: EguiHandler,
    icons: IconCache,
    id: String,
    texture: Option<egui::TextureHandle>,
    fit: bool,
    pinned: bool,
    collapsed: bool,
    last_toolbar_use: Instant,
    password: String,
    remember: bool,
    code_2fa: String,
    last_pos: Option<(i32, i32)>,
}

pub fn run(args: &mut [String]) {
    let id = args[1].clone();
    let password = args.get(2).cloned().unwrap_or_default();
    let rest: Vec<String> = args.iter().skip(3).cloned().collect();
    let force_relay = rest.contains(&"--relay".to_owned());
    let handler = EguiHandler::default();
    let session: Session<EguiHandler> = Session {
        password,
        args: rest,
        ui_handler: handler.clone(),
        server_keyboard_enabled: Arc::new(RwLock::new(true)),
        server_file_transfer_enabled: Arc::new(RwLock::new(true)),
        server_clipboard_enabled: Arc::new(RwLock::new(true)),
        ..Default::default()
    };
    session.lc.write().unwrap().initialize(
        id.clone(),
        ConnType::DEFAULT_CONN,
        None,
        force_relay,
        None,
        None,
        None,
    );
    let title = id.clone();
    run_window(&title, [1280., 800.], [480., 320.], move |ctx| {
        *handler.ctx.lock().unwrap() = Some(ctx.clone());
        handler.msgbox("connecting", "Connecting...", "Connection in progress. Please wait.", "", false);
        session.reconnect(false);
        RemoteWindow {
            session,
            handler,
            icons: IconCache::default(),
            id,
            texture: None,
            fit: true,
            pinned: true,
            collapsed: false,
            last_toolbar_use: Instant::now(),
            password: String::new(),
            remember: false,
            code_2fa: String::new(),
            last_pos: None,
        }
    });
}

enum ToolbarColor {
    Blue,
    Inactive,
    Red,
}

impl RemoteWindow {
    // A 32x32 toolbar button of the Flutter remote toolbar.
    fn toolbar_button(
        &mut self,
        ui: &mut egui::Ui,
        icon: &'static str,
        color: ToolbarColor,
        tooltip: &str,
    ) -> egui::Response {
        let (rect, resp) = ui.allocate_exact_size(vec2(32., 32.), Sense::click());
        let fill = match (color, resp.hovered()) {
            (ToolbarColor::Blue, false) => theme::BUTTON,
            (ToolbarColor::Blue, true) => theme::BLUE_HOVER,
            (ToolbarColor::Inactive, false) => theme::INACTIVE,
            (ToolbarColor::Inactive, true) => Color32::from_rgb(0x30, 0x30, 0x30),
            (ToolbarColor::Red, false) => theme::RED,
            (ToolbarColor::Red, true) => theme::RED_HOVER,
        };
        ui.painter().rect_filled(rect, CornerRadius::same(8), fill);
        self.icons.paint(ui, rect, icon, Some(Color32::WHITE));
        resp.on_hover_text(tooltip)
    }

    fn menu_item(ui: &mut egui::Ui, text: &str) -> bool {
        ui.add(egui::Button::new(text).frame(false).min_size(vec2(180., 26.)))
            .clicked()
    }

    fn toolbar(&mut self, ctx: &egui::Context) {
        let (displays, current) = {
            let s = self.handler.state.lock().unwrap();
            (s.displays.len(), s.current_display)
        };
        // Unpinned toolbars collapse after 5 s without use, like upstream.
        if !self.pinned && !self.collapsed && self.last_toolbar_use.elapsed() > Duration::from_secs(5) {
            self.collapsed = true;
        }
        let top = widgets::TITLE_BAR_HEIGHT;
        egui::Area::new(egui::Id::new("remote_toolbar"))
            .anchor(Align2::CENTER_TOP, [0., top])
            .order(egui::Order::Foreground)
            .show(ctx, |ui| {
                if ui.rect_contains_pointer(ui.max_rect()) {
                    self.last_toolbar_use = Instant::now();
                }
                ui.vertical_centered(|ui| {
                    ui.spacing_mut().item_spacing = vec2(0., 0.);
                    if !self.collapsed {
                        egui::Frame::NONE
                            .fill(Color32::WHITE)
                            .stroke(Stroke::new(1., theme::BORDER3))
                            .corner_radius(CornerRadius::same(4))
                            .shadow(egui::Shadow { offset: [0, 1], blur: 6, spread: 0, color: Color32::from_black_alpha(40) })
                            .inner_margin(Margin::symmetric(4, 0))
                            .show(ui, |ui| {
                                ui.horizontal(|ui| {
                                    ui.spacing_mut().item_spacing.x = 4.;
                                    ui.add_space(0.);
                                    let pin = if self.pinned { "pinned" } else { "unpinned" };
                                    let pin_color = if self.pinned { ToolbarColor::Blue } else { ToolbarColor::Inactive };
                                    let tip = if self.pinned { t("Unpin Toolbar") } else { t("Pin Toolbar") };
                                    ui.add_space(2.);
                                    if self.toolbar_button(ui, pin, pin_color, &tip).clicked() {
                                        self.pinned = !self.pinned;
                                    }
                                    if displays > 1 {
                                        let resp = self.toolbar_button(ui, "screen", ToolbarColor::Blue, &t("Select Monitor"));
                                        menu(ui, &resp, "monitor_menu", |ui| {
                                            for i in 0..displays as i32 {
                                                if ui.radio(i == current, format!("{} {}", t("Display"), i + 1)).clicked() {
                                                    self.session.switch_display(i);
                                                }
                                            }
                                        });
                                    }
                                    let resp = self.toolbar_button(ui, "actions", ToolbarColor::Blue, &t("Control Actions"));
                                    menu(ui, &resp, "actions_menu", |ui| {
                                        if Self::menu_item(ui, &t("Insert Ctrl + Alt + Del")) {
                                            self.session.ctrl_alt_del();
                                        }
                                        if Self::menu_item(ui, &t("Insert Lock")) {
                                            self.session.lock_screen();
                                        }
                                        if Self::menu_item(ui, &t("Refresh")) {
                                            self.session.refresh_video(current);
                                        }
                                    });
                                    let resp = self.toolbar_button(ui, "display", ToolbarColor::Blue, &t("Display Settings"));
                                    menu(ui, &resp, "display_menu", |ui| {
                                        if ui.radio(!self.fit, t("Scale original")).clicked() {
                                            self.fit = false;
                                        }
                                        if ui.radio(self.fit, t("Scale adaptive")).clicked() {
                                            self.fit = true;
                                        }
                                    });
                                    if self.toolbar_button(ui, "close", ToolbarColor::Red, &t("Close")).clicked() {
                                        ctx.send_viewport_cmd(egui::ViewportCommand::Close);
                                    }
                                    ui.add_space(2.);
                                });
                                ui.add_space(0.);
                            });
                    }
                    // The collapse handle below the toolbar.
                    let (r, resp) = ui.allocate_exact_size(vec2(36., 20.), Sense::click());
                    ui.painter().rect_filled(
                        r,
                        CornerRadius { nw: 0, ne: 0, sw: 5, se: 5 },
                        if resp.hovered() { Color32::from_rgb(0xDB, 0xEA, 0xFF) } else { Color32::WHITE },
                    );
                    ui.painter().rect_stroke(
                        r,
                        CornerRadius { nw: 0, ne: 0, sw: 5, se: 5 },
                        Stroke::new(1., theme::BORDER3),
                        StrokeKind::Inside,
                    );
                    let g = if self.collapsed { Glyph::ExpandMore } else { Glyph::ExpandLess };
                    paint_glyph(ui, &mut self.icons, Rect::from_center_size(r.center(), vec2(20., 20.)), g, theme::INACTIVE);
                    if resp.clicked() {
                        self.collapsed = !self.collapsed;
                        self.last_toolbar_use = Instant::now();
                    }
                });
            });
    }

    fn msgbox(&mut self, ctx: &egui::Context) -> bool {
        let Some(m) = self.handler.state.lock().unwrap().msgbox.clone() else {
            return false;
        };
        let mut close = false;
        let mut quit = false;
        let title = match m.msgtype.as_str() {
            "input-password" | "re-input-password" => t("Password Required"),
            _ => t(&m.title),
        };
        widgets::dialog(ctx, &title, |ui| {
            if !m.text.is_empty() && m.msgtype != "input-password" {
                ui.label(t(&m.text));
                ui.add_space(8.);
            }
            if !m.link.is_empty() {
                ui.hyperlink(&m.link);
            }
            let enter = ui.input(|i| i.key_pressed(egui::Key::Enter));
            match m.msgtype.as_str() {
                "connecting" => {
                    ui.horizontal(|ui| {
                        ui.spinner();
                        ui.label(t("Connecting..."));
                    });
                    ui.add_space(16.);
                    widgets::button_row(ui, |ui| {
                        if widgets::outlined_button(ui, &t("Cancel"), 80.).clicked() {
                            quit = true;
                        }
                    });
                }
                "input-password" | "re-input-password" => {
                    let edit = widgets::text_input(ui, &mut self.password, &t("Password"), true, 340.);
                    edit.request_focus();
                    ui.add_space(6.);
                    widgets::checkbox(ui, &mut self.remember, &t("Remember password"));
                    ui.add_space(16.);
                    widgets::button_row(ui, |ui| {
                        if widgets::primary_button(ui, &t("OK"), theme::ACCENT, 80.).clicked() || enter {
                            self.session.login(
                                String::new(),
                                String::new(),
                                std::mem::take(&mut self.password),
                                self.remember,
                            );
                            close = true;
                        }
                        if widgets::outlined_button(ui, &t("Cancel"), 80.).clicked() {
                            quit = true;
                        }
                    });
                }
                "input-2fa" => {
                    widgets::text_input(ui, &mut self.code_2fa, &t("Verification code"), false, 340.)
                        .request_focus();
                    ui.add_space(16.);
                    widgets::button_row(ui, |ui| {
                        if widgets::primary_button(ui, &t("OK"), theme::ACCENT, 80.).clicked() || enter {
                            self.session.send2fa(std::mem::take(&mut self.code_2fa), false);
                            close = true;
                        }
                        if widgets::outlined_button(ui, &t("Cancel"), 80.).clicked() {
                            quit = true;
                        }
                    });
                }
                _ => {
                    ui.add_space(8.);
                    widgets::button_row(ui, |ui| {
                        if m.msgtype.contains("error") || m.msgtype.contains("nook") {
                            if widgets::outlined_button(ui, &t("Close"), 80.).clicked() {
                                quit = true;
                            }
                        } else if widgets::primary_button(ui, &t("OK"), theme::ACCENT, 80.).clicked() {
                            close = true;
                        }
                        if m.retry && widgets::primary_button(ui, &t("Retry"), theme::ACCENT, 80.).clicked() {
                            self.session.reconnect(false);
                            close = true;
                        }
                    });
                }
            }
        });
        if quit {
            ctx.send_viewport_cmd(egui::ViewportCommand::Close);
        }
        if close || quit {
            let mut s = self.handler.state.lock().unwrap();
            if s.msgbox.as_ref().map(|x| x.msgtype == m.msgtype) == Some(true) {
                s.msgbox = None;
            }
        }
        true
    }

    fn update_texture(&mut self, ctx: &egui::Context) {
        let mut s = self.handler.state.lock().unwrap();
        if !s.frame.dirty {
            return;
        }
        s.frame.dirty = false;
        let image =
            egui::ColorImage::from_rgba_unmultiplied([s.frame.w, s.frame.h], &s.frame.rgba);
        drop(s);
        match self.texture.as_mut() {
            Some(tex) => tex.set(image, egui::TextureOptions::LINEAR),
            None => {
                self.texture =
                    Some(ctx.load_texture("remote-display", image, egui::TextureOptions::LINEAR))
            }
        }
    }

    // Mouse and keyboard events inside the remote image.
    fn handle_input(&mut self, ui: &egui::Ui, rect: egui::Rect, scale: f32) {
        let display = self.handler.state.lock().unwrap().display;
        let to_remote = |pos: egui::Pos2| -> (i32, i32) {
            (
                ((pos.x - rect.min.x) / scale) as i32 + display.0,
                ((pos.y - rect.min.y) / scale) as i32 + display.1,
            )
        };
        // Ignore pointer events over the toolbar, menus and dialogs.
        let ctx = ui.ctx().clone();
        let over_ui = |p: egui::Pos2| {
            ctx.layer_id_at(p)
                .map(|l| l.order != egui::Order::Background)
                .unwrap_or(false)
        };
        let events = ui.input(|i| i.events.clone());
        for event in events {
            match event {
                egui::Event::PointerMoved(pos) if rect.contains(pos) && !over_ui(pos) => {
                    let p = to_remote(pos);
                    if self.last_pos != Some(p) {
                        self.last_pos = Some(p);
                        self.send_mouse(MOUSE_TYPE_MOVE, p.0, p.1, egui::Modifiers::NONE);
                    }
                }
                egui::Event::PointerButton {
                    pos,
                    button,
                    pressed,
                    modifiers,
                } if (rect.contains(pos) && !over_ui(pos)) || !pressed => {
                    let buttons = match button {
                        egui::PointerButton::Primary => MOUSE_BUTTON_LEFT,
                        egui::PointerButton::Secondary => MOUSE_BUTTON_RIGHT,
                        egui::PointerButton::Middle => MOUSE_BUTTON_WHEEL,
                        egui::PointerButton::Extra1 => MOUSE_BUTTON_BACK,
                        egui::PointerButton::Extra2 => MOUSE_BUTTON_FORWARD,
                    };
                    let typ = if pressed { MOUSE_TYPE_DOWN } else { MOUSE_TYPE_UP };
                    self.send_mouse((buttons << 3) | typ, 0, 0, modifiers);
                }
                egui::Event::MouseWheel {
                    unit,
                    delta,
                    modifiers,
                } if ui.rect_contains_pointer(rect) => {
                    let (dx, dy) = match unit {
                        egui::MouseWheelUnit::Point => (delta.x / 50., delta.y / 50.),
                        _ => (delta.x, delta.y),
                    };
                    let (dx, dy) = (dx.round() as i32, dy.round() as i32);
                    if dx != 0 || dy != 0 {
                        self.send_mouse(MOUSE_TYPE_WHEEL, dx, dy, modifiers);
                    }
                }
                egui::Event::Text(text) => {
                    self.session.input_string(&text);
                }
                egui::Event::Paste(text) => {
                    self.session.input_string(&text);
                }
                egui::Event::Copy => self.press_key("VK_C", egui::Modifiers::COMMAND),
                egui::Event::Cut => self.press_key("VK_X", egui::Modifiers::COMMAND),
                egui::Event::Key {
                    key,
                    pressed,
                    modifiers,
                    ..
                } => {
                    let Some((name, printable)) = vk_name(key) else {
                        continue;
                    };
                    // Plain printable keys arrive as `Event::Text` as well.
                    if printable && !(modifiers.ctrl || modifiers.alt || modifiers.mac_cmd) {
                        continue;
                    }
                    self.session.input_key(
                        name,
                        pressed,
                        false,
                        modifiers.alt,
                        modifiers.ctrl,
                        modifiers.shift,
                        modifiers.mac_cmd,
                    );
                }
                _ => {}
            }
        }
    }

    fn send_mouse(&self, mask: i32, x: i32, y: i32, m: egui::Modifiers) {
        self.session
            .send_mouse(mask, x, y, m.alt, m.ctrl, m.shift, m.mac_cmd);
    }

    fn press_key(&self, name: &str, m: egui::Modifiers) {
        self.session
            .input_key(name, true, true, m.alt, m.ctrl, m.shift, m.mac_cmd);
    }
}

impl eframe::App for RemoteWindow {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        widgets::resize_handles(ctx);
        self.update_texture(ctx);
        let tabs = [widgets::Tab { label: format_id(&self.id), glyph: None, closable: true }];
        if let Some(widgets::TitleBarEvent::CloseTab) =
            widgets::title_bar(ctx, &mut self.icons, &tabs, 0, false, true)
        {
            ctx.send_viewport_cmd(egui::ViewportCommand::Close);
        }
        let dialog = self.msgbox(ctx);
        if self.texture.is_some() {
            self.toolbar(ctx);
        }
        if !self.pinned && !self.collapsed {
            ctx.request_repaint_after(Duration::from_millis(500));
        }
        egui::CentralPanel::default()
            .frame(egui::Frame::NONE.fill(Color32::BLACK))
            .show(ctx, |ui| {
                let Some(tex) = self.texture.as_ref() else {
                    return;
                };
                let size = tex.size_vec2();
                let avail = ui.available_size();
                let scale = if self.fit {
                    (avail.x / size.x).min(avail.y / size.y).min(1.)
                } else {
                    1.
                };
                let image = egui::Image::new((tex.id(), size * scale));
                let rect = if self.fit {
                    ui.centered_and_justified(|ui| ui.add(image)).inner.rect
                } else {
                    egui::ScrollArea::both()
                        .show(ui, |ui| ui.add(image))
                        .inner
                        .rect
                };
                if !dialog {
                    self.handle_input(ui, rect, scale);
                }
            });
    }

    fn on_exit(&mut self, _gl: Option<&eframe::glow::Context>) {
        self.session.close();
    }
}

fn menu(ui: &mut egui::Ui, resp: &egui::Response, id: &str, add: impl FnOnce(&mut egui::Ui)) {
    let popup = ui.id().with(id);
    if resp.clicked() {
        ui.memory_mut(|m| m.toggle_popup(popup));
    }
    egui::popup::popup_below_widget(ui, popup, resp, egui::PopupCloseBehavior::CloseOnClick, |ui| {
        ui.set_min_width(180.);
        add(ui);
    });
}

// egui key -> RustDesk legacy key name, and whether it produces text.
fn vk_name(key: egui::Key) -> Option<(&'static str, bool)> {
    use egui::Key::*;
    Some(match key {
        ArrowDown => ("VK_DOWN", false),
        ArrowLeft => ("VK_LEFT", false),
        ArrowRight => ("VK_RIGHT", false),
        ArrowUp => ("VK_UP", false),
        Escape => ("VK_ESCAPE", false),
        Tab => ("VK_TAB", false),
        Backspace => ("VK_BACK", false),
        Enter => ("VK_RETURN", false),
        Insert => ("VK_INSERT", false),
        Delete => ("VK_DELETE", false),
        Home => ("VK_HOME", false),
        End => ("VK_END", false),
        PageUp => ("VK_PRIOR", false),
        PageDown => ("VK_NEXT", false),
        Space => ("VK_SPACE", true),
        F1 => ("VK_F1", false),
        F2 => ("VK_F2", false),
        F3 => ("VK_F3", false),
        F4 => ("VK_F4", false),
        F5 => ("VK_F5", false),
        F6 => ("VK_F6", false),
        F7 => ("VK_F7", false),
        F8 => ("VK_F8", false),
        F9 => ("VK_F9", false),
        F10 => ("VK_F10", false),
        F11 => ("VK_F11", false),
        F12 => ("VK_F12", false),
        Num0 => ("VK_0", true),
        Num1 => ("VK_1", true),
        Num2 => ("VK_2", true),
        Num3 => ("VK_3", true),
        Num4 => ("VK_4", true),
        Num5 => ("VK_5", true),
        Num6 => ("VK_6", true),
        Num7 => ("VK_7", true),
        Num8 => ("VK_8", true),
        Num9 => ("VK_9", true),
        A => ("VK_A", true),
        B => ("VK_B", true),
        C => ("VK_C", true),
        D => ("VK_D", true),
        E => ("VK_E", true),
        F => ("VK_F", true),
        G => ("VK_G", true),
        H => ("VK_H", true),
        I => ("VK_I", true),
        J => ("VK_J", true),
        K => ("VK_K", true),
        L => ("VK_L", true),
        M => ("VK_M", true),
        N => ("VK_N", true),
        O => ("VK_O", true),
        P => ("VK_P", true),
        Q => ("VK_Q", true),
        R => ("VK_R", true),
        S => ("VK_S", true),
        T => ("VK_T", true),
        U => ("VK_U", true),
        V => ("VK_V", true),
        W => ("VK_W", true),
        X => ("VK_X", true),
        Y => ("VK_Y", true),
        Z => ("VK_Z", true),
        Minus => ("VK_MINUS", true),
        Plus | Equals => ("VK_PLUS", true),
        Comma => ("VK_COMMA", true),
        Slash => ("VK_SLASH", true),
        Semicolon => ("VK_SEMICOLON", true),
        Quote => ("VK_QUOTE", true),
        OpenBracket => ("VK_LBRACKET", true),
        CloseBracket => ("VK_RBRACKET", true),
        Backslash => ("VK_BACKSLASH", true),
        _ => return None,
    })
}
