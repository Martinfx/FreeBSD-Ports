#!/usr/bin/env python3
#
# Build the boot area of an SD card for the Banana Pi BPI-R64 (MT7622).
#
# The MT7622 BootROM looks up the BL2 partition through the MBR, and
# MediaTek's BL2 looks up the "fip" partition through the GPT, so the card
# needs a GPT with a hybrid MBR (the same layout OpenWrt uses):
#
#   0x000000  hybrid MBR: 0xEE protective entry + "bl2" entry (type 0x83)
#   0x000200  GPT header and partition entries
#   0x080000  bl2       512 KiB  BL2 (bl2.img)
#   0x200000  fip       2 MiB    BL31 + U-Boot (fip.bin)
#   0x400000  ubootenv  1 MiB    U-Boot environment (and its copy)
#   0x600000  free for the operating system partitions
#
# usage: mksdimage.py bl2.img fip.bin sdcard.img

import struct
import sys
import uuid
import zlib

SECTOR = 512
IMAGE_SECTORS = 0x600000 // SECTOR
GPT_ENTRIES = 128
GPT_ENTRY_SIZE = 128
GPT_TABLE_SECTORS = GPT_ENTRIES * GPT_ENTRY_SIZE // SECTOR

# Linux filesystem data (gpart: linux-data), MBR type 0x83
TYPE_LINUX = uuid.UUID("0fc63daf-8483-4772-8e79-3d69d8477de4")
NS = uuid.UUID("6ba7b811-9dad-11d1-80b4-00c04fd430c8")

PARTS = [
    # name, first sector, sectors
    ("bl2", 0x080000 // SECTOR, 0x080000 // SECTOR),
    ("fip", 0x200000 // SECTOR, 0x200000 // SECTOR),
    ("ubootenv", 0x400000 // SECTOR, 0x100000 // SECTOR),
]


def guid(name):
    # Fixed GUIDs keep the image reproducible.
    return uuid.uuid5(NS, "bananapi-bpi-r64/" + name).bytes_le


def mbr_entry(ptype, start, sectors):
    # CHS fields are unused by the BootROM, mark them as LBA-only.
    return struct.pack("<B3sB3sII", 0, b"\xfe\xff\xff", ptype,
                       b"\xfe\xff\xff", start, sectors)


def gpt_header(current, backup, table, entries_crc):
    first_usable = 2 + GPT_TABLE_SECTORS
    last_usable = IMAGE_SECTORS - 2 - GPT_TABLE_SECTORS
    fields = [b"EFI PART", 0x00010000, 92, 0, 0, current, backup,
              first_usable, last_usable, guid("disk"), table,
              GPT_ENTRIES, GPT_ENTRY_SIZE, entries_crc]
    fmt = "<8sIIIIQQQQ16sQIII"
    hdr = struct.pack(fmt, *fields)
    fields[3] = zlib.crc32(hdr)
    return struct.pack(fmt, *fields).ljust(SECTOR, b"\0")


def main():
    if len(sys.argv) != 4:
        sys.exit("usage: mksdimage.py bl2.img fip.bin sdcard.img")
    with open(sys.argv[1], "rb") as f:
        bl2 = f.read()
    with open(sys.argv[2], "rb") as f:
        fip = f.read()

    img = bytearray(IMAGE_SECTORS * SECTOR)

    entries = bytearray(GPT_ENTRIES * GPT_ENTRY_SIZE)
    for i, (name, start, sectors) in enumerate(PARTS):
        struct.pack_into("<16s16sQQQ72s", entries, i * GPT_ENTRY_SIZE,
                         TYPE_LINUX.bytes_le, guid(name), start,
                         start + sectors - 1, 0,
                         name.encode("utf-16-le"))
    entries_crc = zlib.crc32(entries)

    mbr = bytearray(SECTOR)
    mbr[446:462] = mbr_entry(0xee, 1, IMAGE_SECTORS - 1)
    bl2_start, bl2_sectors = PARTS[0][1], PARTS[0][2]
    mbr[462:478] = mbr_entry(0x83, bl2_start, bl2_sectors)
    mbr[510:512] = b"\x55\xaa"
    img[0:SECTOR] = mbr

    backup = IMAGE_SECTORS - 1
    backup_table = backup - GPT_TABLE_SECTORS
    img[SECTOR:2 * SECTOR] = gpt_header(1, backup, 2, entries_crc)
    img[2 * SECTOR:(2 + GPT_TABLE_SECTORS) * SECTOR] = entries
    img[backup_table * SECTOR:backup * SECTOR] = entries
    img[backup * SECTOR:] = gpt_header(backup, 1, backup_table, entries_crc)

    for (name, start, sectors), path, data in zip(PARTS, sys.argv[1:3],
                                                 (bl2, fip)):
        if len(data) > sectors * SECTOR:
            sys.exit("%s does not fit into the %s partition" % (path, name))
        img[start * SECTOR:start * SECTOR + len(data)] = data

    with open(sys.argv[3], "wb") as f:
        f.write(img)


if __name__ == "__main__":
    main()
