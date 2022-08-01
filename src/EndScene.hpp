#ifndef ENDSCENE_H
#define ENDSCENE_H

#include "GameScene.hpp"

class EndScene : public GameScene {
 Q_OBJECT

 protected: // Attributes
  QGraphicsSvgItem* message;
  GameButton* back;

 public: // Constructor and Destructor
  explicit EndScene(QSvgRenderer* renderer,
                    size_t winner,
                    QObject *parent = nullptr);
  ~EndScene();

 signals: // Signals
  void backToMenu();

 public slots: // Initializer
  void setEndScene(size_t winner);
};

#endif // ENDSCENE_H
