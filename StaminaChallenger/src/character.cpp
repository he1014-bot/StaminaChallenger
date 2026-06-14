#include "../include/character.h"
#include <QDebug>  // 添加QDebug头文件

/**
 * @brief 构造函数
 * @param parent 父对象指针
 */
Character::Character(QObject *parent) : QObject(parent) {}

/**
 * @brief 获取当前生命值
 * @return 当前生命值(0-100)
 */
int Character::health() const {
    return m_health;
}

/**
 * @brief 获取当前耐力值
 * @return 当前耐力值(0-100)
 */
int Character::stamina() const {
    return m_stamina;
}

/**
 * @brief 设置生命值
 * @param value 要设置的生命值(自动限制在0-100范围)
 * 触发healthChanged信号并检查游戏状态
 */
void Character::setHealth(int value) {
    m_health = qBound(0, value, 100);
    emit healthChanged(m_health);
    checkGameStatus();
}

/**
 * @brief 设置耐力值
 * @param value 要设置的耐力值(自动限制在0-100范围)
 * 触发staminaChanged信号并检查游戏状态
 */
void Character::setStamina(int value) {
    m_stamina = qBound(0, value, 100);
    emit staminaChanged(m_stamina);
    checkGameStatus();
}

/**
 * @brief 执行攻击动作
 * 算法：消耗10耐力，受到5点生命值伤害
 * 体现风险/回报机制：快速消耗耐力但会损失生命
 */
/**
 * @brief 执行攻击动作
 * 
 * 多态实现说明：
 * 1. 此方法可通过基类指针调用(多态基础)
 * 2. 如需完整多态支持，可：
 *    - 在头文件中声明为virtual:
 *      `virtual void attack();`
 *    - 允许子类重写此方法
 * 3. 当前通过信号槽实现行为扩展
 */
void Character::attack() {
    setStamina(m_stamina - 10); // 消耗耐力
    setHealth(m_health - 5);    // 受到伤害
    /* 多态扩展点：
     * 子类可重写此方法实现特殊攻击效果
     */
}

/**
 * @brief 执行休息动作
 * 算法：恢复15耐力和5生命值
 * 主要恢复手段，但需要策略性使用
 */
void Character::rest() {
    setStamina(m_stamina + 15);
    setHealth(m_health + 5);
}

/**
 * @brief 执行防御动作
 * 算法：恢复5耐力
 * 低风险恢复少量耐力
 */
void Character::defend() {
    setStamina(m_stamina + 5);
}

/**
 * @brief 检查游戏状态
 * 算法：根据生命值和耐力值判断游戏结果
 * 生命<=0触发失败，耐力>=100触发胜利
 */
void Character::checkGameStatus() {
    if (m_health <= 0) {
        emit gameLost();
    } else if (m_stamina >= 100) {
        emit gameWon();
    }
}

// 实现相等运算符重载
bool operator==(const Character& lhs, const Character& rhs) {
    return lhs.m_health == rhs.m_health &&
           lhs.m_stamina == rhs.m_stamina;
}

// 实现输出运算符重载
QDebug operator<<(QDebug debug, const Character& character) {
    debug << "Character(Health:" << character.m_health 
          << ", Stamina:" << character.m_stamina << ")";
    return debug;
}
