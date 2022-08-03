// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include <QGraphicsScene>
#include <QSoundEffect>

#include "Common.hpp"
#include "GameButton.hpp"

GameButton::GameButton(size_t buttonIdentifier,
                       QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    buttonIdentifier(buttonIdentifier),
    click(clickSound),
    hover(hoverSound) {
  this->setAcceptHoverEvents(true),
  this->setFocus();
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  click.play(false);
  emit this->pressed(this->buttonIdentifier);
}

void GameButton::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
  Q_UNUSED(event);
  hover.play(false);
}
