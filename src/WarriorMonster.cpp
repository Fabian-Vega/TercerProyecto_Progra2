#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "WarriorMonster.hpp"

WarriorMonster::WarriorMonster(
    QSvgRenderer* renderer,
    short type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
  this->initializeMonster();
}

void WarriorMonster::loadMonster() {
  this->setSharedRenderer(this->renderer);
  this->setElementId(
        QString("MonsterRight_%1_3").arg(this->elementalType));
}

void WarriorMonster::setStats() {
  this->health.maxHealth = 90;
  this->health.currentHealth = 90;
  this->attack = 30;
  this->defense = 10;
  this->speed = 10;
}

void WarriorMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_3").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
