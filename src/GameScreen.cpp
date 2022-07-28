#include "GameScreen.hpp"

GameScreen::GameScreen(QWidget *parent)
  : QGraphicsView{parent} {
  this->setScene(&this->menu);
}
