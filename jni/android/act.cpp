/*
 * Copyright (c) 2011  Timo Savola
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <concrete/context.hpp>
#include <concrete/event.hpp>
#include <concrete/execution.hpp>
#include <concrete/io/resolve.hpp>
#include <concrete/objects/code.hpp>

#include "jni.hpp"
#include "modules/concrete.hpp"

using namespace concrete;

class DummyResolve: public Resolve {};

class DummyLoop: public EventLoop {
public:
	virtual void wait(const EventSource &source, unsigned int conditions, EventCallback *callback) {}
	virtual void poll() {}
};

CONCRETE_ANDROID_JNICALL(jint, Act, execute)(JNIEnv *env, jobject object, jbyteArray array)
{
	int value = -1;

	auto data = env->GetByteArrayElements(array, NULL);
	if (data) {
		auto size = env->GetArrayLength(array);

		try {
			DummyLoop event_loop;
			Context context(event_loop);
			ScopedContext activate(context);

			context.add_execution(Execution::New(CodeObject::Load(data, size)));

			while (context.executable())
				context.execute();

			value = get_test_value();

		} catch (...) {
			// TODO
		}

		env->ReleaseByteArrayElements(array, data, 0);
	}

	return value;
}

void concrete::Resolve::suspend_until_resolved()
{
}

struct addrinfo *concrete::Resolve::addrinfo()
{
	return NULL;
}

Resolve *concrete::ResourceCreate<Resolve>::New(const std::string &node, const std::string &service)
{
	return NULL;
}
