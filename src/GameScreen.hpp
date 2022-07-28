#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>

#include "MenuScene.hpp"

class GameScreen : public QGraphicsView {
  Q_OBJECT

 protected:
  MenuScene menu;

 public:
  explicit GameScreen(QWidget *parent = nullptr);
};

#endif // GAMESCREEN_HPP
