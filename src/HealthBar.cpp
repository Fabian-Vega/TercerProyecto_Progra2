#include <QPropertyAnimation>

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

void HealthBar::updateHealthBar(const double newHealth){
  if (newHealth < this->currentHealth) {
    this->reduceHealthBar(newHealth);
  } else if (newHealth > this->currentHealth) {
    this->healHealthBar(newHealth);
  }
}



void HealthBar::setHealthPos(const double xPos,
                             const double yPos) {
  this->setPos(xPos, yPos);
  this->bar->setPos(xPos+10.5, yPos+18.5);
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
  this->bar->setElementId(QString("GreenBar"));
}

void HealthBar::healHealthBar(const double newHealth) {
  double movingDistance = newHealth/this->maxHealth
      - this->currentHealth/this->maxHealth;
  movingDistance *= 100;

  QPropertyAnimation* movingRight =
      new QPropertyAnimation(this->bar, "y");
  movingRight->setDuration(10000);
  movingRight->setStartValue(this->bar->y());
  movingRight->setEndValue(this->bar->y()+movingDistance);
  movingRight->start();
  this->currentHealth = newHealth;
  if (this->currentHealth/this->maxHealth > 0.2) {
    this->bar->setElementId("YellowBar");
  }
  if (this->currentHealth/this->maxHealth > 0.5) {
    this->bar->setElementId("GreenBar");
  }
}

void HealthBar::reduceHealthBar(const double newHealth) {
  double movingDistance = this->currentHealth/this->maxHealth
      - newHealth/this->maxHealth;
   movingDistance *= 100;

  QPropertyAnimation* movingLeft =
      new QPropertyAnimation(this->bar, "y");
  movingLeft->setDuration(10000);
  movingLeft->setStartValue(this->bar->y());
  movingLeft->setEndValue(this->bar->y()-movingDistance);
  movingLeft->start();
  this->currentHealth = newHealth;
  if (this->currentHealth/this->maxHealth < 0.5) {
    this->bar->setElementId("YellowBar");
  }
  if (this->currentHealth/this->maxHealth < 0.2) {
    this->bar->setElementId("RedBar");
  }

  if (currentHealth <= 0) {
    emit this->monsterDied();
  }
}
