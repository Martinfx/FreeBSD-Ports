use super::{run_window, t};
use crate::ui_interface::{
    get_connect_status, get_option, new_remote, set_option, set_permanent_password,
    temporary_password, update_temporary_password,
};
use eframe::egui;
use hbb_common::config::{LocalConfig, PeerConfig};
use std::{
    sync::{Arc, Mutex},
    time::Duration,
};

#[derive(Default, Clone)]
struct Status {
    id: String,
    password: String,
    status_num: i32,
}

struct RecentPeer {
    id: String,
    info: String,
}

struct MainWindow {
    status: Arc<Mutex<Status>>,
    remote_id: String,
    recent: Vec<RecentPeer>,
    show_settings: bool,
    id_server: String,
    relay_server: String,
    api_server: String,
    key: String,
    permanent_password: String,
    settings_msg: String,
}

pub fn run() {
    // Same helper threads as the Sciter main window.
    std::thread::spawn(crate::ui_interface::check_zombie);
    std::thread::spawn(crate::ipc::start_pa);

    // core_main() already started the server in this process if none runs.
    // Keep id/password/status in sync with the server.
    crate::ui_interface::start_option_status_sync();

    run_window(&crate::get_app_name(), [460., 560.], |ctx| {
        let status = Arc::new(Mutex::new(Status::default()));
        start_status_thread(status.clone(), ctx.clone());
        MainWindow {
            status,
            remote_id: LocalConfig::get_remote_id(),
            recent: load_recent(),
            show_settings: false,
            id_server: get_option("custom-rendezvous-server"),
            relay_server: get_option("relay-server"),
            api_server: get_option("api-server"),
            key: get_option("key"),
            permanent_password: String::new(),
            settings_msg: String::new(),
        }
    });
}

// IPC calls may block, keep them out of the UI thread.
fn start_status_thread(status: Arc<Mutex<Status>>, ctx: egui::Context) {
    std::thread::spawn(move || loop {
        let new = Status {
            id: crate::ipc::get_id(),
            password: temporary_password(),
            status_num: get_connect_status().status_num,
        };
        let changed = {
            let mut lock = status.lock().unwrap();
            let changed = lock.id != new.id
                || lock.password != new.password
                || lock.status_num != new.status_num;
            *lock = new;
            changed
        };
        if changed {
            ctx.request_repaint();
        }
        std::thread::sleep(Duration::from_secs(1));
    });
}

fn load_recent() -> Vec<RecentPeer> {
    PeerConfig::peers(None)
        .into_iter()
        .take(20)
        .map(|(id, _, p)| {
            let mut info = format!("{}@{}", p.info.username, p.info.hostname);
            if !p.info.platform.is_empty() {
                info = format!("{} ({})", info, p.info.platform);
            }
            RecentPeer { id, info }
        })
        .collect()
}

impl MainWindow {
    fn connect(&mut self, id: String) {
        let id = id.replace(' ', "");
        if id.is_empty() {
            return;
        }
        LocalConfig::set_remote_id(&id);
        new_remote(id, "connect".to_owned(), false);
    }

    fn own_desktop(&mut self, ui: &mut egui::Ui) {
        let status = self.status.lock().unwrap().clone();
        ui.heading(t("Your Desktop"));
        ui.label(t("desk_tip"));
        ui.add_space(8.);
        egui::Grid::new("own_desktop").num_columns(2).show(ui, |ui| {
            ui.label(t("ID"));
            ui.horizontal(|ui| {
                ui.label(egui::RichText::new(&status.id).monospace().size(20.));
                if ui.small_button(t("Copy")).clicked() {
                    ui.ctx().copy_text(status.id.clone());
                }
            });
            ui.end_row();
            ui.label(t("One-time Password"));
            ui.horizontal(|ui| {
                ui.label(egui::RichText::new(&status.password).monospace().size(20.));
                if ui.small_button(t("Copy")).clicked() {
                    ui.ctx().copy_text(status.password.clone());
                }
                if ui.small_button(t("Refresh Password")).clicked() {
                    update_temporary_password();
                }
            });
            ui.end_row();
        });
        ui.add_space(4.);
        let (color, text) = match status.status_num {
            -1 => (egui::Color32::RED, t("not_ready_status")),
            0 => (egui::Color32::YELLOW, t("connecting_status")),
            _ => (egui::Color32::GREEN, t("Ready")),
        };
        ui.horizontal(|ui| {
            let (rect, _) = ui.allocate_exact_size(egui::vec2(10., 10.), egui::Sense::hover());
            ui.painter().circle_filled(rect.center(), 5., color);
            ui.label(text);
        });
    }

