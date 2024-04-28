DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

ifneq ($(BOARD_USES_DOUBLE_TAP),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_MMI_ENABLE_DOUBLE_TAP=y
endif

ifneq ($(BOARD_USES_TOUCH_PALM),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_MMI_ENABLE_PALM=y
endif

ifneq ($(BOARD_USES_PEN_NOTIFIER),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_MMI_PEN_NOTIFIER=y
endif

ifneq ($(findstring touchscreen_mmi.ko,$(BOARD_VENDOR_KERNEL_MODULES)),)
    KERNEL_CFLAGS += CONFIG_INPUT_TOUCHSCREEN_MMI=y
endif

include $(CLEAR_VARS)
LOCAL_MODULE := focaltech_v2_mmi.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
include $(DLKM_DIR)/AndroidKernelModule.mk
