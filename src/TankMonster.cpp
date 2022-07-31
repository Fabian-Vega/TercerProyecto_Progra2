#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "TankMonster.hpp"

TankMonster::TankMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
}

void TankMonster::setStats() {
  this->health.maxHealth = 110;
  this->health.currentHealth = 110;
  this->attack = 15;
  this->defense = 30;
  this->speed = 5;
}
