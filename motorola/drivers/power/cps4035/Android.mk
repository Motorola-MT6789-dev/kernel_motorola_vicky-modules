DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cps_wls_charger.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
#LOCAL_ADDITIONAL_DEPENDENCIES += $(KERNEL_MODULES_OUT)/smart_pen_charger.ko
#LOCAL_REQUIRED_MODULES := cps4035.ko
KBUILD_OPTIONS_GKI += GKI_OBJ_MODULE_DIR=gki
include $(DLKM_DIR)/AndroidKernelModule.mk
