#ifndef WINSCENE_H
#define WINSCENE_H

#include "GameScene.hpp"

class WinScene : public GameScene {
 Q_OBJECT

 protected: // Attributes
  QGraphicsSvgItem* message;
  GameButton* back;

 public: // Constructor and Destructor
  explicit WinScene(QSvgRenderer* renderer,
                    size_t winner,
                    QObject *parent = nullptr);
  ~WinScene();

 signals: // Signals
  void backToMenu();

 public slots: // Initializer
  void setWinScene(size_t winner);
};

#endif // WINSCENE_H
