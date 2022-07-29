#include "InstructionsScene.hpp"

InstructionsScene::InstructionsScene(QSvgRenderer* renderer,
                                     QObject *parent)
  : GameScene(renderer, parent),
    instrucctions(nullptr),
    goBackButton(nullptr) {
  this->setInstructions();
}

void InstructionsScene::setInstructions() {
  this->background = this->setObject(
                     this->background, QString("instructionsBackground"),
                     0, 0);
  this->instrucctions = this->setObject(
                        this->instrucctions,
                        QString("instructionBook"),
                        10, 10);
  this->goBackButton = this->setObject(
                        this->goBackButton,
                        QString("playButton003"),
                        204, 380);
  this->connect(this->goBackButton, &GameButton::pressed,
                this, &InstructionsScene::goBackPressed);
}
