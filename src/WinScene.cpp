#include "WinScene.hpp"

WinScene::WinScene(QSvgRenderer* renderer,
                   size_t winner,
                   QObject *parent)
  : GameScene(renderer, parent),
    message(nullptr),
    back() {
  this->setWinScene(winner);
}

WinScene::~WinScene() {
  delete this->back;
}

void WinScene::setWinScene(size_t winner) {
  this->background = this->setObject(
                     this->background, QString("endBackground"),
                     0, 0);
  this->message = this->setObject(
                  this->message, QString("player%1win").arg(winner),
                  82, 15);
  this->back = this->setObject(
               this->back, QString("backButton"),
               319, 280);
  this->connect(this->back, &GameButton::pressed,
                this, &WinScene::backToMenu);
}
