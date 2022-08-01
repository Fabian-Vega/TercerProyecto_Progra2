#include <QGraphicsScene>
#include <QSoundEffect>

#include "Common.hpp"
#include "GameButton.hpp"

GameButton::GameButton(size_t buttonIdentifier,
                       QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    buttonIdentifier(buttonIdentifier),
    click(clickSound) {
  this->setFlags(QGraphicsItem::ItemIsFocusable);
  this->setFocus();
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  click.play(false);
  emit this->pressed(this->buttonIdentifier);
}
