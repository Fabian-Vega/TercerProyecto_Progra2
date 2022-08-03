// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

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

 public: // Constructor and destructor
  CreditsScene(QSvgRenderer* renderer,
               QObject *parent = nullptr);
  ~CreditsScene();

 signals: // Signals
  void creditsEnded();

 protected slots: // Slots
  void finishCredits();

 public: // General functions
  void startCredits();

 protected: // Initializer
  void setCredits();
  QPropertyAnimation* setAnimation(
      QPropertyAnimation* animation,
      QGraphicsSvgItem* animatedObject,
      const double startValue,
      const double endValue);
};

#endif // CREDITSSCENE_HPP
