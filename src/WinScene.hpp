#ifndef WINSCENE_H
#define WINSCENE_H

#include "GameScene.hpp"

class WinScene : public GameScene {
 Q_OBJECT

 protected: // Attributes
  QGraphicsSvgItem* message;
  GameButton* goBackButton;

 public: // Constructor and Destructor
  explicit WinScene(QSvgRenderer* renderer,
                    QObject *parent = nullptr);
  ~WinScene();

 signals: // Signals
  void backToMenu();

 public slots: // Initializer
  void setWinScene();

 public:
  void setWinner(size_t winner);
};

#endif // WINSCENE_H
