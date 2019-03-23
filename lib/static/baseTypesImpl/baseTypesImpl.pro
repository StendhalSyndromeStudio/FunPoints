QT          += network
QT          -= gui

TARGET      = baseTypesImpl
TEMPLATE    = lib
CONFIG      += staticlib

HEADERS += \
    impl/fp_core.h

SOURCES += \
    impl/fp_core.cpp

# Base types
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../baseTypes/release/ -lbaseTypes
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../baseTypes/debug/ -lbaseTypes
else:unix: LIBS += -L$$OUT_PWD/../baseTypes/ -lbaseTypes

INCLUDEPATH += $$PWD/../baseTypes
DEPENDPATH += $$PWD/../baseTypes

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../baseTypes/release/libbaseTypes.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../baseTypes/debug/libbaseTypes.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../baseTypes/release/baseTypes.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../baseTypes/debug/baseTypes.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../baseTypes/libbaseTypes.a
