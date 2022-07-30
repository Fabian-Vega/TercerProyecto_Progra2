#ifndef INSTRUCTIONSSCENE_HPP
#define INSTRUCTIONSSCENE_HPP

#include "GameScene.hpp"

class InstructionsScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(InstructionsScene)

 protected:
  GameButton* goBackButton;

 public:
  explicit InstructionsScene(QSvgRenderer* renderer,
                             QObject *parent = nullptr);
 signals:
  void goBackPressed();

 protected:
  void setInstructions();
};

#endif // INSTRUCTIONSSCENE_HPP
