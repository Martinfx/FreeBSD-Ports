//! Main window, laid out like the Flutter desktop home page: the gray
//! "Your Desktop" pane on the left, "Control Remote Desktop" with the peer
//! tabs on the right, the status bar at the bottom and a Settings tab.

use super::{
    run_window,
    svg::{platform_icon, IconCache},
    t, theme,
    widgets::{self, format_id, glyph_button, paint_glyph, str2color, Glyph, Tab, TitleBarEvent},
};
use crate::ui_interface::{
    get_connect_status, get_fav, get_lan_peers, get_option, new_remote, remove_discovered,
    set_option, set_permanent_password_with_result, store_fav, temporary_password,
    update_temporary_password,
};
use eframe::egui::{
    self, pos2, vec2, Align, Align2, Color32, CornerRadius, FontId, Layout, Margin, Rect,
    RichText, Sense, Stroke, StrokeKind, Ui,
};
use hbb_common::config::{LocalConfig, PeerConfig};
use std::{
    collections::HashMap,
    sync::{Arc, Mutex},
    time::{Duration, Instant},
};

#[derive(Default, Clone)]
struct Status {
    id: String,
    password: String,
    status_num: i32,
    public_server: bool,
}

#[derive(Clone)]
struct Peer {
    id: String,
    alias: String,
    username: String,
    hostname: String,
    platform: String,
}

impl Peer {
    fn user_host(&self) -> String {
        if self.username.is_empty() && self.hostname.is_empty() {
            String::new()
        } else {
            format!("{}@{}", self.username, self.hostname)
        }
    }

    fn title(&self) -> String {
        if self.alias.is_empty() {
            format_id(&self.id)
        } else {
            self.alias.clone()
        }
    }

    fn from_config(id: String, p: &PeerConfig) -> Self {
        Self {
            alias: p.options.get("alias").cloned().unwrap_or_default(),
            username: p.info.username.clone(),
            hostname: p.info.hostname.clone(),
            platform: p.info.platform.clone(),
            id,
        }
    }
}

#[derive(Clone, Copy, PartialEq)]
enum PeerTab {
    Recent,
    Favorites,
    Discovered,
    AddressBook,
}

const PEER_TABS: [(PeerTab, &str); 4] = [
    (PeerTab::Recent, "Recent sessions"),
    (PeerTab::Favorites, "Favorites"),
    (PeerTab::Discovered, "Discovered"),
    (PeerTab::AddressBook, "Address book"),
];

#[derive(Clone, Copy, PartialEq)]
enum ViewType {
    Grid,
    Tile,
    List,
}

#[derive(Clone, Copy, PartialEq)]
enum SortBy {
    Id,
    Host,
    Username,
}

#[derive(Clone, Copy, PartialEq)]
enum SettingsPage {
    Security,
    Network,
    About,
}

struct PasswordDialog {
    password: String,
    confirm: String,
    error: String,
}

struct MainWindow {
    icons: IconCache,
    status: Arc<Mutex<Status>>,
    settings_open: bool,
    on_settings: bool,
    settings_page: SettingsPage,
    remote_id: String,
    peer_tab: PeerTab,
    view: ViewType,
    sort: SortBy,
    search_open: bool,
    search: String,
    peers: Vec<Peer>,
    favs: Vec<String>,
    last_load: Instant,
    online: Arc<Mutex<HashMap<String, bool>>>,
    last_online_query: Option<Instant>,
    id_server: String,
    relay_server: String,
    api_server: String,
    key: String,
    network_msg: String,
    password_dialog: Option<PasswordDialog>,
    toast: Option<(String, Instant)>,
}

pub fn run() {
    // Same helper threads as the Sciter main window.
    std::thread::spawn(crate::ui_interface::check_zombie);
    std::thread::spawn(crate::ipc::start_pa);
    // core_main() already started the server in this process if none runs.
    // Keep id/password/status in sync with the server.
    crate::ui_interface::start_option_status_sync();

    run_window(&crate::get_app_name(), [800., 600.], [640., 480.], |ctx| {
        let status = Arc::new(Mutex::new(Status::default()));
        start_status_thread(status.clone(), ctx.clone());
        let peer_tab = match LocalConfig::get_option("peer-tab-index").as_str() {
            "1" => PeerTab::Favorites,
            "2" => PeerTab::Discovered,
            "3" => PeerTab::AddressBook,
            _ => PeerTab::Recent,
        };
        let view = match LocalConfig::get_option("peer-card-ui-type").as_str() {
            "1" => ViewType::Tile,
            "2" => ViewType::List,
            _ => ViewType::Grid,
        };
        let mut w = MainWindow {
            icons: IconCache::default(),
            status,
            settings_open: false,
            on_settings: false,
            settings_page: SettingsPage::Security,
            remote_id: format_id(&LocalConfig::get_remote_id()),
            peer_tab,
            view,
            sort: SortBy::Id,
            search_open: false,
            search: String::new(),
            peers: Vec::new(),
            favs: Vec::new(),
            last_load: Instant::now(),
            online: Default::default(),
            last_online_query: None,
            id_server: get_option("custom-rendezvous-server"),
            relay_server: get_option("relay-server"),
            api_server: get_option("api-server"),
            key: get_option("key"),
            network_msg: String::new(),
            password_dialog: None,
            toast: None,
        };
        w.load_peers();
        w
    });
}

