#ifndef SELECTIONSCENE_H
#define SELECTIONSCENE_H

#include "GameScene.hpp"
// Forward Declarations
class SelectionPlate;

class SelectionScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(SelectionScene)

 protected: // Attributes
  SelectionPlate* firstPlayerPlate;
  SelectionPlate* secondPlayerPlate;
  GameButton* continueButton;

  bool firstSelectionDone;
  bool secondSelectionDone;

 public: // Constructor and Destructor
  explicit SelectionScene(QSvgRenderer* renderer,
                           QObject *parent = nullptr);
  ~SelectionScene();

 signals: // Signals
  void continuePressed();

 protected slots: // Slots
  void finishFirstSelection();
  void finishSecondSelection();

 public: // Accesor
  size_t getPlayerChoice (size_t player, size_t category);

 protected:
  void setSelection();
  SelectionPlate* setObject(SelectionPlate* object,
                 const QString identifier,
                 const double xPos,
                 const double yPos);
  /// addGroup Method
  void addGroup(SelectionPlate* group);
};

#endif // SELECTIONSCENE_H
