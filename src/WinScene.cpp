#include "WinScene.hpp"

WinScene::WinScene(QSvgRenderer* renderer,
                   QObject *parent)
  : GameScene(renderer, parent),
    message(nullptr),
    goBackButton() {
  this->setWinScene();
}

WinScene::~WinScene() {
  delete this->goBackButton;
}

void WinScene::setWinScene() {
  this->background = this->setObject(
                     this->background, QString("endBackground"),
                     0, 0);
  this->message = this->setObject(
                  this->message, QString("player1win"),
                  82, 15);
  this->goBackButton = this->setObject(
               this->goBackButton, QString("backButton"),
               319, 280);
  this->connect(this->goBackButton, &GameButton::pressed,
                this, &WinScene::backToMenu);
}

void WinScene::setWinner(size_t winner) {
  this->message->setElementId(QString("player%1win").arg(winner));
}
