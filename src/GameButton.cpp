#include <QGraphicsScene>

#include "GameButton.hpp"

GameButton::GameButton(size_t buttonIdentifier,
                       QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    buttonIdentifier(buttonIdentifier) {
  this->setFlags(QGraphicsItem::ItemIsFocusable);
  this->setFocus();
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  emit this->pressed(this->buttonIdentifier);
}
