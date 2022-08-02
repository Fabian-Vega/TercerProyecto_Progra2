#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "GameScene.hpp"

class MenuScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(MenuScene)

 protected: // Attributes
  QGraphicsSvgItem* title;
  GameButton* playButton;
  GameButton* instrucctionsButton;
  GameButton* creditsButton;

 public: // Constructor and Destructor
  explicit MenuScene(QSvgRenderer* renderer,
                     QObject* parent = nullptr);
  ~MenuScene();

 signals: // Signals
  void playPressed();
  void instructionsPressed();
  void creditsPressed();

 protected: // Initializer
  void setMenu();
};

#endif // MENUSCENE_HPP
