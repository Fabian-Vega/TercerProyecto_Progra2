#include <QGraphicsScene>
#include <QSoundEffect>

#include "Common.hpp"
#include "GameButton.hpp"

GameButton::GameButton(size_t buttonIdentifier,
                       QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    buttonIdentifier(buttonIdentifier),
    clickSound(nullptr),
    moveSound(nullptr) {
  this->setSounds();
  this->setFlags(QGraphicsItem::ItemIsFocusable);
  this->setFocus();
}

void GameButton::setSounds() {
  this->clickSound = new QSoundEffect(this);
  this->clickSound->setSource(clickTrack);
  this->clickSound->setVolume(generalVolume);

  this->moveSound = new QSoundEffect(this);
  this->moveSound->setSource(moveTrack);
  this->moveSound->setVolume(generalVolume);
}

void GameButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  this->clickSound->play();
  emit this->pressed(this->buttonIdentifier);
}

void GameButton::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  this->moveSound->play();
}
