ANDROID_ARCH		:= arch-arm
ANDROID_PLATFORM	:= android-8

COMPILER_PREFIX		:= arm-linux-androideabi-
COMPILER_NAME		:= $(COMPILER_PREFIX)4.4.3
COMPILER_SYSTEM		:= linux-x86

SYSROOT			:= $(NDK)/platforms/$(ANDROID_PLATFORM)/$(ANDROID_ARCH)
CXX			:= $(NDK)/toolchains/$(COMPILER_NAME)/prebuilt/$(COMPILER_SYSTEM)/bin/$(COMPILER_PREFIX)g++ --sysroot=$(SYSROOT)
CPPFLAGS		+= -I$(NDK)/sources/cxx-stl/gnu-libstdc++/include -I$(NDK)/sources/cxx-stl/gnu-libstdc++/libs/armeabi/include
