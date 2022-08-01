#include <QGraphicsScene>
#include <QSoundEffect>

#include "Common.hpp"
#include "GameButton.hpp"

GameButton::GameButton(size_t buttonIdentifier,
                       QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    buttonIdentifier(buttonIdentifier),
    clickSound(nullptr) {
  this->setSound();
  this->setFlags(QGraphicsItem::ItemIsFocusable);
  this->setFocus();
}

void GameButton::setSound() {
  this->clickSound = new QSoundEffect(this);
  this->clickSound->setSource(clickTrack);
  this->clickSound->setVolume(generalVolume);
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  this->clickSound->play();
  emit this->pressed(this->buttonIdentifier);
}
