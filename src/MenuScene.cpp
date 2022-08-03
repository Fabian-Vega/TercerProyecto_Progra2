// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include "MenuScene.hpp"

MenuScene::MenuScene(QSvgRenderer* renderer, QObject* parent)
  : GameScene(renderer, parent),
    title(nullptr),
    playButton(nullptr),
    instrucctionsButton(nullptr),
    creditsButton(nullptr) {
  this->setMenu();
}

MenuScene::~MenuScene() {
  this->clear();
}

void MenuScene::setMenu() {
  this->background = this->setObject(
                     this->background, QString("menuBackground"),
                     0, 0);
  this->title = this->setObject(
                 this->title, QString("menuTittle"),
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
  this->creditsButton = this->setObject(
                     this->creditsButton,
                     QString("creditsButton"),
                     670, 10);
  this->connect(this->creditsButton, &GameButton::pressed,
                this, &MenuScene::creditsPressed);
}
