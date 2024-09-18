QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../3rdparty/qtgifimage/src/gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ../c_mod/init_func/loader.c \
    ../c_mod/init_func/helper.c \
    ../c_mod/affine_func/rotation_x.c \
    ../c_mod/affine_func/rotation_y.c \
    ../c_mod/affine_func/rotation_z.c \
    ../c_mod/affine_func/scaling.c \
    ../c_mod/affine_func/x_offset.c \
    ../c_mod/affine_func/y_offset.c \
    ../c_mod/affine_func/z_offset.c \
    oglwidget.cpp

HEADERS += \
    mainwindow.h \
        ../c_mod/loader.h \
         ../c_mod/affine_func.h \
    oglwidget.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    ../tests/test_object.obj

LIBS += -lopengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
