/*#include "SelectionScreen.hpp"

SelectionScreen::SelectionScreen(QSvgRenderer* renderer,
                                 QObject *parent)
  : GameScene(renderer, parent),
    continueButton(nullptr) {
    this->setSelection();
}

void SelectionScreen::setSelection(){
  this->background = this->setObject(
                     this->background, QString("menuBackground"),
                     0, 0);
  this->continueButton = this->setObject(
                     this->continueButton,
                     QString("playButton001"),
                     147.75, 260);
  this->connect(this->continueButton, &GameButton::pressed,
                this, &SelectionScreen::continuePressed);
}*/
