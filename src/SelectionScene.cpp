#include "SelectionPlate.hpp"
#include "SelectionScene.hpp"

SelectionScene::SelectionScene(QSvgRenderer* renderer,
                                 QObject *parent)
  : GameScene(renderer, parent),
    firstPlayerPlate(nullptr),
    secondPlayerPlate(nullptr),
    continueButton(nullptr) {
  this->setSelection();
}

void SelectionScene::addGroup(SelectionPlate* group) {
  this->addItem(group->getBase());
  this->addItem(group->getElementHeader());
  this->addItem(group->getTypeHeader());
  this->addItem(group->getFireButton());
  this->addItem(group->getWaterButton());
  this->addItem(group->getPlantButton());
  this->addItem(group->getShieldButton());
  this->addItem(group->getBootButton());
  this->addItem(group->getSwordButton());
}

void SelectionScene::setSelection(){
  this->background = this->setObject(
                     this->background, QString("menuBackground"),
                     0, 0);
  this->firstPlayerPlate = this->setObject(
                           this->firstPlayerPlate,
                           QString("player1Base"),
                             50, 13);
  this->secondPlayerPlate = this->setObject(
                           this->secondPlayerPlate,
                           QString("player2Base"),
                             420, 13);
  this->continueButton = this->setObject(
                         this->continueButton,
                         QString("playButton001"),
                         147.75, 260);
  this->connect(this->continueButton, &GameButton::pressed,
                this, &SelectionScene::continuePressed);
}
