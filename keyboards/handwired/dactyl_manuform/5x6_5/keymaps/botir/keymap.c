// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// enum layer_names {
//   _QWERTY,
//   _HALMAK,
//   _NUMPAD,
//   _COMMAND,
//   _MOUSE,
// };
#define _QWERTY 0
#define _HALMAK 1
#define _NUMPAD 2
#define _COMMAND 3
#define _MOUSE 4

#define QU_A    LSFT_T(KC_A)
#define QU_S    LCTL_T(KC_S)
#define QU_D    LALT_T(KC_D)
#define QU_F    LGUI_T(KC_F)

#define QU_J    RGUI_T(KC_J)
#define QU_K    RALT_T(KC_K)
#define QU_L    RCTL_T(KC_L)
#define QU_SCLN RSFT_T(KC_SCLN)

#define HM_S    LSFT_T(KC_S)
#define HM_H    LCTL_T(KC_H)
#define HM_N    LALT_T(KC_N)
#define HM_T    LGUI_T(KC_T)

#define HM_A    RGUI_T(KC_A)
#define HM_E    RALT_T(KC_E)
#define HM_O    RCTL_T(KC_O)
#define HM_I    RSFT_T(KC_I)

#define QWERT   DF(_QWERTY)
#define HALMK   DF(_HALMAK)

#define SPC_L   LSFT_T(KC_SPC)
#define SPC_R   RSFT_T(KC_SPC)
#define ENT_L   LSFT_T(KC_ENT)
#define ENT_R   RSFT_T(KC_ENT)

#define UNDO    LGUI(KC_Z)
#define REDO    LGUI(KC_Y)
#define CUT     LGUI(KC_X)
#define COPY    LGUI(KC_C)
#define PASTE   LGUI(KC_V)
#define ALL     LGUI(KC_A)

#define NUMTG       TG(_NUMPAD)
#define COMMANDTG   TG(_COMMAND)
#define MOUSETG     TG(_MOUSE)

