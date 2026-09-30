//! Tiny SVG renderer for the upstream icon assets (flutter/assets/*.svg).
//!
//! Only what those icons use is supported: `<path>` elements with the
//! complete path syntax, solid fills, `fill-rule` and a `url(...)` fill
//! (the gradient of the app icon). Rasterized with tiny-skia.

use eframe::egui::{self, Color32, ColorImage, TextureHandle, TextureOptions};
use std::collections::HashMap;
use tiny_skia::{
    FillRule, GradientStop, LinearGradient, Paint, PathBuilder, Pixmap, Point, SpreadMode,
    Transform,
};

macro_rules! asset {
    ($name:literal) => {
        include_str!(concat!("../../flutter/assets/", $name, ".svg"))
    };
}

fn source(name: &str) -> Option<&'static str> {
    Some(match name {
        "icon" => asset!("icon"),
        "win" => asset!("win"),
        "linux" => asset!("linux"),
        "mac" => asset!("mac"),
        "android" => asset!("android"),
        "refresh" => asset!("refresh"),
        "search" => asset!("search"),
        "dots" => asset!("dots"),
        "home" => asset!("home"),
        "pinned" => asset!("pinned"),
        "unpinned" => asset!("unpinned"),
        "actions" => asset!("actions"),
        "display" => asset!("display"),
        "screen" => asset!("screen"),
        "keyboard_mouse" => asset!("keyboard_mouse"),
        "chat" => asset!("chat"),
        "chat2" => asset!("chat2"),
        "close" => asset!("close"),
        "fullscreen" => asset!("fullscreen"),
        "fullscreen_exit" => asset!("fullscreen_exit"),
        "file_transfer" => asset!("file_transfer"),
        _ => return None,
    })
}

/// Icon name for a peer platform, as the Flutter UI chooses it.
pub fn platform_icon(platform: &str) -> Option<&'static str> {
    match platform {
        "" => None,
        "Mac OS" => Some("mac"),
        "Linux" => Some("linux"),
        "Android" => Some("android"),
        _ => Some("win"),
    }
}

#[derive(Default)]
pub struct IconCache {
    textures: HashMap<(&'static str, u32, u32), TextureHandle>,
}

impl IconCache {
    /// Texture of icon `name`, `size` points wide, tinted with `tint`
    /// (`None` keeps the colors of the svg).
    pub fn get(
        &mut self,
        ctx: &egui::Context,
        name: &'static str,
        size: f32,
        tint: Option<Color32>,
    ) -> Option<TextureHandle> {
        let px = (size * ctx.pixels_per_point()).round().max(1.) as u32;
        let key = (name, px, tint.map(|c| u32::from_le_bytes(c.to_array())).unwrap_or(0));
        if let Some(t) = self.textures.get(&key) {
            return Some(t.clone());
        }
        let image = render(source(name)?, px, tint)?;
        let tex = ctx.load_texture(format!("svg-{name}-{px}"), image, TextureOptions::LINEAR);
        self.textures.insert(key, tex.clone());
        Some(tex)
    }

    /// Paint icon `name` centered in `rect`.
    pub fn paint(
        &mut self,
        ui: &egui::Ui,
        rect: egui::Rect,
        name: &'static str,
        tint: Option<Color32>,
    ) {
        let size = rect.width().min(rect.height());
        if let Some(tex) = self.get(ui.ctx(), name, size, tint) {
            let r = egui::Rect::from_center_size(rect.center(), egui::vec2(size, size));
            ui.painter().image(
                tex.id(),
                r,
                egui::Rect::from_min_max(egui::pos2(0., 0.), egui::pos2(1., 1.)),
                Color32::WHITE,
            );
        }
    }
}

fn attr<'a>(tag: &'a str, name: &str) -> Option<&'a str> {
    let mut rest = tag;
    loop {
        let i = rest.find(name)?;
        let before = rest[..i].chars().last();
        let after = &rest[i + name.len()..];
        if matches!(before, Some(' ' | '\n' | '\t')) && after.starts_with("=\"") {
            let v = &after[2..];
            return v.find('"').map(|e| &v[..e]);
        }
        rest = &rest[i + name.len()..];
    }
}

