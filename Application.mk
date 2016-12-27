APP_STL := gnustl_static
APP_CPPFLAGS += -fexceptions -frtti -std=c++11 -D__STDC_CONSTANT_MACROS

#APP_CPPFLAGS += -DRELEASE
#APP_CPPFLAGS += -DRELEASE_PACKAGE=com.touchtalent.bobbleapp.bobble_native_api
#APP_CPPFLAGS += -DRELEASE_KEY=8mMxc9satCC4CigyzgCO9wWxKs8=

APP_ABI := all
APP_PLATFORM=android-14