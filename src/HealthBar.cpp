#include "Monster.hpp"
#include "HealthBar.hpp"

HealthBar::HealthBar(QSvgRenderer* renderer,
                     Monster* monster,
                     QGraphicsSvgItem *parent)
  : QGraphicsSvgItem(parent),
    renderer(renderer),
    currentHealth(),
    totalHealth(monster->getMaxHealth()),
    health(monster->getCurrentHealth()) {
  this->setHealthBar();
}

void HealthBar::setHealthBar() {
  this->setSharedRenderer(this->renderer);
  this->setElementId(QString("HealthFrame"));
  this->currentHealth = new QGraphicsSvgItem;
  Q_ASSERT(this->currentHealth);
  this->currentHealth->setSharedRenderer(this->renderer);
  this->setElementId(QString("GreenBar"));
}
