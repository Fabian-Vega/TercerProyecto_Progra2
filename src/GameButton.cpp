#include <QGraphicsScene>
#include <QKeyEvent>

#include "GameButton.hpp"

GameButton::GameButton(QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem) {
  this->setFlags(QGraphicsItem::ItemIsFocusable);
  this->setFocus();
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  emit this->pressed();
}
