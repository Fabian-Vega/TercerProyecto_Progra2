#include <QGraphicsSvgItem>

#include "MenuScene.hpp"

MenuScene::MenuScene(QObject *parent)
  : QGraphicsScene{parent} {
  this->setBackground();
}

void MenuScene::setBackground() {
  QGraphicsSvgItem* background =
  new QGraphicsSvgItem(
  QString(":/Backgrounds/Background.svg"));
  background->setPos(0, 0);
  this->addItem(background);
  this->setSceneRect(0, 0, 500, 500);
  this->setFocusItem(background);
}
