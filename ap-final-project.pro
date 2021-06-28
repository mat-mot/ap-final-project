QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = library
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib_book.cpp \
    lib_file.cpp \
    lib_group.cpp \
    lib_user.cpp \
    main.cpp \
    manage.cpp \
    maplibrary.cpp \
    register_login.cpp

HEADERS += \
    lib_book.h \
    lib_file.h \
    lib_group.h \
    lib_user.h \
    manage.h \
    maplibrary.h \
    register_login.h

FORMS += \
    manage.ui \
    maplibrary.ui \
    register_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

