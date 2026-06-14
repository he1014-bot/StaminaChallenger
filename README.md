# Stamina Challenger

一个基于 Qt 框架的 C++ 耐力挑战游戏。

## 项目简介

Stamina Challenger 是一款策略性耐力管理游戏，玩家需要在攻击、防御和休息之间做出平衡决策，管理生命值和耐力值两个核心资源，最终达到 100 耐力值获胜。

## 游戏规则

- **攻击**：消耗 10 耐力，减少 5 生命值
- **防御**：恢复 5 耐力
- **休息**：恢复 15 耐力，恢复 5 生命值
- **胜利条件**：耐力值达到 100
- **失败条件**：生命值降至 0

## 技术特性

- 使用 C++17 标准开发
- 基于 Qt 框架的图形界面
- 采用 MVC 架构设计
- 应用多种设计模式：
  - 有限状态机 (FSM)
  - 观察者模式
  - 策略模式
- 面向对象特性：运算符重载、友元类、继承体系、运行时多态

## 项目结构

```
StaminaChallenger/
├── include/          # 头文件
│   ├── character.h   # 角色类
│   ├── gamelogger.h  # 游戏日志类
│   └── mainwindow.h  # 主窗口类
├── src/              # 源文件
│   ├── main.cpp      # 程序入口
│   ├── mainwindow.cpp
│   ├── character.cpp
│   └── gamelogger.cpp
├── ui/               # UI 设计文件
│   └── mainwindow.ui
├── StaminaChallenger.pro  # Qt 项目文件
├── algorithm_explanation.txt  # 算法说明
└── README.txt        # 项目说明
```

## 构建要求

- Qt 5 或更高版本
- C++17 兼容的编译器 (如 MinGW, GCC, MSVC)
- qmake 构建工具

## 构建步骤

```bash
cd StaminaChallenger
qmake StaminaChallenger.pro
make
```

## 许可证

本项目仅供学习参考。