// IPC calls may block, keep them out of the UI thread.
fn start_status_thread(status: Arc<Mutex<Status>>, ctx: egui::Context) {
    std::thread::spawn(move || loop {
        let new = Status {
            id: crate::ipc::get_id(),
            password: temporary_password(),
            status_num: get_connect_status().status_num,
            public_server: crate::common::using_public_server(),
        };
        let changed = {
            let mut lock = status.lock().unwrap();
            let changed = lock.id != new.id
                || lock.password != new.password
                || lock.status_num != new.status_num
                || lock.public_server != new.public_server;
            *lock = new;
            changed
        };
        if changed {
            ctx.request_repaint();
        }
        std::thread::sleep(Duration::from_secs(1));
    });
}

impl MainWindow {
    fn connect(&mut self, id: &str) {
        let id = id.replace(' ', "");
        if id.is_empty() {
            return;
        }
        LocalConfig::set_remote_id(&id);
        new_remote(id, "connect".to_owned(), false);
    }

    fn load_peers(&mut self) {
        self.last_load = Instant::now();
        self.favs = get_fav();
        self.peers = match self.peer_tab {
            PeerTab::Recent => PeerConfig::peers(None)
                .into_iter()
                .map(|(id, _, p)| Peer::from_config(id, &p))
                .collect(),
            PeerTab::Favorites => self
                .favs
                .iter()
                .map(|id| Peer::from_config(id.clone(), &PeerConfig::load(id)))
                .collect(),
            PeerTab::Discovered => get_lan_peers()
                .into_iter()
                .map(|m| Peer {
                    id: m.get("id").cloned().unwrap_or_default(),
                    alias: String::new(),
                    username: m.get("username").cloned().unwrap_or_default(),
                    hostname: m.get("hostname").cloned().unwrap_or_default(),
                    platform: m.get("platform").cloned().unwrap_or_default(),
                })
                .collect(),
            PeerTab::AddressBook => Vec::new(),
        };
        if self.peer_tab != PeerTab::Recent {
            match self.sort {
                SortBy::Id => self.peers.sort_by(|a, b| a.id.cmp(&b.id)),
                SortBy::Host => self.peers.sort_by(|a, b| a.hostname.cmp(&b.hostname)),
                SortBy::Username => self.peers.sort_by(|a, b| a.username.cmp(&b.username)),
            }
        }
    }

    // Online states of the listed peers, queried like the Flutter UI does.
    fn query_onlines(&mut self, ctx: &egui::Context) {
        if self
            .last_online_query
            .map(|t| t.elapsed() < Duration::from_secs(30))
            .unwrap_or(false)
            || self.peers.is_empty()
        {
            return;
        }
        self.last_online_query = Some(Instant::now());
        let ids: Vec<String> = self.peers.iter().map(|p| p.id.clone()).collect();
        let online = self.online.clone();
        let ctx = ctx.clone();
        std::thread::spawn(move || {
            let Ok(rt) = hbb_common::tokio::runtime::Runtime::new() else {
                return;
            };
            rt.block_on(crate::client::peer_online::query_online_states(
                ids,
                move |onlines, offlines| {
                    let mut lock = online.lock().unwrap();
                    for id in onlines {
                        lock.insert(id, true);
                    }
                    for id in offlines {
                        lock.insert(id, false);
                    }
                    ctx.request_repaint();
                },
            ));
        });
    }

    fn toast(&mut self, text: String) {
        self.toast = Some((text, Instant::now()));
    }

    // ---- left pane -------------------------------------------------------

