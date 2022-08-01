#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "GameScene.hpp"

class MenuScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(MenuScene)

 protected:
  QGraphicsSvgItem* title;
  GameButton* playButton;
  GameButton* instrucctionsButton;

 public:
  explicit MenuScene(QSvgRenderer* renderer,
                     QObject *parent = nullptr);
  ~MenuScene();

 signals:
  void playPressed();
  void instructionsPressed();

 protected:
  void setMenu();
};

#endif // MENUSCENE_HPP
