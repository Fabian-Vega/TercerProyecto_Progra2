#ifndef CREDITSSCENE_HPP
#define CREDITSSCENE_HPP

#include "GameScene.hpp"


class CreditsScene : public GameScene {
 Q_OBJECT

 protected:
  QGraphicsSvgItem* creditsp1;
  QGraphicsSvgItem* creditsp2;
  QGraphicsSvgItem* creditsp3;
  QGraphicsSvgItem* creditsp4;

 public:
  CreditsScene(QSvgRenderer* renderer,
               QObject *parent = nullptr);

 signals:
  void creditsEnded();

 protected slots:
  void finishCredits();

 public:
  void startCredits();

 protected:
  void setCredits();
};

#endif // CREDITSSCENE_HPP
