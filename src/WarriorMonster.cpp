// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "WarriorMonster.hpp"

WarriorMonster::WarriorMonster(
    QSvgRenderer* renderer,
    size_t type,
    QGraphicsSvgItem* parent)
  : Monster(renderer, type, parent) {
  this->initializeMonster();
}

void WarriorMonster::loadMonster() {
  this->setElementId(
        QString("MonsterRight_%1_3").arg(this->elementalType));
}

void WarriorMonster::setStats() {
  this->health.maxHealth = 100;
  this->health.currentHealth = 100;
  this->attack = 124;
  this->defense = 110;
  this->speed = 85;
}

void WarriorMonster::changeOrientation(bool orientation) {
  this->setElementId(
        QString("Monster%1_%2_3").arg(
          (orientation? QString("Right"):QString("Left"))).arg(
          this->elementalType));
}
