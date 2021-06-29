QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = library
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Class_source\lib_book.cpp \
    Class_source\lib_file.cpp \
    Class_source\lib_group.cpp \
    Class_source\lib_user.cpp \
    main.cpp \
    Manage_form\manage.cpp \
    maplibrary.cpp \
    Rgister_login_form\register_login.cpp

HEADERS += \
    Class_source\lib_book.h \
    Class_source\lib_file.h \
    Class_source\lib_group.h \
    Class_source\lib_user.h \
    Manage_form\manage.h \
    maplibrary.h \
    Rgister_login_form\register_login.h

FORMS += \
    Manage_form\manage.ui \
    maplibrary.ui \
    Rgister_login_form\register_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

