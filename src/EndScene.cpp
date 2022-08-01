#include "EndScene.hpp"

EndScene::EndScene(QSvgRenderer* renderer,
                   size_t winner,
                   QObject *parent)
  : GameScene(renderer, parent),
    message(nullptr),
    back() {
  this->setEndScene(winner);
}

EndScene::~EndScene() {
  delete this->back;
}

void EndScene::setEndScene(size_t winner) {
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
                this, &EndScene::backToMenu);
}
