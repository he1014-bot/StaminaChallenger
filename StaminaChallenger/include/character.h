#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QProgressBar>

/**
 * @brief 游戏角色类，管理角色的生命值和耐力值状态
 * 实现游戏核心逻辑：攻击、休息、防御三种基本动作
 */
/**
 * @brief 游戏角色类
 * 继承自QObject，获得Qt对象系统的支持
 * 
 * 继承实现说明：
 * 1. 使用public继承，表示"是一个"的关系
 * 2. 继承QObject获得以下能力：
 *    - 信号槽通信机制
 *    - 对象树内存管理
 *    - 属性系统
 * 3. 必须添加Q_OBJECT宏以启用元对象系统
 */
class GameLogger; // 前向声明友元类

class Character : public QObject
{
    Q_OBJECT // 必须的Qt元对象系统宏
    friend class GameLogger; // 声明GameLogger为友元类
    friend bool operator==(const Character& lhs, const Character& rhs); // 声明友元运算符
    friend QDebug operator<<(QDebug debug, const Character& character); // 声明友元运算符

public:
    explicit Character(QObject *parent = nullptr);
    
    // 状态管理
    int health() const;  // 获取当前生命值
    int stamina() const; // 获取当前耐力值
    void setHealth(int value);  // 设置生命值(0-100范围)
    void setStamina(int value); // 设置耐力值(0-100范围)
    
    // 游戏动作
    void attack();  // 攻击动作：消耗耐力并受到伤害
    void rest();    // 休息动作：恢复耐力和生命值
    void defend();  // 防御动作：恢复少量耐力

signals:
    void gameWon();     // 游戏胜利信号(耐力>=100时触发)
    void gameLost();    // 游戏失败信号(生命<=0时触发)
    void healthChanged(int value);  // 生命值变化信号
    void staminaChanged(int value); // 耐力值变化信号


private:
    int m_health = 100;  // 当前生命值，初始100
    int m_stamina = 50;  // 当前耐力值，初始50
    
    void checkGameStatus();  // 检查游戏状态(胜利/失败条件)
};

#endif // CHARACTER_H
