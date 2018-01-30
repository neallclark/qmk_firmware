#include "dz60.h"

// Layer numbering
#define _BL  0  // Default layer
#define _FL  1  // Momentary Function Layer
#define _FLM 2  // Macro and miscleanous function layer
#define _FLN 3  // Numpad function layer 
#define _FLA 4  // Arrow nav cluster
#define _FLP 5  // Pointer device (err.... mouse but I'd used m already :) )
#define _FLALT 6// mostly alt codes with a few exceptions

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum satan_keycodes {
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

// Macro Declarations
enum {
  M_USER = 0,
  M_LINE,
  M_COM,
  M_ARW1,
  M_ARW2
};

#include "dynamic_macro.h"

// Tap Dance Declarations
enum {
  ESC_ALTF4 = 0, // Single tap = ESCAPE; Triple tap = ALT+F4
  CTRL_CAD      // Single tap (or hold) = CTRL; Triple tap = CTRL+ALT+DEL
};

// increase readability
#define _______  KC_TRNS
#define XXXXX    KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Keymap BASE: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  ~|Brk|
   * |-----------------------------------------------------------|
   * |Tab/CTL|Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bksp|
   * |-----------------------------------------------------------|
   * |FN/B  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|    R   |
   * |-----------------------------------------------------------|
   * |Shft| \ |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |FN2 |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------|
   */

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _BL ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( //Base Layer
  TD(ESC_ALTF4), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, KC_PAUSE, \
 RCTL_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,         \
 LT(_FL,KC_BSPC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
MT(MOD_LSFT,KC_HOME),KC_NUBS,KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_END),LT(_FLM,KC_NONUS_HASH),  \
   TD(CTRL_CAD), KC_LGUI, KC_LALT,          KC_SPC,                                    MO(_FLALT),MO(_FL), LT(_FLN,KC_APP),KC_RCTL),             

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _FL ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( //Main Function Layer
   SFT_T(KC_GRV),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,_______, \
      _______, KC_MS_BTN1,KC_WH_U, KC_MS_BTN2,KC_DEL,_______, _______, KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP, _______, _______, _______,        \
        _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, _______,          _______, \
_______, DYN_REC_START1,DYN_REC_STOP,DYN_MACRO_PLAY1,KC_VOLD,KC_VOLU,_______,KC_END,KC_MUTE,KC_MPRV,KC_MNXT,KC_MPLY,_______,         _______,\
        _______, _______, _______,          _______,                                              _______, _______, _______, _______),

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _FLN ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( // Numpad Layer
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_NUMLOCK, \
        _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP, _______, _______, _______,         \
        _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, _______,          _______, \
        _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_END,  _______, _______, _______, _______, _______,         _______, \
        _______, _______, _______,          _______,                                              _______, _______, _______, TO(_BL)),

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _FLA ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( //Arrow cluster layer
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   LSFT_T(KC_SLASH),_______, \
        _______, _______, _______,          _______,                                              KC_LEFT, KC_DOWN, KC_RIGHT,TO(_BL)),

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _FLM ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( // Macros etc.
   LALT(KC_GRV), RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, M(M_ARW1),M(M_ARW2),_______,_______, \
        _______, _______, _______, _______, _______, _______, _______,M(M_USER),LSFT(KC_INS), _______,KC_PAUSE, _______, _______,_______,          \
        _______, BL_STEP, _______, BL_TOGG, _______, _______, _______, _______, _______, M(M_LINE),_______, _______,         _______, \
_______,DYN_REC_START2,DYN_REC_STOP,DYN_MACRO_PLAY2,_______,_______,RESET,TO(_FLN),TO(_FLP),_______,_______,M(M_COM),_______,        _______,\
        _______, _______, _______,          TO(_FLA),                                             _______, _______, TO(_BL), TO(_BL)),

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
  [ _FLP ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( // Mouse Layer
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, \
      _______, KC_MS_BTN1,KC_WH_U,KC_MS_BTN2,_______,_______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______,         \
        _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,  \
        _______, _______, _______,          _______,                                              _______, _______, _______,TO(_BL)),

    /*  ESC      1        2        3        4        5        6        7        8        9        0        -        =        ~       Pause
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        Backsp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter
        Shift    \        Z        X        C        V        B        N        M        ,        .        /        Shift            FN
        Ctrl     Win      Alt               Space                                                 Alt      Win      Menu     Ctrl     */
[ _FLALT ] = KEYMAP_SPLIT_EVERYTHING_BUT_SPACE( // mostly alt codes with a few exceptions
   RALT(KC_ESC), _______, _______, _______,RALT(KC_4),_______,_______, _______, _______, _______, _______,M(M_ARW1),M(M_ARW2),RALT(KC_GRV),_______, \
        _______, _______, _______, RALT(KC_E),_______,_______,_______,RALT(KC_U),RALT(KC_I),RALT(KC_O),_______,_______,_______,_______,         \
        _______,RALT(KC_A),_______,_______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______,          _______,                                              _______, _______, _______, _______),

};

/*
    MACROS
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_dynamic_macro(keycode, record);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case M_ARW1:
         return MACRO(T(MINS), D(LSFT), T(DOT), U(LSFT), END);
       case M_ARW2:
         return MACRO(T(EQL), D(LSFT), T(DOT), U(LSFT), END);
      case M_USER:
        SEND_STRING("UK"SS_TAP(X_NONUS_BSLASH)"neal.clark"SS_TAP(X_TAB));
        return false;
      case M_LINE:
        return MACRO(T(HOME), D(LSFT), T(END), U(LSFT), END);
      case M_COM:
        SEND_STRING("/**/"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false;
    }
  }
  return MACRO_NONE;
}


