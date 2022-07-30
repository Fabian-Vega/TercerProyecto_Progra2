#include "GameScene.hpp"
#include "SelectionPlate.hpp"

GameScene::GameScene(QSvgRenderer* renderer, QObject* parent)
  : QGraphicsScene(parent),
  renderer(renderer),
  background(nullptr) {
}

QGraphicsSvgItem* GameScene::setObject(
    QGraphicsSvgItem* object,
    const QString identifier,
    const double xPos,
    const double yPos){
  Q_ASSERT(object == nullptr);
  object = new QGraphicsSvgItem();
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

SelectionPlate* GameScene::setObject(
    SelectionPlate* object,
    const QString identifier,
    const double xPos,
    const double yPos){
  Q_ASSERT(object == nullptr);
  object = new SelectionPlate(this->renderer);
  Q_ASSERT(object);
  object->setGroup(identifier);
  object->setGroupPos(xPos, yPos);
  this->addGroup(object);
  return object;
}

void GameScene::addGroup(SelectionPlate* item) {
  Q_UNUSED(item);
}
