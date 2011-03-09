LOCAL_PATH		:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE		:= concrete
LOCAL_SRC_FILES		:= ../obj/concrete/lib/libconcrete.a

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE		:= concrete-android
LOCAL_SRC_FILES		:= android/act.cpp android/modules/concrete.cpp
LOCAL_C_INCLUDES	:= $(LOCAL_PATH)/concrete $(NDK)/sources/cxx-stl/gnu-libstdc++/include $(NDK)/sources/cxx-stl/gnu-libstdc++/libs/armeabi/include
LOCAL_STATIC_LIBRARIES	:= concrete
LOCAL_CXXFLAGS		:= -std=gnu++0x -fexceptions
LOCAL_LDLIBS		:= $(NDK)/sources/cxx-stl/gnu-libstdc++/libs/armeabi/libstdc++.a

include $(BUILD_SHARED_LIBRARY)