    fn left_pane(&mut self, ui: &mut Ui) {
        let status = self.status.lock().unwrap().clone();
        let full = ui.max_rect();
        let x0 = full.left();
        ui.add_space(16.);
        ui.horizontal(|ui| {
            ui.add_space(20.);
            ui.vertical(|ui| {
                ui.set_width(200. - 20. - 16.);
                ui.label(RichText::new(t("Your Desktop")).size(19.));
                ui.add_space(10.);
                ui.label(RichText::new(t("desk_tip")).size(12.));
            });
        });
        ui.add_space(5.);

        // ID board
        let (board, _) = ui.allocate_exact_size(vec2(full.width(), 57.), Sense::hover());
        let left = x0 + 20.;
        let right = full.right() - 11.;
        ui.painter().rect_filled(
            Rect::from_min_max(pos2(left, board.top() + 5.), pos2(left + 2., board.bottom())),
            CornerRadius::ZERO,
            theme::ACCENT,
        );
        let tx = left + 9.;
        ui.painter().text(
            pos2(tx, board.top() + 5.),
            Align2::LEFT_TOP,
            t("ID"),
            FontId::proportional(14.),
            theme::TEXT_50,
        );
        let more = Rect::from_center_size(pos2(right - 15., board.top() + 12.5), vec2(30., 30.));
        let more_resp = ui.interact(more, ui.id().with("id_more"), Sense::click());
        ui.painter().circle_filled(
            more.center(),
            15.,
            if more_resp.hovered() { Color32::WHITE } else { theme::GRAY_BG },
        );
        paint_glyph(
            ui,
            &mut self.icons,
            Rect::from_center_size(more.center(), vec2(20., 20.)),
            Glyph::MoreVert,
            if more_resp.hovered() { theme::TEXT } else { theme::TEXT_50 },
        );
        if more_resp.on_hover_text(t("Settings")).clicked() {
            self.open_settings();
        }
        let id_rect = Rect::from_min_max(pos2(tx, board.top() + 25.), pos2(right, board.bottom()));
        ui.painter().text(
            pos2(tx, id_rect.center().y + 2.),
            Align2::LEFT_CENTER,
            format_id(&status.id),
            FontId::proportional(22.),
            theme::TEXT,
        );
        let id_resp = ui.interact(id_rect, ui.id().with("id_text"), Sense::click());
        if id_resp.double_clicked() {
            ui.ctx().copy_text(status.id.clone());
            self.toast(t("Copied"));
        }

        // One-time password board
        ui.add_space(13.);
        let (board, _) = ui.allocate_exact_size(vec2(full.width(), 52.), Sense::hover());
        let right = full.right() - 16.;
        ui.painter().rect_filled(
            Rect::from_min_max(pos2(left, board.top()), pos2(left + 2., board.bottom())),
            CornerRadius::ZERO,
            theme::ACCENT,
        );
        ui.painter().text(
            pos2(tx, board.top()),
            Align2::LEFT_TOP,
            t("One-time Password"),
            FontId::proportional(14.),
            theme::TEXT_50,
        );
        let pw_y = board.top() + 34.;
        let pw = if status.password.is_empty() { "-".to_owned() } else { status.password.clone() };
        ui.painter().text(
            pos2(tx, pw_y),
            Align2::LEFT_CENTER,
            pw,
            FontId::proportional(15.),
            theme::TEXT,
        );
        let icon_color = |hovered: bool| {
            if hovered {
                theme::TEXT
            } else {
                Color32::from_rgb(0xDD, 0xDD, 0xDD)
            }
        };
        let edit = Rect::from_center_size(pos2(right - 8. - 11., pw_y), vec2(22., 22.));
        let refresh = Rect::from_center_size(pos2(edit.left() - 8. - 11., pw_y), vec2(22., 22.));
        let r = ui.interact(refresh, ui.id().with("pw_refresh"), Sense::click());
        paint_glyph(ui, &mut self.icons, refresh, Glyph::Refresh, icon_color(r.hovered()));
        if r.on_hover_text(t("Refresh Password")).clicked() {
            update_temporary_password();
        }
        let e = ui.interact(edit, ui.id().with("pw_edit"), Sense::click());
        paint_glyph(ui, &mut self.icons, edit, Glyph::Edit, icon_color(e.hovered()));
        if e.on_hover_text(t("Change Password")).clicked() {
            self.password_dialog = Some(PasswordDialog {
                password: String::new(),
                confirm: String::new(),
                error: String::new(),
            });
        }
    }

    // ---- right pane ------------------------------------------------------

    fn connect_card(&mut self, ui: &mut Ui) {
        egui::Frame::NONE
            .stroke(Stroke::new(1., theme::GRAY_BG))
            .corner_radius(CornerRadius::same(13))
            .inner_margin(Margin { left: 20, right: 20, top: 24, bottom: 22 })
            .show(ui, |ui| {
                ui.set_width(320.);
                ui.horizontal(|ui| {
                    ui.label(RichText::new(t("Control Remote Desktop")).size(19.));
                    ui.add_space(4.);
                    let (r, resp) = ui.allocate_exact_size(vec2(16., 16.), Sense::hover());
                    paint_glyph(ui, &mut self.icons, r, Glyph::Help, theme::TEXT_50);
                    resp.on_hover_text(t("id_input_tip"));
                });
                ui.add_space(15.);
                let edit = ui.add(
                    egui::TextEdit::singleline(&mut self.remote_id)
                        .font(FontId::proportional(22.))
                        .hint_text(RichText::new(t("Enter Remote ID")).color(theme::HINT))
                        .margin(Margin::symmetric(15, 13))
                        .desired_width(f32::INFINITY),
                );
                let enter = edit.lost_focus() && ui.input(|i| i.key_pressed(egui::Key::Enter));
                if edit.changed() {
                    self.remote_id = format_id(&self.remote_id);
                }
                ui.add_space(13.);
                let row = vec2(ui.available_width(), 28.);
                ui.allocate_ui_with_layout(row, Layout::right_to_left(Align::Center), |ui| {
                    ui.spacing_mut().item_spacing.x = 8.;
                    // The "more" box: other connection types.
                    let (r, resp) = ui.allocate_exact_size(vec2(28., 28.), Sense::click());
                    ui.painter().rect_stroke(
                        r,
                        CornerRadius::same(8),
                        Stroke::new(1., theme::DIVIDER),
                        StrokeKind::Inside,
                    );
                    ui.painter().text(
                        r.center(),
                        Align2::CENTER_CENTER,
                        widgets::ICON_MORE,
                        widgets::icon_font("More", 14.),
                        theme::TEXT,
                    );
                    let popup = ui.id().with("connect_more");
                    if resp.clicked() {
                        ui.memory_mut(|m| m.toggle_popup(popup));
                    }
                    egui::popup::popup_below_widget(
                        ui,
                        popup,
                        &resp,
                        egui::PopupCloseBehavior::CloseOnClick,
                        |ui| {
                            ui.set_min_width(160.);
                            for name in ["Transfer file", "View camera", "Terminal", "TCP tunneling"] {
                                let mut label = t(name);
                                if name == "Terminal" {
                                    label += " (beta)";
                                }
                                ui.add_enabled(false, egui::Button::new(label).frame(false))
                                    .on_disabled_hover_text("Not available in this build yet");
                            }
                        },
                    );
                    if widgets::primary_button(ui, &t("Connect"), theme::ACCENT, 0.).clicked() || enter
                    {
                        let id = self.remote_id.clone();
                        self.connect(&id);
                    }
                });
            });
    }

