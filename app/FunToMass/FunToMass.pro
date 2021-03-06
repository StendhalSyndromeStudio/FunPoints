QT += quick
QT += location positioning quickcontrols2 webview
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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

DISTFILES += \
    FilterringPage.qml

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/MarkerModel/release/ -lMarkerModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/MarkerModel/debug/ -lMarkerModel
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/MarkerModel/ -lMarkerModel

INCLUDEPATH += $$PWD/../../lib/static/MarkerModel
DEPENDPATH += $$PWD/../../lib/static/MarkerModel

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MarkerModel/release/libMarkerModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MarkerModel/debug/libMarkerModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MarkerModel/release/MarkerModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MarkerModel/debug/MarkerModel.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MarkerModel/libMarkerModel.a

###
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
###
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
