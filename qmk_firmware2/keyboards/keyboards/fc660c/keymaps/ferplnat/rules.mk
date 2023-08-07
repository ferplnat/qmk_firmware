# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes  # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
NKRO_ENABLE = yes       # Enable N-Key Rollover
CAPS_WORD_ENABLE = yes  # Enable Caps Word
LTO_ENABLE = yes        # Shrink Firmware size (Link Time Optimization) Increases build time
# VIA_ENABLE = yes

# Optimize size but this may cause error "relocation truncated to fit"
#EXTRALDFLAGS = -Wl,--relax

CUSTOM_MATRIX = yes
SRC +=	matrix.c \
		actuation_point.c \
		i2c.c
