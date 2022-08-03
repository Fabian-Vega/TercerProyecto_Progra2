#include "GameScene.hpp"

GameScene::GameScene(QSvgRenderer* renderer, QObject* parent)
  : QGraphicsScene(parent),
  renderer(renderer),
  background(nullptr) {
}

GameScene::~GameScene() {
  this->clear();
}

QGraphicsSvgItem* GameScene::setObject(
    QGraphicsSvgItem* object,
    const QString identifier,
    const double xPos,
    const double yPos){
  if (object == nullptr) {
    object = new QGraphicsSvgItem();
  }
  Q_ASSERT(object);
  object->setSharedRenderer(this->renderer);
  object->setElementId(identifier);
  object->setPos(xPos, yPos);
  this->addItem(object);
  return object;
}

GameButton* GameScene::setObject(
    GameButton* object,
    const QString identifier,
    const double xPos,
    const double yPos){
  Q_ASSERT(object == nullptr);
  object = new GameButton();
  Q_ASSERT(object);
  object->setSharedRenderer(this->renderer);
  object->setElementId(identifier);
  object->setPos(xPos, yPos);
  this->addItem(object);
  return object;
}