    fn peer_tab_header(&mut self, ui: &mut Ui) {
        let (row, _) = ui.allocate_exact_size(vec2(ui.available_width(), 32.), Sense::hover());
        let mut child = ui.new_child(egui::UiBuilder::new().max_rect(row.with_max_x(row.right() - 12.)));
        let ui = &mut child;
        ui.horizontal_centered(|ui| {
            ui.spacing_mut().item_spacing.x = 8.;
            for (tab, name) in PEER_TABS {
                let sel = self.peer_tab == tab;
                let (r, resp) = ui.allocate_exact_size(vec2(32., 32.), Sense::click());
                if resp.hovered() && !sel {
                    ui.painter().rect_filled(r, CornerRadius::same(6), theme::GRAY_BG);
                }
                let color = if sel { Color32::BLACK } else { theme::TAB_UNSELECTED };
                let ir = Rect::from_center_size(r.center(), vec2(24., 24.));
                match tab {
                    PeerTab::Recent => paint_glyph(ui, &mut self.icons, ir, Glyph::Clock, color),
                    PeerTab::Favorites => paint_glyph(ui, &mut self.icons, ir, Glyph::Star, color),
                    PeerTab::Discovered => paint_glyph(ui, &mut self.icons, ir, Glyph::Explore, color),
                    PeerTab::AddressBook => {
                        ui.painter().text(
                            r.center(),
                            Align2::CENTER_CENTER,
                            widgets::ICON_ADDRESS_BOOK,
                            widgets::icon_font("AddressBook", 22.),
                            color,
                        );
                    }
                }
                if sel {
                    ui.painter().line_segment(
                        [pos2(r.left() + 4., r.bottom() - 1.), pos2(r.right() - 4., r.bottom() - 1.)],
                        Stroke::new(2., color),
                    );
                }
                if resp.on_hover_text(t(name)).clicked() && !sel {
                    self.peer_tab = tab;
                    let idx = PEER_TABS.iter().position(|(x, _)| *x == tab).unwrap_or(0);
                    LocalConfig::set_option("peer-tab-index".to_owned(), idx.to_string());
                    if tab == PeerTab::Discovered {
                        std::thread::spawn(|| {
                            let _ = crate::lan::discover();
                        });
                    }
                    self.last_online_query = None;
                    self.load_peers();
                }
            }
            widgets::button_row(ui, |ui| {
                ui.spacing_mut().item_spacing.x = 2.;
                if self.peer_tab != PeerTab::Recent {
                    let resp = glyph_button(ui, &mut self.icons, Glyph::Sort, 18., theme::TEXT, "");
                    let popup = ui.id().with("sort_menu");
                    if resp.clicked() {
                        ui.memory_mut(|m| m.toggle_popup(popup));
                    }
                    egui::popup::popup_below_widget(ui, popup, &resp, egui::PopupCloseBehavior::CloseOnClick, |ui| {
                        ui.set_min_width(140.);
                        for (s, name) in [(SortBy::Id, "Remote ID"), (SortBy::Host, "Remote Host"), (SortBy::Username, "Username")] {
                            if ui.radio(self.sort == s, t(name)).clicked() {
                                self.sort = s;
                                self.load_peers();
                            }
                        }
                    });
                }
                let view_glyph = match self.view {
                    ViewType::Grid => Glyph::Grid,
                    ViewType::Tile => Glyph::Grid,
                    ViewType::List => Glyph::List,
                };
                let resp = glyph_button(ui, &mut self.icons, view_glyph, 18., theme::TEXT, "");
                let popup = ui.id().with("view_menu");
                if resp.clicked() {
                    ui.memory_mut(|m| m.toggle_popup(popup));
                }
                egui::popup::popup_below_widget(ui, popup, &resp, egui::PopupCloseBehavior::CloseOnClick, |ui| {
                    ui.set_min_width(140.);
                    ui.label(RichText::new(t("Change view")).color(theme::TEXT_50));
                    for (v, name, key) in [(ViewType::Grid, "Big tiles", "0"), (ViewType::Tile, "Small tiles", "1"), (ViewType::List, "List", "2")] {
                        if ui.radio(self.view == v, t(name)).clicked() {
                            self.view = v;
                            LocalConfig::set_option("peer-card-ui-type".to_owned(), key.to_owned());
                        }
                    }
                });
                ui.add_space(8.);
                if self.search_open {
                    egui::Frame::NONE
                        .fill(theme::GRAY_BG)
                        .corner_radius(CornerRadius::same(6))
                        .inner_margin(Margin::symmetric(4, 2))
                        .show(ui, |ui| {
                            ui.set_width(140.);
                            ui.horizontal(|ui| {
                                ui.spacing_mut().item_spacing.x = 2.;
                                ui.label(
                                    RichText::new(widgets::ICON_SEARCH.to_string())
                                        .font(widgets::icon_font("PeerSearchbar", 16.))
                                        .color(theme::HINT),
                                );
                                let edit = ui.add(
                                    egui::TextEdit::singleline(&mut self.search)
                                        .frame(false)
                                        .hint_text(RichText::new(t("Search ID")).color(theme::HINT))
                                        .desired_width(96.),
                                );
                                if ui.add(egui::Button::new("✕").frame(false).small()).clicked()
                                    || (edit.lost_focus() && self.search.is_empty())
                                {
                                    self.search.clear();
                                    self.search_open = false;
                                }
                            });
                        });
                } else {
                    let (r, resp) = ui.allocate_exact_size(vec2(32., 32.), Sense::click());
                    ui.painter().text(
                        r.center(),
                        Align2::CENTER_CENTER,
                        widgets::ICON_SEARCH,
                        widgets::icon_font("PeerSearchbar", 22.),
                        theme::HINT,
                    );
                    if resp.clicked() {
                        self.search_open = true;
                    }
                }
            });
        });
    }

