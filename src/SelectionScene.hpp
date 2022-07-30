#ifndef SELECTIONSCENE_H
#define SELECTIONSCENE_H

#include "GameScene.hpp"

class SelectionPlate;

class SelectionScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(SelectionScene)

 protected:
  SelectionPlate* firstPlayerPlate;
  SelectionPlate* secondPlayerPlate;
  GameButton* continueButton;

 public:
  explicit SelectionScene(QSvgRenderer* renderer,
                           QObject *parent = nullptr);
 signals:
  void continuePressed();

 protected:
  void addGroup(SelectionPlate* group) override;
  void setSelection();
};

#endif // SELECTIONSCENE_H
