#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "TankMonster.hpp"

TankMonster::TankMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
  this->initializeMonster();
}

void TankMonster::loadMonster() {
  this->setSharedRenderer(this->renderer);
  this->setElementId(
        QString("MonsterRight_%1_1").arg(this->elementalType));
}

void TankMonster::setStats() {
  this->health.maxHealth = 95;
  this->health.currentHealth = 95;
  this->attack = 60;
  this->defense = 105;
  this->speed = 40;
}

void TankMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_1").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
