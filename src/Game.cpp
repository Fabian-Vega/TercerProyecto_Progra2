#include "Game.hpp"
#include "GameScreen.hpp"

Game::Game(int& argc, char** argv)
  : QApplication(argc, argv),
    screen(nullptr) {
}

Game::~Game() {
  delete this->screen;
}

int Game::run() {
  Q_ASSERT(this->screen == nullptr);
  this->screen = new GameScreen();
  Q_ASSERT(this->screen);
  this->screen->show();
  this->exec();
  return 0;
}
