SRC = $$system("git rev-parse --git-dir")
equals(SRC, ".git"){
    SRC = $$system("git rev-parse --show-toplevel")
}
else{
    SRC = $$replace(SRC, "\.git.*", "")
}
SRC = $$replace(SRC, "/$", "")

exists($$SRC/global) {
    INCLUDEPATH += $$SRC/global
    unix: {
        VERSION = $$system("bash $$SRC/global/build_tools/version-get.sh $$SRC")
    }
}
else {
    unix: {
        VERSION = $$system("bash $$SRC/build_tools/version-get.sh $$SRC")
    }
}

exists($$SRC/project.pri) {
    include($$SRC/project.pri)
}

unix:{
    MACHINE = $$system("uname -m")

    equals(MACHINE, "e2k") {
        QMAKE_CXXFLAGS += -Wall -Wno-unused-parameter
    }

    equals(MACHINE, "x86_64") {
        QMAKE_CXXFLAGS += -Wall -Werror -Wno-unused-parameter
    }
}
win32: {
    QMAKE_CXXFLAGS += -Wall -Werror -Wno-unused-parameter

    greaterThan(QT_VERSION, 5.14):
    {
        QMAKE_CXXFLAGS += -Wno-deprecated-declarations
    }
}
INCLUDEPATH += $$SRC

BUILD_DIR= $$SRC/build_dir

CONFIG += c++14
unix:{
    CONFIG += qt debug
}
win32:{
    CONFIG += qt
    CONFIG += debug|release
    message("$$CONFIG")
}

QMAKE_RPATHDIR = $$BUILD_DIR/lib

DESTDIR = $$BUILD_DIR

contains(TEMPLATE, ".*app") : {
    TARGET=bin/$$TARGET
    INCLUDEPATH += $$SRC

    win32 {
        DESTDIR = $$SRC\build_dir
        ARGS = --compiler-runtime --core --gui --network --widgets --winextras --no-svg --no-system-d3d-compiler --no-translations --no-opengl-sw --no-angle
        QMAKE_POST_LINK = windeployqt $$ARGS  $$shell_path($$DESTDIR/$${TARGET}.exe)
        message($$QMAKE_POST_LINK)
    }
}

contains(TEMPLATE, ".*lib") : {

    unix:{
        TARGET=lib/$$TARGET
    }
    win32:{
        TARGET=bin/$$TARGET
    }
    DESTDIR = $$BUILD_DIR
}

contains(TEMPLATE, ".*manual_test") :{
    TEMPLATE = app
    DESTDIR = $$BUILD_DIR
    TARGET=mtests/$$TARGET
}

contains(TEMPLATE, ".*test") : {
    TEMPLATE = app
    DESTDIR = $$BUILD_DIR
    QT += testlib
    CONFIG += testcase no_testcase_installs

    TARGET=unittest/$$TARGET
}

contains(TEMPLATE, ".*vplugin") : {
    TEMPLATE = lib
    TARGET=plugins/$$TARGET
    DESTDIR = $$BUILD_DIR
    CONFIG += unversioned_libname unversioned_soname
}


INCLUDEPATH += $$SRC

unix:{
    LIBS += -L$$SRC/build_dir/lib
}

win32:{
    LIBS += -L$$SRC/build_dir/bin
}
#-Wsuggest-override - этот флаг увы нельзя добавлять, т.к. google protobuf генерирует код без ключевого слова override

#Автоматически генерируемые moc,ui-файлы складываются в отдельный каталог
MOC_DIR=.moc
UI_DIR=.ui
RCC_DIR=.qrc
OBJECTS_DIR=.obj
QMAKE_DISTCLEAN += -r .moc .ui .qrc .obj

contains(DEFINES, LQWT) {
        INCLUDEPATH += $$SRC/build_dir/include
}

#Уровень оптимизации
QMAKE_CXXFLAGS_DEBUG += -O1
