DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

ifeq ($(DLKM_INSTALL_TO_VENDOR_OUT),true)
CHIPONE_MMI_MODULE_PATH := $(TARGET_OUT_VENDOR)/lib/modules/
else
CHIPONE_MMI_MODULE_PATH := $(KERNEL_MODULES_OUT)
endif

ifneq ($(BOARD_USES_MTK_GET_PANEL),)
	KERNEL_CFLAGS += CONFIG_INPUT_CHIPONE_MTK_GET_PANEL=y
endif

ifeq ($(CHIPONE_ESD),true)
	KERNEL_CFLAGS += CONFIG_CHIPONE_ESD=y
endif

include $(CLEAR_VARS)
LOCAL_MODULE := icnl9916_tddi_mmi.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(CHIPONE_MMI_MODULE_PATH)
include $(DLKM_DIR)/AndroidKernelModule.mk