fn parse_color(s: &str) -> Option<tiny_skia::Color> {
    let s = s.trim();
    let hex = s.strip_prefix('#')?;
    let v = match hex.len() {
        3 => {
            let d: Vec<u8> = hex
                .chars()
                .map(|c| c.to_digit(16).unwrap_or(0) as u8 * 17)
                .collect();
            (d[0], d[1], d[2])
        }
        6 => (
            u8::from_str_radix(&hex[0..2], 16).ok()?,
            u8::from_str_radix(&hex[2..4], 16).ok()?,
            u8::from_str_radix(&hex[4..6], 16).ok()?,
        ),
        _ => return None,
    };
    Some(tiny_skia::Color::from_rgba8(v.0, v.1, v.2, 255))
}

fn render(svg: &str, px: u32, tint: Option<Color32>) -> Option<ColorImage> {
    let svg_tag = &svg[svg.find("<svg")?..];
    let svg_tag = &svg_tag[..svg_tag.find('>')?];
    let (vx, vy, vw, vh) = match attr(svg_tag, "viewBox") {
        Some(vb) => {
            let n: Vec<f32> = vb
                .split(|c: char| c == ' ' || c == ',')
                .filter_map(|x| x.parse().ok())
                .collect();
            (*n.first()?, *n.get(1)?, *n.get(2)?, *n.get(3)?)
        }
        None => (
            0.,
            0.,
            attr(svg_tag, "width")?.parse().ok()?,
            attr(svg_tag, "height")?.parse().ok()?,
        ),
    };
    let scale = px as f32 / vw.max(vh);
    let (ox, oy) = (
        (px as f32 - vw * scale) / 2.,
        (px as f32 - vh * scale) / 2.,
    );
    let transform = Transform::from_row(scale, 0., 0., scale, ox - vx * scale, oy - vy * scale);
    let mut pixmap = Pixmap::new(px, px)?;

    let mut rest = svg;
    while let Some(i) = rest.find("<path") {
        let tag = &rest[i..];
        let end = tag.find('>')?;
        let tag_str = &tag[..end];
        rest = &tag[end..];
        let fill = attr(tag_str, "fill").unwrap_or("#000");
        if fill == "none" {
            continue;
        }
        let Some(d) = attr(tag_str, "d") else {
            continue;
        };
        let Some(path) = parse_path(d) else {
            continue;
        };
        let mut paint = Paint::default();
        paint.anti_alias = true;
        if let Some(t) = tint {
            paint.set_color_rgba8(t.r(), t.g(), t.b(), t.a());
        } else if fill.starts_with("url(") {
            // The app icon: gradient from bottom-left to top-right.
            let b = path.bounds();
            paint.shader = LinearGradient::new(
                Point::from_xy(b.left(), b.bottom()),
                Point::from_xy(b.right(), b.top()),
                vec![
                    GradientStop::new(0., tiny_skia::Color::from_rgba8(0, 0x71, 0xff, 255)),
                    GradientStop::new(1., tiny_skia::Color::from_rgba8(0, 0xbf, 0xe1, 255)),
                ],
                SpreadMode::Pad,
                Transform::identity(),
            )?;
        } else {
            paint.set_color(parse_color(fill).unwrap_or(tiny_skia::Color::BLACK));
        }
        let rule = if attr(tag_str, "fill-rule") == Some("evenodd") {
            FillRule::EvenOdd
        } else {
            FillRule::Winding
        };
        pixmap.fill_path(&path, &paint, rule, transform, None);
    }
    Some(ColorImage::from_rgba_premultiplied(
        [px as usize, px as usize],
        pixmap.data(),
    ))
}

struct Tokens<'a> {
    s: &'a [u8],
    i: usize,
}

impl<'a> Tokens<'a> {
    fn skip(&mut self) {
        while self.i < self.s.len() && matches!(self.s[self.i], b' ' | b',' | b'\n' | b'\t' | b'\r')
        {
            self.i += 1;
        }
    }

    fn command(&mut self) -> Option<u8> {
        self.skip();
        let c = *self.s.get(self.i)?;
        if c.is_ascii_alphabetic() {
            self.i += 1;
            Some(c)
        } else {
            None
        }
    }

    fn has_number(&mut self) -> bool {
        self.skip();
        matches!(self.s.get(self.i), Some(b'0'..=b'9' | b'-' | b'+' | b'.'))
    }

