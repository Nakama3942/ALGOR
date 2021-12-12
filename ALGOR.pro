CONFIG -= qt

TEMPLATE = lib
DEFINES += ALGOR_LIBRARY

VERSION = 2.0.0

CONFIG += c++11
CONFIG += build_all

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ALGOR.hpp \
    ALGOR_global.h

SOURCES += \
    ALGOR.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
