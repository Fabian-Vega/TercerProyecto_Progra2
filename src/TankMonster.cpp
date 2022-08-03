// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "TankMonster.hpp"

TankMonster::TankMonster(
    QSvgRenderer* renderer,
    size_t type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
  this->initializeMonster();
}

void TankMonster::loadMonster() {
  this->setElementId(
        QString("MonsterRight_%1_1").arg(this->elementalType));
}

void TankMonster::setStats() {
  this->health.maxHealth = 80;
  this->health.currentHealth = 80;
  this->attack = 100;
  this->defense = 135;
  this->speed = 70;
}

void TankMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_1").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
