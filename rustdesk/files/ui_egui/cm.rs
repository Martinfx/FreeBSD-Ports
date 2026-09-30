use super::{run_window, t};
use crate::ui_cm_interface::{self, start_ipc, Client, ConnectionManager, InvokeUiCM};
use eframe::egui;
use hbb_common::log;
use std::{
    collections::HashMap,
    sync::{
        atomic::{AtomicBool, Ordering},
        Arc, Mutex,
    },
};

#[derive(Clone)]
struct CmClient {
    id: i32,
    peer_id: String,
    name: String,
    kind: String,
    authorized: bool,
    messages: Vec<String>,
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
        let kind = if client.is_file_transfer {
            t("File Transfer")
        } else if client.is_view_camera {
            t("View Camera")
        } else if client.is_terminal {
            t("Terminal")
        } else if !client.port_forward.is_empty() {
            format!("{} {}", t("Port Forward"), client.port_forward)
        } else {
            t("Remote Desktop")
        };
        let item = CmClient {
            id: client.id,
            peer_id: client.peer_id.clone(),
            name: client.name.clone(),
            kind,
            authorized: client.authorized,
            messages: Vec::new(),
        };
        {
            let mut clients = self.clients.lock().unwrap();
            if let Some(c) = clients.iter_mut().find(|c| c.id == item.id) {
                c.authorized = item.authorized;
            } else {
                clients.push(item);
            }
        }
        self.had_clients.store(true, Ordering::SeqCst);
        self.repaint();
    }

    fn remove_connection(&self, id: i32, _close: bool) {
        self.clients.lock().unwrap().retain(|c| c.id != id);
        self.repaint();
    }

    fn new_message(&self, id: i32, text: String) {
        if let Some(c) = self.clients.lock().unwrap().iter_mut().find(|c| c.id == id) {
            c.messages.push(text);
        }
        self.repaint();
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
    chat_input: HashMap<i32, String>,
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
    run_window(&title, [380., 440.], move |ctx| {
        *handler.ctx.lock().unwrap() = Some(ctx.clone());
        CmWindow {
            handler,
            chat_input: HashMap::new(),
        }
    });
}

impl eframe::App for CmWindow {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        let clients = self.handler.clients.lock().unwrap().clone();
        // The server starts a new connection manager when needed.
        if clients.is_empty() && self.handler.had_clients.load(Ordering::SeqCst) {
            ctx.send_viewport_cmd(egui::ViewportCommand::Close);
        }
        egui::CentralPanel::default().show(ctx, |ui| {
            if clients.is_empty() {
                ui.label(t("Waiting"));
                return;
            }
            egui::ScrollArea::vertical().show(ui, |ui| {
                for c in clients.iter() {
                    ui.group(|ui| {
                        ui.horizontal(|ui| {
                            ui.strong(&c.name);
                            ui.monospace(&c.peer_id);
                        });
                        ui.label(&c.kind);
                        ui.horizontal(|ui| {
                            if !c.authorized {
                                ui.colored_label(egui::Color32::YELLOW, t("Waiting"));
                                if ui.button(t("Accept")).clicked() {
                                    ui_cm_interface::authorize(c.id);
                                }
                                if ui.button(t("Dismiss")).clicked() {
                                    ui_cm_interface::close(c.id);
                                }
                            } else {
                                ui.colored_label(egui::Color32::GREEN, t("Connected"));
                                if ui.button(t("Disconnect")).clicked() {
                                    ui_cm_interface::close(c.id);
                                }
                            }
                        });
                        for m in c.messages.iter() {
                            ui.label(format!("{}: {}", c.name, m));
                        }
                        if c.authorized {
                            let input = self.chat_input.entry(c.id).or_default();
                            ui.horizontal(|ui| {
                                let edit = ui.text_edit_singleline(input);
                                let enter = edit.lost_focus()
                                    && ui.input(|i| i.key_pressed(egui::Key::Enter));
                                if (ui.button(t("Send")).clicked() || enter) && !input.is_empty()
                                {
                                    ui_cm_interface::send_chat(c.id, std::mem::take(input));
                                }
                            });
                        }
                    });
                }
            });
        });
    }
}
