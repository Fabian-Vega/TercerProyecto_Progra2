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

  bool firstSelectionDone;
  bool secondSelectionDone;

 public:
  explicit SelectionScene(QSvgRenderer* renderer,
                           QObject *parent = nullptr);
  ~SelectionScene();

 signals:
  void continuePressed();

 protected slots:
  void finishFirstSelection();
  void finishSecondSelection();

 public:
  size_t getPlayerChoice (size_t player, size_t category);

 protected:
  void setSelection();
  SelectionPlate* setObject(SelectionPlate* object,
                 const QString identifier,
                 const double xPos,
                 const double yPos);
  void addGroup(SelectionPlate* group);
};

#endif // SELECTIONSCENE_H
