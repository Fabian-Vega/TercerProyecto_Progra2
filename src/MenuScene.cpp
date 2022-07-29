#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "MenuScene.hpp"

MenuScene::MenuScene(QSvgRenderer* renderer, QObject *parent)
  : QGraphicsScene{parent},
    renderer(renderer),
    background(nullptr),
    tittle(nullptr),
    playButton(nullptr),
    instrucctionsButton(nullptr) {
    this->setMenu();
}

QGraphicsSvgItem* MenuScene::setObject(QGraphicsSvgItem* object,
               const QString identifier,
               const double xPos,
               const double yPos) {
  Q_ASSERT(object == nullptr);
  object = new QGraphicsSvgItem();
  Q_ASSERT(object);
  object->setSharedRenderer(this->renderer);
  object->setElementId(identifier);
  object->setPos(xPos, yPos);
  this->addItem(object);
  return object;
}

void MenuScene::setMenu() {
  this->background =
  this->setObject(this->background, QString("menuBackground"),
                  0, 0);
  this->tittle =
  this->setObject(this->tittle, QString("menuTittle"),
                  147.75, 80);
  this->playButton =
  this->setObject(this->playButton, QString("playButton001"),
                  234, 260);
}

QGraphicsSvgItem* MenuScene::getBackground() {
  return this->background;
}
