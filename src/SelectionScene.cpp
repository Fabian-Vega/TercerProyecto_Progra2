#include "SelectionPlate.hpp"
#include "SelectionScene.hpp"

SelectionScene::SelectionScene(QSvgRenderer* renderer,
                                 QObject *parent)
  : GameScene(renderer, parent),
    firstPlayerPlate(nullptr),
    secondPlayerPlate(nullptr),
    continueButton(nullptr),
    firstSelectionDone(false),
    secondSelectionDone(false) {
  this->setSelection();
}

SelectionScene::~SelectionScene() {
  delete this->firstPlayerPlate;
  delete this->secondPlayerPlate;
}

void SelectionScene::finishFirstSelection() {
  this->firstSelectionDone = true;
  if (this->secondSelectionDone) {
    this->continueButton->setElementId("continueButtonOn");
    this->connect(this->continueButton, &GameButton::pressed,
                  this, &SelectionScene::continuePressed);
  }
}

void SelectionScene::finishSecondSelection() {
  this->secondSelectionDone = true;
  if (this->firstSelectionDone) {
    this->continueButton->setElementId("continueButtonOn");
    this->connect(this->continueButton, &GameButton::pressed,
                  this, &SelectionScene::continuePressed);
  }
}

short SelectionScene::getPlayerChoice(
    short player, short category) {
  if (player == 1) {
    return (category == 1?
            this->firstPlayerPlate->getElementSelected():
            this->firstPlayerPlate->getTypeSelected());
  } else {
    return (category == 1?
            this->secondPlayerPlate->getElementSelected():
            this->secondPlayerPlate->getTypeSelected());
  }
}

void SelectionScene::setSelection(){
  this->background = GameScene::setObject(
                     this->background,
                     QString("menuBackground"),
                     0, 0);

  this->firstPlayerPlate = this->setObject(
                           this->firstPlayerPlate,
                           QString("player1Base"),
                             20, 13);
  this->connect(this->firstPlayerPlate, &SelectionPlate::selectionDone,
                this, &SelectionScene::finishFirstSelection);

  this->secondPlayerPlate = this->setObject(
                           this->secondPlayerPlate,
                           QString("player2Base"),
                             447, 13);
  this->connect(this->secondPlayerPlate, &SelectionPlate::selectionDone,
                this, &SelectionScene::finishSecondSelection);

  this->continueButton = GameScene::setObject(
                         this->continueButton,
                         QString("continueButtonOff"),
                         287, 155);
}

SelectionPlate* SelectionScene::setObject(
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
