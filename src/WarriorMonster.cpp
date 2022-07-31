#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "WarriorMonster.hpp"

WarriorMonster::WarriorMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
}

void WarriorMonster::setStats() {
  this->health.maxHealth = 90;
  this->health.currentHealth = 90;
  this->attack = 30;
  this->defense = 10;
  this->speed = 10;
}
