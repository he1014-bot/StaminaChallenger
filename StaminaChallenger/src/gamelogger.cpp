#include "../include/gamelogger.h"
#include <QString>

GameLogger::GameLogger(QObject *parent) : QObject(parent) {}

QString GameLogger::getCharacterDetails(const Character& character) const
{
    // 作为友元类，可以直接访问Character的私有成员
    return QString("Character Details - Health: %1, Stamina: %2")
        .arg(character.m_health)
        .arg(character.m_stamina);
}