    fn control_remote(&mut self, ui: &mut egui::Ui) {
        ui.heading(t("Control Remote Desktop"));
        ui.horizontal(|ui| {
            let edit = ui.add(
                egui::TextEdit::singleline(&mut self.remote_id)
                    .hint_text(t("Enter Remote ID"))
                    .desired_width(260.),
            );
            let enter = edit.lost_focus() && ui.input(|i| i.key_pressed(egui::Key::Enter));
            if ui.button(t("Connect")).clicked() || enter {
                self.connect(self.remote_id.clone());
            }
        });
        ui.add_space(8.);
        ui.label(t("Recent sessions"));
        let mut to_connect = None;
        let mut to_remove = None;
        egui::ScrollArea::vertical().max_height(180.).show(ui, |ui| {
            for peer in self.recent.iter() {
                ui.horizontal(|ui| {
                    if ui.link(&peer.id).clicked() {
                        to_connect = Some(peer.id.clone());
                    }
                    ui.weak(&peer.info);
                    if ui.small_button("x").on_hover_text(t("Remove")).clicked() {
                        to_remove = Some(peer.id.clone());
                    }
                });
            }
        });
        if let Some(id) = to_connect {
            self.remote_id = id.clone();
            self.connect(id);
        }
        if let Some(id) = to_remove {
            PeerConfig::remove(&id);
            self.recent = load_recent();
        }
    }

    fn settings(&mut self, ctx: &egui::Context) {
        let mut open = self.show_settings;
        egui::Window::new(t("Settings"))
            .open(&mut open)
            .collapsible(false)
            .show(ctx, |ui| {
                ui.label(t("ID/Relay Server"));
                egui::Grid::new("servers").num_columns(2).show(ui, |ui| {
                    ui.label(t("ID Server"));
                    ui.text_edit_singleline(&mut self.id_server);
                    ui.end_row();
                    ui.label(t("Relay Server"));
                    ui.text_edit_singleline(&mut self.relay_server);
                    ui.end_row();
                    ui.label(t("API Server"));
                    ui.text_edit_singleline(&mut self.api_server);
                    ui.end_row();
                    ui.label(t("Key"));
                    ui.text_edit_singleline(&mut self.key);
                    ui.end_row();
                });
                if ui.button(t("Apply")).clicked() {
                    set_option(
                        "custom-rendezvous-server".to_owned(),
                        self.id_server.trim().to_owned(),
                    );
                    set_option("relay-server".to_owned(), self.relay_server.trim().to_owned());
                    set_option("api-server".to_owned(), self.api_server.trim().to_owned());
                    set_option("key".to_owned(), self.key.trim().to_owned());
                    self.settings_msg = t("Successful");
                }
                ui.separator();
                ui.label(t("Set permanent password"));
                ui.horizontal(|ui| {
                    ui.add(egui::TextEdit::singleline(&mut self.permanent_password).password(true));
                    if ui.button(t("OK")).clicked() {
                        set_permanent_password(std::mem::take(&mut self.permanent_password));
                        self.settings_msg = t("Successful");
                    }
                });
                if !self.settings_msg.is_empty() {
                    ui.label(&self.settings_msg);
                }
            });
        self.show_settings = open;
    }
}

impl eframe::App for MainWindow {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        egui::TopBottomPanel::top("menu").show(ctx, |ui| {
            ui.horizontal(|ui| {
                ui.strong(crate::get_app_name());
                ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                    if ui.button(t("Settings")).clicked() {
                        self.settings_msg.clear();
                        self.show_settings = !self.show_settings;
                    }
                });
            });
        });
        egui::CentralPanel::default().show(ctx, |ui| {
            self.own_desktop(ui);
            ui.separator();
            self.control_remote(ui);
        });
        if self.show_settings {
            self.settings(ctx);
        }
    }
}
