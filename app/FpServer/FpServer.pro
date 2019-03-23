#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T14:38:21
#
#-------------------------------------------------

QT       += core gui network qml positioning widgets

TARGET      = FpServer
TEMPLATE    = app
CONFIG      += c++11

HEADERS += \
        server_main_window.h

SOURCES += \
        main.cpp \
        server_main_window.cpp

FORMS += \
        server_main_window.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/release/ -lbaseTypesImpl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/debug/ -lbaseTypesImpl
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/ -lbaseTypesImpl

INCLUDEPATH += $$PWD/../../lib/static/baseTypesImpl
DEPENDPATH += $$PWD/../../lib/static/baseTypesImpl

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/release/libbaseTypesImpl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/debug/libbaseTypesImpl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/release/baseTypesImpl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/debug/baseTypesImpl.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/libbaseTypesImpl.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/release/ -lbaseTypes
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/debug/ -lbaseTypes
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/ -lbaseTypes

INCLUDEPATH += $$PWD/../../lib/static/baseTypes
DEPENDPATH += $$PWD/../../lib/static/baseTypes

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/release/libbaseTypes.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/debug/libbaseTypes.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/release/baseTypes.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/debug/baseTypes.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/libbaseTypes.a
