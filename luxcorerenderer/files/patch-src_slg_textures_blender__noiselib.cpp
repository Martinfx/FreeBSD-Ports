--- src/slg/textures/blender_noiselib.cpp.orig	2025-01-02 11:17:30 UTC
+++ src/slg/textures/blender_noiselib.cpp
@@ -254,7 +254,7 @@ static float orgBlenderNoise(float x, float y, float z
 /* Was BLI_hnoise(), removed noisesize, so other functions can call it without scaling. */
 static float orgBlenderNoise(float x, float y, float z)
 {
-	register float cn1, cn2, cn3, cn4, cn5, cn6, i, *h;
+	float cn1, cn2, cn3, cn4, cn5, cn6, i, *h;
 	float ox, oy, oz, jx, jy, jz;
 	float n= 0.5f;
 	int ix, iy, iz, b00, b01, b10, b11, b20, b21;
@@ -917,7 +917,7 @@ float noise3_perlin(float vec[3])
 {
 	int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
 	float rx0, rx1, ry0, ry1, rz0, rz1, *q, sx, sy, sz, a, b, c, d, t, u, v;
-	register int i, j;
+	int i, j;
 
 
 	setup(0, bx0,bx1, rx0,rx1);
