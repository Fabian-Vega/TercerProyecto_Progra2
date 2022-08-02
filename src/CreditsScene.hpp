#ifndef CREDITSSCENE_HPP
#define CREDITSSCENE_HPP

#include "GameScene.hpp"

// Forward declaration
class QPropertyAnimation;

class CreditsScene : public GameScene {
 Q_OBJECT

 protected:
  QGraphicsSvgItem* developers;
  QGraphicsSvgItem* thirdPartys;
  QGraphicsSvgItem* musicCredits;
  QGraphicsSvgItem* thanks;

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
