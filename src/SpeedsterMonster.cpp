#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "SpeedsterMonster.hpp"

SpeedsterMonster::SpeedsterMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
}

void SpeedsterMonster::setStats() {
  this->health.maxHealth = 250;
  this->health.currentHealth = 250;
  this->attack = 10;
  this->defense = 10;
  this->speed = 30;
}
