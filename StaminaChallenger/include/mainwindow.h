#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 游戏主窗口类
 * 负责UI界面显示和用户交互
 * 连接Character类的游戏逻辑与界面显示
 */
/**
 * @brief 游戏主窗口类
 * 继承自QMainWindow，获得标准主窗口功能
 * 
 * 继承实现说明：
 * 1. 使用public继承，表示"是一个"的关系  
 * 2. 继承QMainWindow获得以下能力：
 *    - 菜单栏、工具栏、状态栏
 *    - 中心窗口部件
 *    - 窗口管理功能
 * 3. 必须添加Q_OBJECT宏以启用信号槽
 * 
 * 多态实现说明：
 * 1. 通过信号槽实现运行时多态绑定
 * 2. 重写父类的虚函数(如closeEvent)
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT // 必须的Qt元对象系统宏

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 按钮点击处理
    void onAttackClicked();  // 攻击按钮点击处理
    void onRestClicked();    // 休息按钮点击处理
    void onDefendClicked();  // 防御按钮点击处理
    
    // 游戏状态处理
    void onGameWon();       // 游戏胜利处理
    void onGameLost();      // 游戏失败处理
    
    // 状态更新
    void updateHealthDisplay(int value);   // 更新生命值显示
    void updateStaminaDisplay(int value);  // 更新耐力值显示

private:
    Ui::MainWindow *ui;      // UI界面指针
    Character *m_character;  // 游戏角色实例
};

#endif // MAINWINDOW_H
