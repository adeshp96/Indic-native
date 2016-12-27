LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := native_api

LOCAL_CPP_EXTENSION := .cc .cpp .cxx
FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/**/*.cc)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/**/**/**/*.cc)

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_LDLIBS := -lm -llog -ldl -lz -lGLESv2 -lEGL
LOCAL_STATIC_LIBRARIES += libvpx libyuv
LOCAL_CPPFLAGS += -fexceptions -frtti -std=c++11
LOCAL_LDFLAGS += -ljnigraphics

include $(BUILD_SHARED_LIBRARY)