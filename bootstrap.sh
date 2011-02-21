#!/bin/sh

git submodule update --init
(cd jni/concrete && ./bootstrap.sh)
