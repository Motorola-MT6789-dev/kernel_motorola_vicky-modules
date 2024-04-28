DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

ifeq ($(DLKM_INSTALL_TO_VENDOR_OUT),true)
HIMAX_MMI_MODULE_PATH := $(TARGET_OUT_VENDOR)/lib/modules/
else
HIMAX_MMI_MODULE_PATH := $(KERNEL_MODULES_OUT)
endif

ifeq ($(HIMAX_V2_MMI_0FLASH),true)
	KERNEL_CFLAGS += CONFIG_INPUT_TOUCHSCREEN_HIMAX_0FLASH_MMI_0FLASH=y
endif
ifneq ($(BOARD_USES_TOUCH_PALM),)
	KERNEL_CFLAGS += CONFIG_INPUT_TOUCHSCREEN_HIMAX_0FLASH_MMI_ENABLE_PALM=y
endif

ifneq ($(BOARD_USES_DOUBLE_TAP),)
	KERNEL_CFLAGS += CONFIG_INPUT_HIMAX_0FLASH_MMI_ENABLE_DOUBLE_TAP=y
endif

ifneq ($(BOARD_USES_HIMAX_MULTI_BIN),)
	KERNEL_CFLAGS += CONFIG_INPUT_HIMAX_0FLASH_MMI_ENABLE_MULTI_BIN=y
endif

ifeq ($(HIMAX_V2_MMI_HX83102D),true)
	KERNEL_CFLAGS += CONFIG_INPUT_HIMAX_0FLASH_MMI_IC_NAME_D=hx83102d
endif

ifeq ($(HIMAX_V2_MMI_HX83112F),true)
	KERNEL_CFLAGS += CONFIG_INPUT_HIMAX_0FLASH_MMI_IC_NAME=hx83112f
endif

ifneq ($(BOARD_USES_PANEL_NOTIFICATIONS),)
	KERNEL_CFLAGS += CONFIG_INPUT_HIMAX_PANEL_NOTIFICATIONS=y
endif

include $(CLEAR_VARS)
LOCAL_MODULE := himax_0flash_mmi.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(HIMAX_MMI_MODULE_PATH)
include $(DLKM_DIR)/AndroidKernelModule.mk

include $(call first-makefiles-under,$(LOCAL_PATH))
