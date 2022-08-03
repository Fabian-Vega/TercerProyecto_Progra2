#include "InstructionsScene.hpp"

InstructionsScene::InstructionsScene(QSvgRenderer* renderer,
                                     QObject *parent)
  : GameScene(renderer, parent),
    goBackButton(nullptr) {
  this->setInstructions();
}

InstructionsScene::~InstructionsScene() {
  this->clear();
}

void InstructionsScene::setInstructions() {
  this->background = this->setObject(
                     this->background, QString("instructionBackground"),
                     0, 0);
  this->goBackButton = this->setObject(
                        this->goBackButton,
                        QString("backButton"),
                        319, 280);
  this->connect(this->goBackButton, &GameButton::pressed,
                this, &InstructionsScene::goBackPressed);
}