    fn visible_peers(&self) -> Vec<Peer> {
        let q = self.search.trim().to_lowercase().replace(' ', "");
        self.peers
            .iter()
            .filter(|p| {
                q.is_empty()
                    || p.id.to_lowercase().contains(&q)
                    || p.alias.to_lowercase().contains(&q)
                    || p.hostname.to_lowercase().contains(&q)
                    || p.username.to_lowercase().contains(&q)
            })
            .cloned()
            .collect()
    }

    fn peers_view(&mut self, ui: &mut Ui) {
        let peers = self.visible_peers();
        if peers.is_empty() {
            ui.add_space(40.);
            ui.vertical_centered(|ui| {
                let (r, _) = ui.allocate_exact_size(vec2(40., 40.), Sense::hover());
                paint_glyph(ui, &mut self.icons, r, Glyph::Sad, theme::TEXT);
                ui.add_space(10.);
                let tip = match self.peer_tab {
                    PeerTab::Recent => "empty_recent_tip",
                    PeerTab::Favorites => "empty_favorite_tip",
                    PeerTab::Discovered => "empty_lan_tip",
                    PeerTab::AddressBook => "empty_address_book_tip",
                };
                ui.label(t(tip));
            });
            return;
        }
        let online = self.online.lock().unwrap().clone();
        egui::ScrollArea::vertical()
            .auto_shrink([false, false])
            .show(ui, |ui| {
                ui.add_space(12.);
                if self.view == ViewType::List {
                    ui.spacing_mut().item_spacing.y = 6.;
                    for p in peers.iter() {
                        let w = ui.available_width() - 12.;
                        self.peer_row(ui, p, online.get(&p.id).copied(), vec2(w, 45.));
                    }
                } else {
                    ui.spacing_mut().item_spacing = vec2(12., 6.);
                    ui.horizontal_wrapped(|ui| {
                        for p in peers.iter() {
                            if self.view == ViewType::Grid {
                                self.peer_card(ui, p, online.get(&p.id).copied());
                            } else {
                                self.peer_row(ui, p, online.get(&p.id).copied(), vec2(220., 42.));
                            }
                        }
                    });
                }
                ui.add_space(12.);
            });
    }

    fn online_color(online: Option<bool>) -> Color32 {
        if online == Some(true) {
            theme::ONLINE
        } else {
            theme::WARN
        }
    }

    fn more_button(&mut self, ui: &mut Ui, center: egui::Pos2, peer: &Peer) {
        let r = Rect::from_center_size(center, vec2(28., 28.));
        let resp = ui.interact(r, ui.id().with(("peer_more", &peer.id)), Sense::click());
        ui.painter().circle_filled(
            center,
            14.,
            if resp.hovered() { Color32::WHITE } else { theme::GRAY_BG },
        );
        paint_glyph(
            ui,
            &mut self.icons,
            Rect::from_center_size(center, vec2(18., 18.)),
            Glyph::MoreVert,
            if resp.hovered() { theme::TEXT } else { theme::TEXT_50 },
        );
        let popup = ui.id().with(("peer_menu", &peer.id));
        if resp.clicked() {
            ui.memory_mut(|m| m.toggle_popup(popup));
        }
        egui::popup::popup_below_widget(ui, popup, &resp, egui::PopupCloseBehavior::CloseOnClick, |ui| {
            ui.set_min_width(170.);
            if ui.add(egui::Button::new(t("Connect")).frame(false)).clicked() {
                self.connect(&peer.id);
            }
            ui.add_enabled(false, egui::Button::new(t("Transfer file")).frame(false))
                .on_disabled_hover_text("Not available in this build yet");
            ui.separator();
            let is_fav = self.favs.contains(&peer.id);
            let label = if is_fav { "Remove from Favorites" } else { "Add to Favorites" };
            if ui.add(egui::Button::new(t(label)).frame(false)).clicked() {
                let mut favs = self.favs.clone();
                if is_fav {
                    favs.retain(|x| x != &peer.id);
                } else {
                    favs.push(peer.id.clone());
                }
                store_fav(favs);
                self.load_peers();
            }
            let removable = matches!(self.peer_tab, PeerTab::Recent | PeerTab::Discovered);
            if removable
                && ui
                    .add(egui::Button::new(RichText::new(t("Delete")).color(theme::RED)).frame(false))
                    .clicked()
            {
                if self.peer_tab == PeerTab::Recent {
                    PeerConfig::remove(&peer.id);
                } else {
                    remove_discovered(peer.id.clone());
                }
                self.load_peers();
            }
        });
    }

