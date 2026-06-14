QT += widgets
TARGET = StaminaChallenger
TEMPLATE = app

# 娣诲姞澶存枃浠舵悳绱㈣矾寰?
INCLUDEPATH += include

SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/character.cpp
HEADERS += include/mainwindow.h \
           include/character.h
FORMS += ui/mainwindow.ui

# Windows骞冲彴浣跨敤MinGW缂栬瘧鍣?
win32 {
    QMAKE_CXX = g++
    QMAKE_CC = gcc
}

== 操作指南 ==
1. 点击按钮选择行动
2. 平衡攻击和防御
3. 注意耐力管理
4. 达到100耐力获胜

== 开发特性 ==
- 使用C++17标准
- 采用Qt框架
- 包含面向对象特性：
  * 运算符重载
  * 友元类
  * 继承体系
  * 运行时多态
