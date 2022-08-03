// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include <QPropertyAnimation>

#include <iostream>

#include "Monster.hpp"
#include "HealthBar.hpp"

HealthBar::HealthBar(QSvgRenderer* renderer,
                     Monster* monster,
                     QGraphicsSvgItem *parent)
  : QGraphicsSvgItem(parent),
    renderer(renderer),
    bar(),
    maxHealth(monster->getMaxHealth()),
    currentHealth(monster->getCurrentHealth()) {
  this->setHealthBar();
}

void HealthBar::updateHealthBar(const double newHealth,
                                const bool orientation){
  if (newHealth != this->currentHealth) {
    this->currentHealth = newHealth;
    int porcentage = this->getHealthPorcentage();
    porcentage = porcentage <= 0? 10 : porcentage;

    this->bar->setElementId(QString("bar_%1").arg(porcentage));
    this->setHealthPos(this->x(), this->y(), orientation);

    if (this->currentHealth <= 0) {
      emit this->monsterDied();
    }
  }
}



void HealthBar::setHealthPos(const double xPos,
                             const double yPos,
                             const bool orientation) {
  this->setPos(xPos, yPos);
  this->bar->setPos(xPos+10.5, yPos+(orientation?
                       this->upPos():18.5));
}

void HealthBar::flip(bool orientation) {
  this->setElementId(QString("HealthFrame%1").arg(
                       (orientation?
                          QString("Up"):QString("Down"))));
}

void HealthBar::setHealthBar() {
  this->setSharedRenderer(this->renderer);
  this->setElementId(QString("HealthFrameUp"));
  this->bar = new QGraphicsSvgItem;
  Q_ASSERT(this->bar);
  this->bar->setSharedRenderer(this->renderer);
  this->bar->setElementId(QString("bar_100"));
}