    // "Big tiles" card, 220x140.
    fn peer_card(&mut self, ui: &mut Ui, peer: &Peer, online: Option<bool>) {
        let (rect, resp) = ui.allocate_exact_size(vec2(220., 140.), Sense::click());
        let color = str2color(&format!("{}{}", peer.id, peer.platform), 0x7F);
        let strip_h = 44.;
        let top = Rect::from_min_max(rect.min, pos2(rect.right(), rect.bottom() - strip_h));
        let bottom = Rect::from_min_max(pos2(rect.left(), top.bottom()), rect.max);
        let p = ui.painter();
        let top_r = CornerRadius { nw: 14, ne: 14, sw: 0, se: 0 };
        p.rect_filled(top, top_r, Color32::WHITE);
        p.rect_filled(top, top_r, color);
        p.rect_filled(bottom, CornerRadius { nw: 0, ne: 0, sw: 14, se: 14 }, theme::GRAY_BG);
        if let Some(icon) = platform_icon(&peer.platform) {
            let ir = Rect::from_center_size(pos2(top.center().x, top.top() + 4. + 30.), vec2(48., 48.));
            self.icons.paint(ui, ir, icon, Some(Color32::WHITE));
        }
        ui.painter().text(
            pos2(top.center().x, top.bottom() - 12.),
            Align2::CENTER_CENTER,
            peer.user_host(),
            FontId::proportional(12.),
            Color32::from_white_alpha(0xB3),
        );
        let cy = bottom.center().y;
        ui.painter().circle_filled(pos2(bottom.left() + 15., cy), 3., Self::online_color(online));
        let title = ui.painter().layout(
            peer.title(),
            FontId::proportional(14.),
            theme::TEXT,
            220. - 12. - 14. - 40.,
        );
        ui.painter().galley(pos2(bottom.left() + 26., cy - title.size().y / 2.), title, theme::TEXT);
        if resp.hovered() {
            ui.painter().rect_stroke(
                rect.expand(1.),
                CornerRadius::same(16),
                Stroke::new(2., theme::PRIMARY),
                StrokeKind::Outside,
            );
        }
        if resp.double_clicked() {
            self.connect(&peer.id);
        }
        self.more_button(ui, pos2(bottom.right() - 12. - 14., cy), peer);
    }

    // "Small tiles" (220x42) and "List" rows.
    fn peer_row(&mut self, ui: &mut Ui, peer: &Peer, online: Option<bool>, size: egui::Vec2) {
        let (rect, resp) = ui.allocate_exact_size(size, Sense::click());
        let color = str2color(&format!("{}{}", peer.id, peer.platform), 0x7F);
        let left = Rect::from_min_max(rect.min, pos2(rect.left() + 42., rect.bottom()));
        let right = Rect::from_min_max(pos2(left.right(), rect.top()), rect.max);
        let p = ui.painter();
        let lr = CornerRadius { nw: 5, sw: 5, ne: 0, se: 0 };
        p.rect_filled(left, lr, Color32::WHITE);
        p.rect_filled(left, lr, color);
        p.rect_filled(right, CornerRadius { nw: 0, sw: 0, ne: 5, se: 5 }, theme::GRAY_BG);
        if let Some(icon) = platform_icon(&peer.platform) {
            self.icons.paint(ui, left.shrink(8.), icon, Some(Color32::WHITE));
        }
        let x = right.left() + 10.;
        let y1 = rect.top() + 3. + 9.;
        ui.painter().circle_filled(pos2(x + 3., y1), 3., Self::online_color(online));
        ui.painter().text(
            pos2(x + 14., y1),
            Align2::LEFT_CENTER,
            peer.title(),
            FontId::proportional(14.),
            theme::TEXT,
        );
        ui.painter().text(
            pos2(x, rect.bottom() - 10.),
            Align2::LEFT_CENTER,
            peer.user_host(),
            FontId::proportional(11.),
            Color32::from_black_alpha(0x99),
        );
        if resp.hovered() {
            ui.painter().rect_stroke(
                rect.expand(1.),
                CornerRadius::same(5),
                Stroke::new(2., theme::PRIMARY),
                StrokeKind::Outside,
            );
        }
        if resp.double_clicked() {
            self.connect(&peer.id);
        }
        self.more_button(ui, pos2(rect.right() - 20., rect.center().y), peer);
    }

    fn status_bar(&mut self, ui: &mut Ui) {
        let status = self.status.lock().unwrap().clone();
        ui.horizontal_centered(|ui| {
            ui.add_space(14.);
            let (color, text) = match status.status_num {
                -1 => (theme::NOT_READY, t("not_ready_status")),
                0 => (theme::WARN, t("connecting_status")),
                _ => (theme::READY, t("Ready")),
            };
            let (r, _) = ui.allocate_exact_size(vec2(8., 8.), Sense::hover());
            ui.painter().circle_filled(r.center(), 4., color);
            ui.add_space(14.);
            ui.spacing_mut().item_spacing.x = 0.;
            ui.label(RichText::new(text).size(14.));
            if status.status_num > 0 && status.public_server {
                ui.label(RichText::new(", ").size(14.));
                let link = ui.add(
                    egui::Label::new(RichText::new(t("setup_server_tip")).size(14.).underline())
                        .sense(Sense::click()),
                );
                if link.on_hover_cursor(egui::CursorIcon::PointingHand).clicked() {
                    widgets::open_url("https://rustdesk.com/pricing");
                }
            }
        });
    }