#define CTL_ESC  LCTL_T(KC_ESC)
#define CTL_w    LCTL(KC_W)
#define CTL_t    LCTL(KC_T)
#define CTL_pgdw LCTL(KC_PGDN)
#define CTL_pgup LCTL(KC_PGUP)
#define CMD_LEFT LGUI(KC_LEFT)
#define CMD_TAB  LGUI(KC_TAB)
#define CMD_RGHT LGUI(KC_RGHT)
#define CMD_CLK  LGUI(KC_BTN1)
#define LY_DWN  KC_TRNS



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_5x6_5(
    /* QWERTYDEFAULT
   * .--------------------------------------------.                                  .--------------------------------------------.
   * |   `     |   1  |   2  |  3   |  4   |  5   |                                  |   6  |   7  |   8  |  9   |  0   |    -    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | Tab     |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |    [    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | ESC/CTL |A/SHFT|S /CTL|D /ALT|F /CMD|   G  |                                  |   H  |J /CMD|K /ALT|L /CTL|;/SHFT|    '    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | ( /Shft |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | ) /Shft |
   * '--------------------------------------------/4      2              3          2\--------------------------------------------'
   *               |  CMD |  ALT |      1/ DEL   /---------------.    .---------------\BC_SPC \1       | ALT  | CMD  |
   *               |      |      |      / CMND  / CTL   / SPACE /      \ ENTER \ SPACE \ NUMPD \       |      |      |
   *               '-------------'     '-------/  [    / MOUSE /        \ COMMD \       \-------'      '-------------'
   *                                          /---------------/          \---------------\
   *                                        3/   =   /       /            \       \  CTL  \4
   *                                        / NUMPD /       /              \       \  ]    \
   *                                       '---------------'                '---------------'
   */
    KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                                          KC_6,  KC_7,  KC_8,     KC_9,   KC_0,      KC_MINS, 
    KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                                          KC_Y,  KC_U,  KC_I,     KC_O,   KC_P,      KC_LBRC,
    CTL_ESC,  QU_A,  QU_S,  QU_D,  QU_F,  KC_G,                                          KC_H,  QU_J,  QU_K,     QU_L,   QU_SCLN,   KC_QUOT,
    SC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                                          KC_N,  KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   SC_RSPC,
            
    KC_LGUI,  KC_LALT, LT(_COMMAND,KC_DEL), LCTL_T(KC_LBRC), LT(_MOUSE,KC_SPC),     LT(_COMMAND,KC_ENT), KC_SPC, LT(_NUMPAD,KC_BSPC),   LALT_T(KC_RALT), KC_RGUI,
                                            LT(_NUMPAD,KC_EQL), KC_NO,                   KC_NO, RCTL_T(KC_RBRC)
  ),
	[_HALMAK] = LAYOUT_5x6_5(
   /* HALMAK
   * .--------------------------------------------.                                  .--------------------------------------------.
   * |   `     |   1  |   2  |  3   |  4   |  5   |                                  |   6  |   7  |   8  |  9   |  0   |    -    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | Tab     |   W  |   L  |   R  |   B  |   Z  |                                  |   ;  |   Q  |   U  |   D  |   J  |    [    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | ESC/CTL |S/SHFT|H /CTL|N /ALT|T /CMD|   ,  |                                  |   .  |A /CMD|E /ALT|O /CTL|I/SHFT|    '    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * | ( /Shft |   F  |   M  |   V  |   C  |   /  |                                  |   G  |   P  |   X  |   K  |   Y  | ) /Shft |
   * '--------------------------------------------/4      2              3          2\--------------------------------------------'
   *               |  CMD |  ALT |      1/ DEL   /---------------.    .---------------\BC_SPC \1       | ALT  | CMD  |
   *               |      |      |      / COMMD / CTL   / SPACE /      \ ENTER \ SPACE \ NUMPD \       |      |      |
   *               '-------------'     '-------/  [    / MOUSE /        \ COMMD \       \-------'      '-------------'
   *                                          /---------------/          \---------------\
   *                                        3/   =   /       /            \       \  CTL  \4
   *                                        / NUMPD /       /              \       \  ]    \
   *                                       '---------------'                '---------------'
   */
    KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,     KC_5,                                               KC_6,  KC_7,  KC_8,   KC_9,   KC_0,  KC_MINS, 
    KC_TAB,  KC_W,  KC_L,  KC_R,  KC_B,     KC_Z,                                            KC_SCLN,  KC_Q,  KC_U,   KC_D,   KC_J,  KC_LBRC,
    CTL_ESC, HM_S,  HM_H,  HM_N,  HM_T,  KC_COMM,                                             KC_DOT,  HM_A,  HM_E,   HM_O,   HM_I,  KC_QUOT,
    SC_LSPO, KC_F,  KC_M,  KC_V,  KC_C,  KC_SLSH,                                               KC_G,  KC_P,  KC_X,   KC_K,   KC_Y,  SC_RSPC,
            
    KC_LGUI,  KC_LALT,    LT(_COMMAND,KC_DEL), LCTL_T(KC_LBRC), LT(_MOUSE,KC_SPC),     LT(_COMMAND,KC_ENT), KC_SPC, LT(2,KC_BSPC), LALT_T(KC_RALT), KC_RGUI,
                                                  LT(_NUMPAD,KC_EQL), KC_NO,              KC_NO, RCTL_T(KC_RBRC)
  ),
  [_NUMPAD] = LAYOUT_5x6_5(
  /* LAYER (NUMPAD)
   * .--------------------------------------------.                                  .--------------------------------------------.
   * |  POWER  |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11   |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * |    \/   | REDO |  \/  |  \/  |  F2  |      |                                  |   7  |   7  |   8  |   9  |   +  |   F12   |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * |    \/   |  ALL |  CUT | COPY | PASTE|      |                                  |   4  |   4  |   5  |   6  |   -  |   F2    |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
   * |    \/   | UNDO |      |      |      |      |                                  |   1  |   1  |   2  |   3  |   \  |    \/   |
   * '--------------------------------------------/4      2              3          2\--------------------------------------------'
   *               | RESET| POWER|      1/ \/    /---------------.    .---------------\BC_SPC \1       |QWERTY|HALMAK|
   *               |      |      |      /       /  \/   /  \/   /      \ TOGGL \   0   \       \       |      |      |
   *               '-------------'     '-------/       /       /        \ NUMPAD\       \-------'      '-------------'
   *                                          /---------------/          \---------------\
   *                                        3/ TOGGL /       /            \       \  \/   \4
   *                                        / NUMPAD/       /              \       \       \
   *                                       '---------------'                '---------------'
   */
    
    KC_PWR,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,                                     KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,   KC_F11,
    LY_DWN,   REDO, LY_DWN,  LY_DWN, KC_F2,  KC_NO,                                      KC_7,   KC_7,   KC_8,   KC_9,  KC_PLUS,  KC_F12,
    LY_DWN,    ALL,    CUT,    COPY,  PASTE,  KC_NO,                                      KC_4,   KC_4,   KC_5,   KC_6, KC_MINS,   KC_F2,
    LY_DWN,   UNDO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,                                      KC_1,   KC_1,   KC_2,   KC_3, KC_BSLS,   LY_DWN,
                QK_BOOT, KC_PWR,      LY_DWN, LY_DWN,  LY_DWN,             NUMTG, KC_0, KC_BSPC,     QWERT, HALMK, 
                                              NUMTG,  KC_NO,             KC_NO, LY_DWN
  ),
  [_COMMAND] = LAYOUT_5x6_5(
  /* LAYER (COMMAND)
   * .--------------------------------------------.                                  .--------------------------------------------.
   * |   ESC   |      |      |      |      |      |                                  |      |      |      |      |        |       |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+--------+-------|
   * |   ESC   |  ESC |CTL+W | CTL+T|CTL+DW|CTL+DW|                                  |PG_DW | HOME |  UP  |INSERT|SHFT+INS|  ESC  |
   * |---------+------+------+------+------+------|                                  |------+------+------+------+--------+-------|
   * |    \/   |CP_LCK|C+LEFT|C+TAB |C+RGHT|C+RGHT|                                  | LEFT | LEFT | DOWN | RIGHT|  END   |PRT_SCR|
   * |---------+------+------+------+------+------|                                  |------+------+------+------+--------+-------|
   * |    \/   |      |      |      |CTL+UP|CTL+UP|                                  |PG_UP |  \/  | DOWN |      |CTX_MENU|   \/  |
   * '--------------------------------------------/4      2              3          2\--------------------------------------------'
   *               |  \/  |  \/  |      1/  DEL  /---------------.    .---------------\BC_SPC \1       |  \/  |  \/  |
   *               |      |      |      /       / CTL   / SPACE /      \ TOGGLE\ SPACE \       \       |      |      |
   *               '-------------'     '-------/  [    /       /        \ COMMD \       \-------'      '-------------'
   *                                          /---------------/          \---------------\
   *                                        3/ TOGGLE/       /            \       \  CTL  \4
   *                                        / COMMD /       /              \       \  ]    \
   *                                       '---------------'                '---------------'
   */
   
    KC_ESC,  KC_NO,     KC_NO,       KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ESC, KC_ESC, CTL_w, CTL_t, CTL_pgdw, CTL_pgdw,                               KC_PGDN, KC_HOME, KC_UP, KC_INS, LSFT(KC_INS), KC_ESC,
    LY_DWN, KC_CAPS, CMD_LEFT, CMD_TAB, CMD_RGHT, CMD_RGHT,                         KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PSCR,
    LY_DWN, KC_NO, KC_NO, KC_NO, CTL_pgup, CTL_pgup,                                KC_PGUP, LY_DWN, KC_DOWN, KC_NO, KC_APP, KC_TRNS,
            
            LY_DWN, LY_DWN,       KC_DEL, LCTL_T(KC_LBRC), KC_SPC,               COMMANDTG, KC_SPC, KC_BSPC, LY_DWN, LY_DWN,
                                          COMMANDTG, KC_NO,                KC_NO, RCTL_T(KC_RBRC)
  ),
  [_MOUSE] = LAYOUT_5x6_5(
    /* LAYER (MOUSE)
    *       .--------------------------------------------.                                  .--------------------------------------------.
    *       |         |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11   |
    *       |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
    *       |    \/   | ACL1 |      |      |      |      |                                  | WH-UP|WH-LFT|  UP  |WH-RGT|  F12 |         |
    *       |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
    *       |    \/   | ACL2 | BT2  | BT3  | BT1  | BT1  |                                  | LEFT | LEFT | DOWN | RGHT |CMD+1 |         |
    *       |---------+------+------+------+------+------|                                  |------+------+------+------+------+---------|
    *       |    \/   | ACL0 |      |      |      |      |                                  | WH-DW|      | DOWN |      |      |    \/   |
    *       '--------------------------------------------/4      2              3          2\--------------------------------------------'
    *                     |  \/  |  \/  |      1/ DEL   /---------------.    .---------------\BC_SPC \1       |  \/  |  \/  |
    *                     |      |      |      /       / CTL   / SPACE /      \ TOGGLE\ SPACE \       \       |      |      |
    *                     '-------------'     '-------/  [    /       /        \ MOUSE \       \-------'      '-------------'
    *                                                /---------------/          \---------------\
    *                                              3/ TGGL  /       /            \       \  CTL  \4
    *                                              / MOUSE /       /              \       \  ]    \
    *                                             '---------------'                '---------------'
    */
     KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                   KC_F6,    KC_F7,    KC_F8,   KC_F9,  KC_F10,   KC_F11,
    LY_DWN,  KC_ACL1,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_WH_U,  KC_WH_L,  KC_MS_U, KC_WH_R,  KC_F12,    KC_NO,
    LY_DWN,  KC_ACL2,  KC_BTN2,  KC_BTN3,  KC_BTN1,  KC_BTN1,                                 KC_MS_L,  KC_MS_L,  KC_MS_D, KC_MS_R, CMD_CLK,    KC_NO,
    LY_DWN,  KC_ACL0,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_WH_D,    KC_NO,  KC_MS_D,   KC_NO,   KC_NO,  KC_TRNS, 
      
                      LY_DWN, LY_DWN,       KC_DEL, LCTL_T(KC_LBRC), KC_SPC,            MOUSETG, KC_SPC, KC_BSPC,         LY_DWN, LY_DWN, 
                                `                  MOUSETG,  KC_NO,             KC_NO, RCTL_T(KC_RBRC)
  ),
};
