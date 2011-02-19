-include local.mk

ANT		?= ant
NDKBUILD	?= $(NDK)/ndk-build

debug:: jni
	$(ANT) debug

jni:: concrete
	$(NDKBUILD) NDK=$(NDK)

concrete::
	mkdir -p obj
	ln -sf ../jni/concrete.mk obj/
	$(MAKE) -C jni/concrete O=../../obj/concrete NDK=$(NDK)

install::
	$(ANT) install

clean::
	rm -rf bin gen obj libs
