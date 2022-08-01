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
  this->health.maxHealth = 70;
  this->health.currentHealth = 70;
  this->attack = 120;
  this->defense = 65;
  this->speed = 125;
}

void SpeedsterMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_2").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
