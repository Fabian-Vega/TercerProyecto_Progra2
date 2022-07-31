#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "SpeedsterMonster.hpp"

SpeedsterMonster::SpeedsterMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
  this->initializeMonster();
}

void SpeedsterMonster::loadMonster() {
  this->setSharedRenderer(this->renderer);
  this->setElementId(
        QString("MonsterRight_%1_2").arg(this->elementalType));
}

void SpeedsterMonster::setStats() {
  this->health.maxHealth = 250;
  this->health.currentHealth = 250;
  this->attack = 10;
  this->defense = 10;
  this->speed = 30;
}

void SpeedsterMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_2").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
