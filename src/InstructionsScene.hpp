// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef INSTRUCTIONSSCENE_HPP
#define INSTRUCTIONSSCENE_HPP

#include "GameScene.hpp"

class InstructionsScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(InstructionsScene)

 protected: // Attributes
  GameButton* goBackButton;

 public: // Constructor and Destructor
  explicit InstructionsScene(QSvgRenderer* renderer,
                             QObject *parent = nullptr);
  ~InstructionsScene();

 signals: // Signals
  void goBackPressed();

 protected: // Initializer
  void setInstructions();
};

#endif // INSTRUCTIONSSCENE_HPP
