#ifndef CREDITSSCENE_HPP
#define CREDITSSCENE_HPP

#include "GameScene.hpp"

// Forward declaration
class QPropertyAnimation;

class CreditsScene : public GameScene {
 Q_OBJECT

 protected: // Attributes
  QGraphicsSvgItem* developers;
  QGraphicsSvgItem* thirdPartys;
  QGraphicsSvgItem* musicCredits;
  QGraphicsSvgItem* thanks;

  QPropertyAnimation* firstPart;
  QPropertyAnimation* secondPart;
  QPropertyAnimation* thirdPart;
  QPropertyAnimation* fourthPart;

 public: // Constructors
  CreditsScene(QSvgRenderer* renderer,
               QObject *parent = nullptr);

 signals: // Signals
  void creditsEnded();

 protected slots: // General Methods
  void finishCredits();

 public: // Initializer
  void startCredits();

 protected: // Accesors(Sets and Gets)
  void setCredits();
  QPropertyAnimation* setAnimation(
      QPropertyAnimation* animation,
      QGraphicsSvgItem* animatedObject,
      const double startValue,
      const double endValue);
};

#endif // CREDITSSCENE_HPP
