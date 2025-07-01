/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FONT_H
#define _FONT_H

#include "pico/types.h"

typedef struct {
    uint16_t bitmap_index;
    uint16_t adv_w;
    int8_t box_w, box_h, ofs_x, ofs_y;
} __attribute__((packed)) lv_font_fmt_txt_glyph_dsc_t;

typedef struct {
    uint16_t range_start, range_length, glyph_id_start, list_length;
    void *unicode_list, *glyph_id_ofs_list;
    enum {
        LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    } type;
} lv_font_fmt_txt_cmap_t;

typedef struct {
    const uint8_t *glyph_bitmap;
    const lv_font_fmt_txt_glyph_dsc_t *glyph_dsc;
    const lv_font_fmt_txt_cmap_t *cmaps;
    uint8_t cmap_num, bpp, kern_scale, kern_classes;
    void *kern_dsc;
} lv_font_fmt_txt_dsc_t;

typedef struct {
    lv_font_fmt_txt_dsc_t *dsc;
    uint8_t line_height, base_line;
} lv_font_t;

// Intel Mono - variable width, FONT_WIDTH is maximum character width
#define FONT_HEIGHT 23
#define FONT_WIDTH 14
extern const lv_font_t intel_mono_2bpp;

// Unifont - monospace, FONT_WIDTH is character width
// #define FONT_HEIGHT 16
// #define FONT_WIDTH 8

#define TERMINAL_COLS_1280 (1280 / FONT_WIDTH)
#define TERMINAL_ROWS_720  (720 / FONT_HEIGHT)
#define TERMINAL_COLS_640  (640 / FONT_WIDTH)
#define TERMINAL_ROWS_480  (480 / FONT_HEIGHT)

#endif //SOFTWARE_FONT_H
