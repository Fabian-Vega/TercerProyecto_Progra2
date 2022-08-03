// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef GAME_HPP
#define GAME_HPP

#include <QApplication>

// Forward declaration
class GameScreen;

class Game : public QApplication {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(Game)

 protected: // Attributes
  GameScreen* screen;

 public: // Constructor and Destructor
  explicit Game(int& argc, char** argv);
  ~Game();
  int run();
};

#endif // GAME_HPP
