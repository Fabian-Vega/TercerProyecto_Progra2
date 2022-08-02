#ifndef CREDITSSCENE_HPP
#define CREDITSSCENE_HPP

#include "GameScene.hpp"

// Forward declaration
class QPropertyAnimation;

class CreditsScene : public GameScene {
 Q_OBJECT

 protected:
  QTimer* timer;
  QGraphicsSvgItem* creditsp1;
  QGraphicsSvgItem* creditsp2;
  QGraphicsSvgItem* creditsp3;
  QGraphicsSvgItem* creditsp4;

  QPropertyAnimation* firstPart;
  QPropertyAnimation* secondPart;
  QPropertyAnimation* thirdPart;
  QPropertyAnimation* fourthPart;

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
  QPropertyAnimation* setAnimation(
      QPropertyAnimation* animation,
      QGraphicsSvgItem* animatedObject,
      const double startValue,
      const double endValue);
};

#endif // CREDITSSCENE_HPP
