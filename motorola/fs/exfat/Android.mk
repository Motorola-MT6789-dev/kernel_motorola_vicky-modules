ifneq ($(TARGET_USE_EXFATLINUX),true)
DLKM_DIR := vendor/motorola
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := exfat.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
KBUILD_OPTIONS_GKI += MODULE_KERNEL_VERSION=$(TARGET_KERNEL_VERSION)
include $(DLKM_DIR)/AndroidKernelModule.mk
endif
