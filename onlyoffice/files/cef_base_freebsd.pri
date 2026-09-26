# CEF for FreeBSD.
#
# www/cef installs a CEF binary distribution in %%LOCALBASE%%/lib/cef: the
# headers (including the generated ones), the prebuilt libcef_dll_wrapper and
# libcef.so with its resources in Release/.  The cefclient code the editors are
# built on comes from the sources of the same CEF release, in src/cef/freebsd.

CEF_ROOT_PATH = %%LOCALBASE%%/lib/cef
CEF_SRC_PATH = $$PWD/../src/cef/freebsd

# The installed headers go first, they include the generated ones.
INCLUDEPATH += $$CEF_ROOT_PATH $$CEF_SRC_PATH

DEFINES += \
    __STD_C \
    USING_CEF_SHARED \
    NDEBUG \
    WRAPPING_CEF_SHARED \
    NO_CSR

# The CEF headers need C++20.
CONFIG += c++2a
QMAKE_CXXFLAGS += -Wno-register

# CEF itself defines OS_FREEBSD and OS_BSD; the cefclient code only has the
# Linux (X11 and GTK) implementation, which is what FreeBSD uses.
DEFINES += OS_LINUX=1

LIBS += $$CEF_ROOT_PATH/libcef_dll_wrapper/libcef_dll_wrapper.a
LIBS += -L$$CEF_ROOT_PATH/Release -lcef
QMAKE_LFLAGS += -Wl,-rpath,$$CEF_ROOT_PATH/Release

CONFIG += link_pkgconfig
PKGCONFIG += glib-2.0 gtk+-3.0 atk
LIBS += -lX11 -lGL

QMAKE_CXXFLAGS += -fPIC
