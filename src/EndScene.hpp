#ifndef ENDSCENE_H
#define ENDSCENE_H

#include "GameScene.hpp"

class EndScene : public GameScene {
 Q_OBJECT

 protected:
  QGraphicsSvgItem* message;
  GameButton* back;

 public:
  explicit EndScene(QSvgRenderer* renderer,
                    size_t winner,
                    QObject *parent = nullptr);
  ~EndScene();

 signals:
  void backToMenu();

 public slots:
  void setEndScene(size_t winner);
};

#endif // ENDSCENE_H
