# 指定项目依赖的Qt模块(widgets模块提供GUI组件)
QT += widgets

# 设置生成的可执行文件名称
TARGET = StaminaChallenger

# 指定项目类型为应用程序(app)
TEMPLATE = app

# 添加头文件搜索路径(include目录)
INCLUDEPATH += include

# 项目源文件列表
SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/character.cpp \
           src/gamelogger.cpp

# 项目头文件列表
HEADERS += include/mainwindow.h \
           include/character.h \
           include/gamelogger.h

# 项目UI表单文件
FORMS += ui/mainwindow.ui

# Windows平台特定配置(使用MinGW编译器)
win32 {
    QMAKE_CXX = g++
    QMAKE_CC = gcc
}
