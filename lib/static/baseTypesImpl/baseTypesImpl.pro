QT          += network positioning qml
QT          -= gui

TARGET      = baseTypesImpl
TEMPLATE    = lib
CONFIG      += staticlib

HEADERS += \
    impl/fp_core.h \
    impl/fp_core_provider.h \
    impl/tcp/tcp_client.h \
    impl/tcp/tcp_server.h \
    impl/server/fp_server.h \
    impl/server/fp_client.h \
    impl/server/fp_server_client.h \
    impl/server/cmd/iclient_cmd_handler.h \
    impl/server/cmd/iserver_cmd_handler.h \
    impl/server/cmd/cmd_handler_provider.h \
    impl/fp/test_local_event.h \
    impl/fp/test_event_storage.h \
    impl/server/cmd/client/event_storage_controller.h \
    impl/server/users_storage.h

SOURCES += \
    impl/fp_core.cpp \
    impl/fp_core_provider.cpp \
    impl/tcp/tcp_client.cpp \
    impl/tcp/tcp_server.cpp \
    impl/server/fp_server.cpp \
    impl/server/fp_client.cpp \
    impl/server/fp_server_client.cpp \
    impl/server/cmd/iclient_cmd_handler.cpp \
    impl/server/cmd/iserver_cmd_handler.cpp \
    impl/server/cmd/cmd_handler_provider.cpp \
    impl/fp/test_local_event.cpp \
    impl/fp/test_event_storage.cpp \
    impl/server/cmd/client/event_storage_controller.cpp \
    impl/server/users_storage.cpp

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

DISTFILES += \
    FpCoreProvider
