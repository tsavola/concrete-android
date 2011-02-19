/*
 * Copyright (c) 2011  Timo Savola
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <concrete/context.hpp>
#include <concrete/execute.hpp>
#include <concrete/modules/concrete.hpp>
#include <concrete/objects/code.hpp>

#include "jni.hpp"

using namespace concrete;

CONCRETE_ANDROID_JNICALL(jint, Act, execute)(JNIEnv *env, jobject object, jbyteArray array)
{
	int value = -1;

	auto data = env->GetByteArrayElements(array, NULL);
	if (data) {
		auto size = env->GetArrayLength(array);

		try {
			Context context;
			ContextScope scope(context);
			Executor executor(CodeObject::Load(data, size));

			while (executor.execute())
				;

			value = ConcreteModule::GetTestValue();

		} catch (...) {
			// TODO
		}

		env->ReleaseByteArrayElements(array, data, 0);
	}

	return value;
}