    fn number(&mut self) -> Option<f32> {
        self.skip();
        let start = self.i;
        let s = self.s;
        if matches!(s.get(self.i), Some(b'-' | b'+')) {
            self.i += 1;
        }
        let mut dot = false;
        while let Some(&c) = s.get(self.i) {
            if c.is_ascii_digit() {
                self.i += 1;
            } else if c == b'.' && !dot {
                dot = true;
                self.i += 1;
            } else {
                break;
            }
        }
        if matches!(s.get(self.i), Some(b'e' | b'E')) {
            self.i += 1;
            if matches!(s.get(self.i), Some(b'-' | b'+')) {
                self.i += 1;
            }
            while matches!(s.get(self.i), Some(b'0'..=b'9')) {
                self.i += 1;
            }
        }
        std::str::from_utf8(&s[start..self.i]).ok()?.parse().ok()
    }

    // Arc flags may be written without separators ("a1 1 0 011 1").
    fn flag(&mut self) -> Option<bool> {
        self.skip();
        let c = *self.s.get(self.i)?;
        self.i += 1;
        match c {
            b'0' => Some(false),
            b'1' => Some(true),
            _ => None,
        }
    }
}

fn parse_path(d: &str) -> Option<tiny_skia::Path> {
    let mut t = Tokens { s: d.as_bytes(), i: 0 };
    let mut pb = PathBuilder::new();
    let (mut cx, mut cy) = (0f32, 0f32);
    let (mut sx, mut sy) = (0f32, 0f32);
    // Last control point, for the smooth curve commands.
    let mut last_ctrl: Option<(f32, f32)> = None;
    let mut last_cmd = b' ';
    let mut cmd = t.command()?;
    loop {
        let rel = cmd.is_ascii_lowercase();
        let (bx, by) = if rel { (cx, cy) } else { (0., 0.) };
        match cmd.to_ascii_uppercase() {
            b'M' => {
                let x = t.number()? + bx;
                let y = t.number()? + by;
                pb.move_to(x, y);
                (cx, cy, sx, sy) = (x, y, x, y);
                last_ctrl = None;
                // Further pairs are implicit line-to commands.
                cmd = if rel { b'l' } else { b'L' };
                last_cmd = b'M';
                if t.has_number() {
                    continue;
                }
            }
            b'L' => {
                let x = t.number()? + bx;
                let y = t.number()? + by;
                pb.line_to(x, y);
                (cx, cy) = (x, y);
                last_ctrl = None;
            }
            b'H' => {
                let x = t.number()? + bx;
                pb.line_to(x, cy);
                cx = x;
                last_ctrl = None;
            }
            b'V' => {
                let y = t.number()? + by;
                pb.line_to(cx, y);
                cy = y;
                last_ctrl = None;
            }
            b'C' => {
                let (x1, y1) = (t.number()? + bx, t.number()? + by);
                let (x2, y2) = (t.number()? + bx, t.number()? + by);
                let (x, y) = (t.number()? + bx, t.number()? + by);
                pb.cubic_to(x1, y1, x2, y2, x, y);
                last_ctrl = Some((x2, y2));
                (cx, cy) = (x, y);
            }
            b'S' => {
                let (x1, y1) = match (last_ctrl, last_cmd.to_ascii_uppercase()) {
                    (Some((px, py)), b'C' | b'S') => (2. * cx - px, 2. * cy - py),
                    _ => (cx, cy),
                };
                let (x2, y2) = (t.number()? + bx, t.number()? + by);
                let (x, y) = (t.number()? + bx, t.number()? + by);
                pb.cubic_to(x1, y1, x2, y2, x, y);
                last_ctrl = Some((x2, y2));
                (cx, cy) = (x, y);
            }
            b'Q' => {
                let (x1, y1) = (t.number()? + bx, t.number()? + by);
                let (x, y) = (t.number()? + bx, t.number()? + by);
                pb.quad_to(x1, y1, x, y);
                last_ctrl = Some((x1, y1));
                (cx, cy) = (x, y);
            }
            b'T' => {
                let (x1, y1) = match (last_ctrl, last_cmd.to_ascii_uppercase()) {
                    (Some((px, py)), b'Q' | b'T') => (2. * cx - px, 2. * cy - py),
                    _ => (cx, cy),
                };
                let (x, y) = (t.number()? + bx, t.number()? + by);
                pb.quad_to(x1, y1, x, y);
                last_ctrl = Some((x1, y1));
                (cx, cy) = (x, y);
            }
            b'A' => {
                let rx = t.number()?;
                let ry = t.number()?;
                let rot = t.number()?;
                let large = t.flag()?;
                let sweep = t.flag()?;
                let (x, y) = (t.number()? + bx, t.number()? + by);
                arc_to(&mut pb, (cx, cy), rx, ry, rot, large, sweep, (x, y));
                (cx, cy) = (x, y);
                last_ctrl = None;
            }
            b'Z' => {
                pb.close();
                (cx, cy) = (sx, sy);
                last_ctrl = None;
            }
            _ => return None,
        }
        last_cmd = cmd;
        if cmd.to_ascii_uppercase() != b'Z' && t.has_number() {
            continue;
        }
        match t.command() {
            Some(c) => cmd = c,
            None => break,
        }
    }
    pb.finish()
}