    fn home(&mut self, ctx: &egui::Context) {
        egui::SidePanel::left("left_pane")
            .exact_width(200.)
            .resizable(false)
            .frame(egui::Frame::NONE.fill(theme::GRAY_BG))
            .show(ctx, |ui| {
                egui::ScrollArea::vertical().show(ui, |ui| self.left_pane(ui));
            });
        egui::TopBottomPanel::bottom("status_bar")
            .exact_height(42.)
            .frame(egui::Frame::NONE.fill(Color32::WHITE))
            .show(ctx, |ui| self.status_bar(ui));
        egui::CentralPanel::default()
            .frame(egui::Frame::NONE.fill(Color32::WHITE).inner_margin(Margin { left: 12, ..Default::default() }))
            .show(ctx, |ui| {
                ui.add_space(22.);
                self.connect_card(ui);
                ui.add_space(12.);
                let (r, _) = ui.allocate_exact_size(vec2(ui.available_width(), 16.), Sense::hover());
                ui.painter().line_segment(
                    [pos2(r.left(), r.center().y), pos2(r.right() - 12., r.center().y)],
                    Stroke::new(1., theme::DIVIDER),
                );
                self.peer_tab_header(ui);
                self.peers_view(ui);
            });
    }

    // ---- settings --------------------------------------------------------

    fn open_settings(&mut self) {
        self.settings_open = true;
        self.on_settings = true;
    }

    fn settings(&mut self, ctx: &egui::Context) {
        egui::SidePanel::left("settings_nav")
            .exact_width(200.)
            .resizable(false)
            .frame(egui::Frame::NONE.fill(theme::GRAY_BG).inner_margin(Margin::symmetric(0, 16)))
            .show(ctx, |ui| {
                for (page, name) in [
                    (SettingsPage::Security, "Security"),
                    (SettingsPage::Network, "Network"),
                    (SettingsPage::About, "About"),
                ] {
                    let sel = self.settings_page == page;
                    let (r, resp) = ui.allocate_exact_size(vec2(200., 38.), Sense::click());
                    if sel {
                        ui.painter().rect_filled(r, CornerRadius::ZERO, Color32::WHITE);
                        ui.painter().rect_filled(
                            Rect::from_min_max(r.min, pos2(r.left() + 3., r.bottom())),
                            CornerRadius::ZERO,
                            theme::ACCENT,
                        );
                    } else if resp.hovered() {
                        ui.painter().rect_filled(r, CornerRadius::ZERO, theme::HOVER);
                    }
                    ui.painter().text(
                        pos2(r.left() + 24., r.center().y),
                        Align2::LEFT_CENTER,
                        t(name),
                        FontId::proportional(15.),
                        if sel { theme::ACCENT } else { theme::TEXT },
                    );
                    if resp.clicked() {
                        self.settings_page = page;
                    }
                }
            });
        egui::CentralPanel::default()
            .frame(egui::Frame::NONE.fill(Color32::WHITE).inner_margin(Margin::same(20)))
            .show(ctx, |ui| {
                egui::ScrollArea::vertical().show(ui, |ui| match self.settings_page {
                    SettingsPage::Security => self.security_page(ui),
                    SettingsPage::Network => self.network_page(ui),
                    SettingsPage::About => self.about_page(ui),
                });
            });
    }

    fn card(ui: &mut Ui, title: &str, add: impl FnOnce(&mut Ui)) {
        egui::Frame::NONE
            .stroke(Stroke::new(1., theme::GRAY_BG))
            .corner_radius(CornerRadius::same(8))
            .inner_margin(Margin::same(16))
            .show(ui, |ui| {
                ui.set_width(ui.available_width().min(560.));
                ui.label(RichText::new(title).size(16.).strong());
                ui.add_space(8.);
                add(ui);
            });
        ui.add_space(12.);
    }

    fn security_page(&mut self, ui: &mut Ui) {
        let mut open_dialog = false;
        Self::card(ui, &t("Password"), |ui| {
            let method = get_option("verification-method");
            for (value, name) in [
                ("use-temporary-password", "Use one-time password"),
                ("use-permanent-password", "Use permanent password"),
                ("", "Use both passwords"),
            ] {
                if ui.radio(method == value, t(name)).clicked() {
                    set_option("verification-method".to_owned(), value.to_owned());
                }
            }
            ui.add_space(6.);
            if widgets::outlined_button(ui, &t("Set permanent password"), 0.).clicked() {
                open_dialog = true;
            }
        });
        Self::card(ui, &t("Accept sessions via"), |ui| {
            let mode = get_option("approve-mode");
            for (value, name) in [
                ("password", "Accept sessions via password"),
                ("click", "Accept sessions via click"),
                ("", "Accept sessions via both"),
            ] {
                if ui.radio(mode == value, t(name)).clicked() {
                    set_option("approve-mode".to_owned(), value.to_owned());
                }
            }
        });
        if open_dialog {
            self.password_dialog = Some(PasswordDialog {
                password: String::new(),
                confirm: String::new(),
                error: String::new(),
            });
        }
    }

