DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := goodix_mtk_tee.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
ifneq ($(findstring mmi_relay.ko,$(BOARD_VENDOR_KERNEL_MODULES)),)
    KERNEL_CFLAGS += CONFIG_MMI_RELAY=y
    LOCAL_ADDITIONAL_DEPENDENCIES := $(KERNEL_MODULES_OUT)/mmi_relay.ko
    LOCAL_REQUIRED_MODULES := mmi_relay.ko
endif
KBUILD_OPTIONS_GKI += GKI_OBJ_MODULE_DIR=gki
include $(DLKM_DIR)/AndroidKernelModule.mk

