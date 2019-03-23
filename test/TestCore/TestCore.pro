QT      += quick positioning qml
CONFIG  += c++11

SOURCES += \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# Impl
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/release/ -lbaseTypesImpl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/debug/ -lbaseTypesImpl
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/baseTypesImpl/ -lbaseTypesImpl

INCLUDEPATH += $$PWD/../../lib/static/baseTypesImpl
DEPENDPATH += $$PWD/../../lib/static/baseTypesImpl

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/release/libbaseTypesImpl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/debug/libbaseTypesImpl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/release/baseTypesImpl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/debug/baseTypesImpl.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypesImpl/libbaseTypesImpl.a

# Base types
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/release/ -lbaseTypes
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/debug/ -lbaseTypes
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/baseTypes/ -lbaseTypes

INCLUDEPATH += $$PWD/../../lib/static/baseTypes
DEPENDPATH += $$PWD/../../lib/static/baseTypes

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/release/libbaseTypes.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/debug/libbaseTypes.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/release/baseTypes.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/debug/baseTypes.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/baseTypes/libbaseTypes.a
