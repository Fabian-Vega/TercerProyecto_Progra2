#include "MenuScene.hpp"

MenuScene::MenuScene(QSvgRenderer* renderer, QObject *parent)
  : GameScene(renderer, parent),
    tittle(nullptr),
    playButton(nullptr),
    instrucctionsButton(nullptr) {
    this->setMenu();
}

void MenuScene::setMenu() {
  this->background = this->setObject(
                     this->background, QString("menuBackground"),
                     0, 0);
  this->tittle = this->setObject(
                 this->tittle, QString("menuTittle"),
                 73.75, 20);
  this->playButton = this->setObject(
                     this->playButton,
                     QString("playButton"),
                     220, 250);
  this->connect(this->playButton, &GameButton::pressed,
                this, &MenuScene::playPressed);
  this->instrucctionsButton = this->setObject(
                     this->instrucctionsButton,
                     QString("helpButton"),
                     430, 250);
  this->connect(this->instrucctionsButton, &GameButton::pressed,
                this, &MenuScene::instructionsPressed);
}
