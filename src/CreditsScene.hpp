#ifndef CREDITSSCENE_HPP
#define CREDITSSCENE_HPP

#include "GameScene.hpp"


class CreditsScene : public GameScene {
 Q_OBJECT

 protected:
  QGraphicsSvgItem* creditsp1;
  QGraphicsSvgItem* creditsp2;

 public:
  CreditsScene(QSvgRenderer* renderer,
               QObject *parent = nullptr);

 signals:
  void creditsEnded();

 protected:
  void setCredits();
  void startCredits();
};

#endif // CREDITSSCENE_HPP
