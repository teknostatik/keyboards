SRC += muse.c
AUTO_SHIFT_ENABLE = yes
AUDIO_ENABLE = no
COMBO_ENABLE = yes

# bootloader selection
# BOOTLOADER = qmk-hid

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
