#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

/**
 * @brief 构造函数
 * 初始化UI界面和游戏角色
 * 建立信号槽连接
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_character(new Character(this))
{
    ui->setupUi(this);

    // 连接角色信号
    connect(m_character, &Character::healthChanged, this, &MainWindow::updateHealthDisplay);
    connect(m_character, &Character::staminaChanged, this, &MainWindow::updateStaminaDisplay);
// 多态连接示例：信号动态绑定到槽
connect(
    m_character,  // 发送者对象(基类指针)
    &Character::gameWon,  // 信号(继承自QObject)
    this,         // 接收者对象 
    &MainWindow::onGameWon // 槽函数
);
/* 
 * 多态工作原理：
 * 1. 运行时确定实际调用的函数
 * 2. 不依赖具体类型，只依赖接口
 * 3. 允许后期添加新的信号/槽而不修改连接代码
 * 
 * 多态三要素：
 * 1. 继承 - Character继承QObject
 * 2. 虚函数 - 信号本质是虚函数
 * 3. 基类指针指向派生类对象 - m_character指向Character实例
 */
    connect(m_character, &Character::gameLost, this, &MainWindow::onGameLost);

    // 连接按钮信号
    connect(ui->attackBtn, &QPushButton::clicked, this, &MainWindow::onAttackClicked);
    connect(ui->restBtn, &QPushButton::clicked, this, &MainWindow::onRestClicked);
    connect(ui->defendBtn, &QPushButton::clicked, this, &MainWindow::onDefendClicked);

    // 初始化显示
    updateHealthDisplay(m_character->health());
    updateStaminaDisplay(m_character->stamina());
}

/**
 * @brief 析构函数
 * 清理UI资源
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 攻击按钮点击处理
 * 调用角色攻击动作并更新游戏日志
 */
void MainWindow::onAttackClicked()
{
    m_character->attack();
    ui->logTextEdit->append("> You attacked! (-10 Stamina, -5 Health)");
}

/**
 * @brief 休息按钮点击处理
 * 调用角色休息动作并更新游戏日志
 */
void MainWindow::onRestClicked()
{
    m_character->rest();
    ui->logTextEdit->append("> You rested! (+15 Stamina, +5 Health)");
}

/**
 * @brief 防御按钮点击处理
 * 调用角色防御动作并更新游戏日志
 */
void MainWindow::onDefendClicked()
{
    m_character->defend();
    ui->logTextEdit->append("> You defended! (+5 Stamina)");
}

/**
 * @brief 更新生命值显示
 * @param value 当前生命值
 * 更新进度条和标签显示
 */
void MainWindow::updateHealthDisplay(int value)
{
    ui->healthBar->setValue(value);
    ui->healthLabel->setText(QString("Health: %1").arg(value));
}

/**
 * @brief 更新耐力值显示
 * @param value 当前耐力值
 * 更新进度条和标签显示
 */
void MainWindow::updateStaminaDisplay(int value)
{
    ui->staminaBar->setValue(value);
    ui->staminaLabel->setText(QString("Stamina: %1").arg(value));
}

/**
 * @brief 游戏胜利处理
 * 显示胜利消息并弹出提示框
 */
void MainWindow::onGameWon()
{
    ui->logTextEdit->append("\n\n? YOU WON! Your stamina reached 100!");
    QMessageBox::information(this, "Victory!", "You completed the stamina challenge!");
}

/**
 * @brief 游戏失败处理
 * 显示失败消息并弹出提示框
 */
void MainWindow::onGameLost()
{
    ui->logTextEdit->append("\n\n? GAME OVER! Your health reached 0!");
    QMessageBox::critical(this, "Defeat", "You ran out of health!");
}
