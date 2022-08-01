#ifndef ENDSCREEN_HPP
#define ENDSCREEN_HPP

#include "GameScene.hpp"

class EndScreen : public GameScene {
 Q_OBJECT

 protected:
  QGraphicsSvgItem* message;
  GameButton* back;

 public:
  explicit EndScreen(QSvgRenderer* renderer,
                     QObject *parent = nullptr);
  ~EndScreen();

 signals:
  void backToMenu();

 protected:
  void setEndScreen();
};

#endif // ENDSCREEN_HPP