/*
    TAPDANCES
*/

void escape_and_altf4_tapdance(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_ESC);
  } 
  else if (state->count == 3) {
    TAP_WITH_MOD(KC_LALT, KC_F4);
  }
}


enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  TRIPLE_TAP,
  TRIPLE_HOLD,
  TRIPLE_SINGLE_TAP,

  NO_TAP_STATE
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int get_dance_status(qk_tap_dance_state_t *state) {
  //NOTE: Interrupted means we are trying to do separate taps

  if (state->count == 1) {
    return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) 
      return DOUBLE_SINGLE_TAP;
    return state->pressed ? DOUBLE_HOLD : DOUBLE_TAP;
  } 
  else if (state->count == 3) {
    if (state->interrupted) 
      return TRIPLE_SINGLE_TAP;
    return state->pressed ? TRIPLE_HOLD : TRIPLE_TAP;
  }
  
  return NO_TAP_STATE;
}


//initialize an instance of 'tap' for the 'x' tap dance.
static tap ctrltap_state = { 
  .is_press_action = true,
  .state = 0
};

/*
  Handles the ctrl key tap dance finish event
*/
void ctrltap_finished(qk_tap_dance_state_t *state, void *user_data) {
  ctrltap_state.state = get_dance_status(state);
  switch (ctrltap_state.state) {
    case SINGLE_TAP: 
      register_code(KC_LCTL); 
      break;
    case SINGLE_HOLD: 
      register_code(KC_LCTL); 
      break;
    case DOUBLE_SINGLE_TAP: 
      TAP(KC_LCTL); register_code(KC_LCTL); 
      break;
    case DOUBLE_HOLD: 
      register_code(KC_LCTL); 
      break;
    case TRIPLE_TAP: 
      register_code (KC_LCTL);   register_code (KC_LALT);   register_code (KC_DEL);
      break;
  }
}

/*
  Handles the ctrl key tap dance reset event
*/
void ctrltap_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrltap_state.state) {
    case SINGLE_TAP: 
    case SINGLE_HOLD:
    case DOUBLE_HOLD:
    case DOUBLE_SINGLE_TAP:
      unregister_code(KC_LCTL); 
      break;

    case TRIPLE_TAP:
      unregister_code (KC_LCTL); unregister_code (KC_LALT); unregister_code (KC_DEL);
      break;
  }
  ctrltap_state.state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [CTRL_CAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrltap_finished, ctrltap_reset),
  [ESC_ALTF4] = ACTION_TAP_DANCE_FN(escape_and_altf4_tapdance)
};


/*
  Runs constantly in the background, in a loop.
*/
/*void matrix_scan_user(void) {
  
  uint8_t layer = biton32(layer_state);
  
  switch (layer) {
    case _BL:
      satan_caps_led_off();
      backlight_set(0);
      break;
    
    case _FL:
      backlight_set(0);
      satan_caps_led_on();
      break;
    
    case _FLM:
      backlight_set(2);
      satan_caps_led_on();
      break;

    case _FLN:
      backlight_set(1);
      satan_caps_led_on();
      break;

    case _FLA:
      backlight_set(0);
      satan_caps_led_on();
      break;

    case _FLP:
      backlight_set(0);
      satan_caps_led_on();
      break;
  }
};*/