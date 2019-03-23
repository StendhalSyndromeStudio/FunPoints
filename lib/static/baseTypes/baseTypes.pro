QT          -= gui
QT          += positioning qml
TARGET      = baseTypes
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11

HEADERS += \
    baseTypes/local_event/iexternal_resource.h \
    baseTypes/local_event/ilocal_event.h \
    baseTypes/local_event/ievent_storage.h \
    baseTypes/rate/ifeedback.h \
    baseTypes/rate/irate_object.h \
    baseTypes/ibase_signal_object.h \
    baseTypes/user/iperson.h \
    baseTypes/user/iuser.h \
    baseTypes/ifp_core.h \
    baseTypes/fpfilter.h

SOURCES += \
    baseTypes/local_event/iexternal_resource.cpp \
    baseTypes/local_event/ilocal_event.cpp \
    baseTypes/local_event/ievent_storage.cpp \
    baseTypes/rate/ifeedback.cpp \
    baseTypes/rate/irate_object.cpp \
    baseTypes/ibase_signal_object.cpp \
    baseTypes/user/iperson.cpp \
    baseTypes/user/iuser.cpp \
    baseTypes/ifp_core.cpp \
    baseTypes/fpfilter.cpp

DISTFILES += \
    IFpCore \
    IUser \
    IPerson \
    IFeedback \
    IRateObject \
    IEventStorage \
    IExternalResource \
    ILocalEvent
