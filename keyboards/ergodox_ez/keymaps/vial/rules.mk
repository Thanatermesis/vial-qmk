VIA_ENABLE = yes
VIAL_ENABLE = yes

#NKRO_ENABLE = yes

# reduce firmware size:
LTO_ENABLE = yes

# Build Options
#   change yes to no to disable
#
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# if NKRO this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = yes       # Mouse keys
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
SEND_STRING_ENABLE = yes     # The Send String API is part of QMK’s macro system. It allows for sequences of keystrokes to be sent automatically. The full ASCII character set is supported, along with all of the keycodes in the Basic Keycode range (as these are the only ones that will actually be sent to the host). Unicode characters are not supported with this API – see the Unicode feature instead.

#DEBOUNCE_TYPE = sym_eager_pr # default ergodox ez
DEBOUNCE_TYPE = sym_defer_g # This is the current default algorithm. This is the highest performance algorithm with lowest memory usage, and it’s also noise-resistant.

SWAP_HANDS_ENABLE= yes # Allow swapping hands of keyboard


TAP_DANCE_ENABLE = yes      # 1-2 kb. Hit the semicolon key once, send a semicolon. Hit it twice, rapidly – send a colon. Hit it three times, and your keyboard’s LEDs do a wild dance.

## these uses quite more space
LEADER_ENABLE = yes         # Combine a sequence of keys (like: ,a) fast to produce a special sending
UNICODE_ENABLE   = yes      # The easiest to use method, albeit somewhat limited. It stores Unicode characters as keycodes in the keymap itself, so it only supports code points up to 0x7FFF. This covers characters for most modern languages (including East Asian), as well as symbols, but it doesn’t cover emoji. For example, UC(0x40B) will output Ћ, and UC(0x30C4) will output ツ.
#UNICODEMAP_ENABLE = no      # In addition to standard character ranges, this method also covers emoji, ancient scripts, rare symbols etc. In fact, all possible code points (up to 0x10FFFF) are supported. Here, Unicode characters are stored in a separate mapping table. You need to maintain a unicode_map array in your keymap file, which may contain at most 16384 entries.
#UCIS_ENABLE = no            # This method also supports all possible code points. As with the Unicode Map method, you need to maintain a mapping table in your keymap file. However, there are no built-in keycodes for this feature — you have to create a custom keycode or function that invokes this functionality.     UCIS_SYM("poop", 0x1F4A9),                // 💩,     UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0)  // ಠ_ಠ
## Another alternative is using the code: send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");



#COMBO_ENABLE = yes
MAGIC_ENABLE = yes           # special features like switching ctrl-caps on the fly

# save space with useless things
KEY_OVERRIDE_ENABLE = no # Key overrides allow you to override modifier-key combinations to send a different modifier-key combination or perform completely custom actions. Don’t want shift + 1 to type ! on your computer? Use a key override to make your keyboard type something different when you press shift + 1. Ex. Send brightness up/down when pressing ctrl + volume up/down. Send delete when pressing shift + backspace.
KEY_LOCK_ENABLE  = no # Sometimes you may find yourself needing to hold down a specific key for a long period of time. Key Lock holds down the next key you press for you. Press it again, and it will be released
NKRO_ENABLE = no           # up to 248 keys pressed simultaneously, you don't need that since the default is 6 at the same time (enough)
AUDIO_ENABLE = no           # Audio output
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
GRAVE_ESC_ENABLE = no
CAPS_WORD_ENABLE = yes      # Caps Word automatically disables itself at the end of the word. That is, it stops by default once a space or any other key, or after 5 seconds, almost 1k
MIDI_ENABLE = no
MUSIC_ENABLE = no
RGBLIGHT_ANIMATION = no
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
SPACE_CADET_ENABLE = no
BLUETOOTH_ENABLE = no       # Enable Bluetooth
PROGRAMMABLE_BUTTON_ENABLE = yes  # Programmable Buttons are keys that have no predefined meaning. This means they can be processed on the host side by custom software without the operating system trying to interpret them.
AUTO_SHIFT_ENABLE = no      # Tap a key and you get its character. Tap a key, but hold it slightly longer and you get its shifted state. Voilà! No shift key needed!
RAW_ENABLE = no             # Raw HID allows for bidirectional communication between QMK and the host computer over an HID interface. This has many potential use cases, such as switching keymaps on the fly or changing RGB LED colors and modes.
SEQUENCER_ENABLE = no       # Since QMK has experimental support for MIDI, you can now turn your keyboard into a step sequencer!


#SECURE_ENABLE = no          # The secure feature aims to prevent unwanted interaction without user intervention. It allows to write firmware things when the user specifically types a combo for a time. It doesn't save space, but makes more handy for dev


# enable these to save space
#AVR_USE_MINIMAL_PRINTF = yes