// SVG elliptical arc (endpoint parameterization) as cubic Bézier curves.
#[allow(clippy::too_many_arguments)]
fn arc_to(
    pb: &mut PathBuilder,
    (x1, y1): (f32, f32),
    rx: f32,
    ry: f32,
    rot_deg: f32,
    large: bool,
    sweep: bool,
    (x2, y2): (f32, f32),
) {
    let (mut rx, mut ry) = (rx.abs() as f64, ry.abs() as f64);
    if rx == 0. || ry == 0. || (x1 == x2 && y1 == y2) {
        pb.line_to(x2, y2);
        return;
    }
    let (x1, y1, x2, y2) = (x1 as f64, y1 as f64, x2 as f64, y2 as f64);
    let phi = (rot_deg as f64).to_radians();
    let (sin, cos) = phi.sin_cos();
    let dx = (x1 - x2) / 2.;
    let dy = (y1 - y2) / 2.;
    let x1p = cos * dx + sin * dy;
    let y1p = -sin * dx + cos * dy;
    let lambda = (x1p * x1p) / (rx * rx) + (y1p * y1p) / (ry * ry);
    if lambda > 1. {
        let s = lambda.sqrt();
        rx *= s;
        ry *= s;
    }
    let num = rx * rx * ry * ry - rx * rx * y1p * y1p - ry * ry * x1p * x1p;
    let den = rx * rx * y1p * y1p + ry * ry * x1p * x1p;
    let mut coef = (num / den).max(0.).sqrt();
    if large == sweep {
        coef = -coef;
    }
    let cxp = coef * rx * y1p / ry;
    let cyp = -coef * ry * x1p / rx;
    let cx = cos * cxp - sin * cyp + (x1 + x2) / 2.;
    let cy = sin * cxp + cos * cyp + (y1 + y2) / 2.;
    let angle = |ux: f64, uy: f64, vx: f64, vy: f64| {
        let a = (ux * vy - uy * vx).atan2(ux * vx + uy * vy);
        a
    };
    let theta1 = angle(1., 0., (x1p - cxp) / rx, (y1p - cyp) / ry);
    let mut dtheta = angle(
        (x1p - cxp) / rx,
        (y1p - cyp) / ry,
        (-x1p - cxp) / rx,
        (-y1p - cyp) / ry,
    );
    if !sweep && dtheta > 0. {
        dtheta -= std::f64::consts::TAU;
    } else if sweep && dtheta < 0. {
        dtheta += std::f64::consts::TAU;
    }
    let segs = (dtheta.abs() / std::f64::consts::FRAC_PI_2).ceil().max(1.) as usize;
    let delta = dtheta / segs as f64;
    let k = 4. / 3. * (delta / 4.).tan();
    let point = |t: f64| {
        let (st, ct) = t.sin_cos();
        (
            cx + rx * cos * ct - ry * sin * st,
            cy + rx * sin * ct + ry * cos * st,
        )
    };
    let deriv = |t: f64| {
        let (st, ct) = t.sin_cos();
        (-rx * cos * st - ry * sin * ct, -rx * sin * st + ry * cos * ct)
    };
    let mut t = theta1;
    for _ in 0..segs {
        let t2 = t + delta;
        let (p1x, p1y) = point(t);
        let (d1x, d1y) = deriv(t);
        let (p2x, p2y) = point(t2);
        let (d2x, d2y) = deriv(t2);
        pb.cubic_to(
            (p1x + k * d1x) as f32,
            (p1y + k * d1y) as f32,
            (p2x - k * d2x) as f32,
            (p2y - k * d2y) as f32,
            p2x as f32,
            p2y as f32,
        );
        t = t2;
    }
}
