/*
 * Copyright (c) 2011  Timo Savola
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#ifndef CONCRETE_ANDROID_JNI_HPP
#define CONCRETE_ANDROID_JNI_HPP

#include <jni.h>

#define CONCRETE_ANDROID_JNICALL(type, class, method) \
	extern "C" JNIEXPORT type JNICALL Java_concrete_android_##class##_##method

#endif
