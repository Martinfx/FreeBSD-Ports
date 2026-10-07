--- shadps4plus/src/core/file_format/pkg.cpp.orig	2026-01-22 18:54:16 UTC
+++ shadps4plus/src/core/file_format/pkg.cpp
@@ -1,6 +1,7 @@
 // SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
 // SPDX-License-Identifier: GPL-2.0-or-later
 
+#include <algorithm>
 #include <iostream>
 #include <zlib.h>
 #include "common/io_file.h"
@@ -29,6 +30,17 @@
     }
 }
 
+// Copy a structure out of a decompressed 0x10000 block without reading past
+// its end; whatever lies beyond the block is zero-filled.
+template <typename T>
+static T ReadFromBlock(const std::vector<char>& block, size_t pos) {
+    T value{};
+    if (pos < block.size()) {
+        std::memcpy(&value, block.data() + pos, std::min(sizeof(T), block.size() - pos));
+    }
+    return value;
+}
+
 u32 GetPFSCOffset(std::span<const u8> pfs_image) {
     static constexpr u32 PfscMagic = 0x43534650;
     u32 value;
@@ -234,7 +246,7 @@
             }
 
             std::vector<u8> data;
-            data.resize(entry.size);
+            data.resize(msize);
             file.ReadRaw<u8>(data.data(), entry.size);
 
             std::span<u8> cipherNp(data.data(), msize);
@@ -280,12 +292,25 @@
 
         // Retrieve PFSC from decrypted pfs_image.
         pfsc_offset = GetPFSCOffset(pfs_decrypted);
+        if (pfsc_offset == u32(-1)) {
+            failreason = "PFSC header not found, the PFS image could not be decrypted";
+            return false;
+        }
         std::memcpy(pfsc.data(), pfs_decrypted.data() + pfsc_offset, length - pfsc_offset);
 
         PFSCHdr pfsChdr;
         std::memcpy(&pfsChdr, pfsc.data(), sizeof(pfsChdr));
 
+        if (pfsChdr.block_sz2 <= 0 || pfsChdr.block_offsets < 0) {
+            failreason = "Invalid PFSC header";
+            return false;
+        }
         num_blocks = (int)(pfsChdr.data_length / pfsChdr.block_sz2);
+        if (num_blocks < 0 ||
+            u64(pfsChdr.block_offsets) + (u64(num_blocks) + 1) * 8 > pfsc.size()) {
+            failreason = "PFSC block table lies outside of the PFS image";
+            return false;
+        }
         sectorMap.resize(num_blocks + 1); // 8 bytes, need extra 1 to get the last offset.
 
         for (int i = 0; i < num_blocks + 1; i++) {
@@ -306,6 +331,10 @@
         const u64 sectorOffset = sectorMap[i];
         const u64 sectorSize = sectorMap[i + 1] - sectorOffset;
 
+        if (sectorOffset > pfsc.size() || sectorSize > pfsc.size() - sectorOffset) {
+            failreason = "PFSC block lies outside of the PFS image";
+            return false;
+        }
         compressedData.resize(sectorSize);
         std::memcpy(compressedData.data(), pfsc.data() + sectorOffset, sectorSize);
 
@@ -325,8 +354,7 @@
 
         if (i >= 1 && i <= occupied_blocks) { // Get all iNodes, gives type, file size and location.
             for (int p = 0; p < 0x10000; p += 0xA8) {
-                Inode node;
-                std::memcpy(&node, &decompressedData[p], sizeof(node));
+                Inode node = ReadFromBlock<Inode>(decompressedData, p);
                 if (node.Mode == 0) {
                     break;
                 }
@@ -343,11 +371,13 @@
 
         if (uroot_reached) {
             for (int i = 0; i < 0x10000; i += ent_size) {
-                Dirent dirent;
-                std::memcpy(&dirent, &decompressedData[i], sizeof(dirent));
+                Dirent dirent = ReadFromBlock<Dirent>(decompressedData, i);
                 ent_size = dirent.entsize;
                 if (dirent.ino != 0) {
                     ndinode_counter++;
+                    if (ent_size <= 0) {
+                        break;
+                    }
                 } else {
                     // Set the the folder according to the current inode.
                     // Can be 2 or more (rarely)
@@ -377,15 +407,15 @@
         bool end_reached = false;
         if (dinode_reached) {
             for (int j = 0; j < 0x10000; j += ent_size) { // Skip the first parent and child.
-                Dirent dirent;
-                std::memcpy(&dirent, &decompressedData[j], sizeof(dirent));
+                Dirent dirent = ReadFromBlock<Dirent>(decompressedData, j);
 
                 // Stop here and continue the main loop
-                if (dirent.ino == 0) {
+                if (dirent.ino == 0 || dirent.entsize <= 0) {
                     break;
                 }
 
                 ent_size = dirent.entsize;
+                dirent.namelen = std::clamp(dirent.namelen, 0, int(sizeof(dirent.name)));
                 auto& table = fsTable.emplace_back();
                 table.name = std::string(dirent.name, dirent.namelen);
                 table.inode = dirent.ino;
@@ -419,6 +449,9 @@
     std::string inode_name = fsTable[index].name;
 
     if (inode_type == PFS_FILE) {
+        if (inode_number < 0 || size_t(inode_number) >= iNodeBuf.size()) {
+            return;
+        }
         int sector_loc = iNodeBuf[inode_number].loc;
         int nblocks = iNodeBuf[inode_number].Blocks;
         int bsize = iNodeBuf[inode_number].Size;
@@ -439,6 +472,9 @@
 
         for (int j = 0; j < nblocks; j++) {
 			std::cout << "\r" << ((j + 1) * 100) / nblocks << "%  ";
+            if (size_t(sector_loc) + j + 1 >= sectorMap.size()) {
+                break;
+            }
             u64 sectorOffset =
                 sectorMap[sector_loc + j]; // offset into PFSC_image and not pfs_image.
             u64 sectorSize = sectorMap[sector_loc + j + 1] -
@@ -455,6 +491,9 @@
 
             PKG::crypto.decryptPFS(dataKey, tweakKey, pfsc, pfs_decrypted, currentSector1);
 
+            if (previousData + sectorSize > pfs_decrypted.size()) {
+                break;
+            }
             compressedData.resize(sectorSize);
             std::memcpy(compressedData.data(), pfs_decrypted.data() + previousData, sectorSize);
 
