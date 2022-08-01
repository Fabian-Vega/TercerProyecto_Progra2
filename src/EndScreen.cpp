#include "EndScreen.hpp"

EndScreen::EndScreen(QSvgRenderer* renderer,
                     QObject *parent)
  : GameScene(renderer, parent),
    message(nullptr),
    back() {

}

EndScreen::~EndScreen() {
  delete this->back;
}

void EndScreen::setEndScreen() {
  this->background = this->setObject(
                     this->background, QString("endBackground"),
                     0, 0);
  this->back = this->setObject(
                     this->back, QString("backButton"),
                     0, 0);
  this->connect(this->back, &GameButton::pressed,
                );

}
