LOCAL_PATH := $(call my-dir)
MX3_PATH := $(realpath $(LOCAL_PATH)/../../..)

#include $(CLEAR_VARS)
#LOCAL_LDLIBS := -llog
#LOCAL_EXPORT_LDLIBS := -llog 
#include $(BUILD_SHARED_LIBRARY)

include $(MX3_PATH)/GypAndroid.mk