    fn network_page(&mut self, ui: &mut Ui) {
        let mut apply = false;
        let (id_server, relay_server, api_server, key) = (
            &mut self.id_server,
            &mut self.relay_server,
            &mut self.api_server,
            &mut self.key,
        );
        Self::card(ui, &t("ID/Relay Server"), |ui| {
            egui::Grid::new("servers").num_columns(2).spacing([12., 10.]).show(ui, |ui| {
                for (name, value) in [
                    ("ID Server", id_server),
                    ("Relay Server", relay_server),
                    ("API Server", api_server),
                    ("Key", key),
                ] {
                    ui.label(t(name));
                    widgets::text_input(ui, value, "", false, 320.);
                    ui.end_row();
                }
            });
            ui.add_space(8.);
            if widgets::primary_button(ui, &t("Apply"), theme::ACCENT, 80.).clicked() {
                apply = true;
            }
        });
        if apply {
            set_option("custom-rendezvous-server".to_owned(), self.id_server.trim().to_owned());
            set_option("relay-server".to_owned(), self.relay_server.trim().to_owned());
            set_option("api-server".to_owned(), self.api_server.trim().to_owned());
            set_option("key".to_owned(), self.key.trim().to_owned());
            self.network_msg = t("Successful");
        }
        if !self.network_msg.is_empty() {
            ui.label(RichText::new(&self.network_msg).color(theme::READY));
        }
    }

    fn about_page(&mut self, ui: &mut Ui) {
        Self::card(ui, &format!("{} {}", t("About"), crate::get_app_name()), |ui| {
            ui.label(format!("{}: {}", t("Version"), crate::VERSION));
            ui.label(format!("{}: {}", t("Build Date"), crate::BUILD_DATE));
            ui.add_space(6.);
            if ui.link(t("Privacy Statement")).clicked() {
                widgets::open_url("https://rustdesk.com/privacy.html");
            }
            if ui.link(t("Website")).clicked() {
                widgets::open_url("https://rustdesk.com");
            }
            ui.add_space(6.);
            ui.label(
                RichText::new("Copyright © Purslane Ltd.\nThis FreeBSD build uses a native egui user interface.")
                    .size(12.)
                    .color(theme::TEXT_50),
            );
        });
    }

    fn password_dialog(&mut self, ctx: &egui::Context) {
        let Some(d) = self.password_dialog.as_mut() else {
            return;
        };
        let mut close = false;
        widgets::dialog(ctx, &t("Set Password"), |ui| {
            ui.label(t("Password"));
            widgets::text_input(ui, &mut d.password, "", true, 340.);
            ui.add_space(6.);
            ui.label(t("Confirmation"));
            widgets::text_input(ui, &mut d.confirm, "", true, 340.);
            if !d.error.is_empty() {
                ui.label(RichText::new(&d.error).color(theme::RED));
            }
            ui.add_space(16.);
            widgets::button_row(ui, |ui| {
                if widgets::primary_button(ui, &t("OK"), theme::ACCENT, 80.).clicked() {
                    if d.password.len() < 6 && !d.password.is_empty() {
                        d.error = t("Too short, at least 6 characters.");
                    } else if d.password != d.confirm {
                        d.error = t("The confirmation is not identical.");
                    } else if set_permanent_password_with_result(d.password.clone()) {
                        close = true;
                    } else {
                        d.error = t("Failed");
                    }
                }
                if widgets::outlined_button(ui, &t("Cancel"), 80.).clicked() {
                    close = true;
                }
            });
        });
        if close {
            self.password_dialog = None;
        }
    }

    fn show_toast(&mut self, ctx: &egui::Context) {
        let Some((text, since)) = self.toast.clone() else {
            return;
        };
        if since.elapsed() > Duration::from_secs(2) {
            self.toast = None;
            return;
        }
        ctx.request_repaint_after(Duration::from_millis(200));
        egui::Area::new(egui::Id::new("toast"))
            .anchor(Align2::CENTER_BOTTOM, [0., -60.])
            .order(egui::Order::Tooltip)
            .show(ctx, |ui| {
                egui::Frame::NONE
                    .fill(Color32::from_black_alpha(0xCC))
                    .corner_radius(CornerRadius::same(6))
                    .inner_margin(Margin::symmetric(14, 8))
                    .show(ui, |ui| ui.label(RichText::new(text).color(Color32::WHITE)));
            });
    }
}

impl eframe::App for MainWindow {
    fn clear_color(&self, _visuals: &egui::Visuals) -> [f32; 4] {
        [1., 1., 1., 1.]
    }

    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        widgets::resize_handles(ctx);
        if self.last_load.elapsed() > Duration::from_secs(3) {
            self.load_peers();
        }
        self.query_onlines(ctx);
        ctx.request_repaint_after(Duration::from_secs(3));

        let tabs: Vec<Tab> = if self.settings_open {
            vec![
                Tab { label: t("Home"), glyph: Some(Glyph::Home), closable: false },
                Tab { label: t("Settings"), glyph: None, closable: true },
            ]
        } else {
            vec![]
        };
        let selected = if self.on_settings { 1 } else { 0 };
        match widgets::title_bar(ctx, &mut self.icons, &tabs, selected, true, true) {
            Some(TitleBarEvent::SelectTab(i)) => self.on_settings = i == 1,
            Some(TitleBarEvent::CloseTab) => {
                self.settings_open = false;
                self.on_settings = false;
            }
            Some(TitleBarEvent::Settings) => self.open_settings(),
            None => {}
        }
        if self.on_settings {
            self.settings(ctx);
        } else {
            self.home(ctx);
        }
        self.password_dialog(ctx);
        self.show_toast(ctx);
    }
}
