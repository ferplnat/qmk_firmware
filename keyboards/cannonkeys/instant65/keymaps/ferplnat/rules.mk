# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -v FFFF -p FFFF

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes  # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
NKRO_ENABLE = yes       # Enable N-Key Rollover
CAPS_WORD_ENABLE = yes  # Enable Caps Word
LTO_ENABLE = yes        # Shrink Firmware size (Link Time Optimization) Increases build time


# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
