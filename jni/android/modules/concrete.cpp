/*
 * Copyright (c) 2011  Timo Savola
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <concrete/objects/internal.hpp>
#include <concrete/objects/long.hpp>

using namespace concrete;

static int test_value;

int get_test_value()
{
	return test_value;
}

namespace {

Object Test(const TupleObject &args, const DictObject &kwargs)
{
	auto value = args.get_item(0);
	test_value = value.require<LongObject>().value();
	return value;
}

} // namespace

CONCRETE_INTERNAL_FUNCTION(ConcreteModule_Test, Test)
