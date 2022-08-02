#include <QPropertyAnimation>
#include <QTimer>

#include "CreditsScene.hpp"

CreditsScene::CreditsScene(
    QSvgRenderer* renderer,
    QObject* parent)
    : GameScene(renderer, parent),
    developers(nullptr),
    thirdPartys(nullptr),
    musicCredits(nullptr),
    thanks(nullptr),
    firstPart(nullptr),
    secondPart(nullptr),
    thirdPart(nullptr),
    fourthPart(nullptr) {
  this->setCredits();
}

void CreditsScene::finishCredits() {
  this->firstPart->stop();
  this->secondPart->stop();
  this->thirdPart->stop();
  this->fourthPart->stop();

  emit this->creditsEnded();
}

void CreditsScene::setCredits() {
  this->background = this->setObject(
                     this->background, QString("blackBackground"),
                     0, 0);

  this->developers = this->setObject(
                 this->developers, QString("credits1"),
                    281, 540);
  this->firstPart = setAnimation(this->firstPart,
                                 this->developers,
                                 540, -1860);

  this->thirdPartys = this->setObject(
                 this->thirdPartys, QString("credits2"),
                    284.1, 1340);
  this->secondPart = setAnimation(this->secondPart,
                                 this->thirdPartys,
                                 1340, -1060);

  this->musicCredits = this->setObject(
                 this->musicCredits, QString("credits3"),
                    237.2, 1710);
  this->thirdPart = setAnimation(this->thirdPart,
                                 this->musicCredits,
                                 1710, -690);

  this->thanks = this->setObject(
                 this->thanks, QString("credits4"),
                      333.249, 2301);
  this->fourthPart = setAnimation(this->fourthPart,
                                 this->thanks,
                                 2301, -99);
  this->connect(this->fourthPart, &QPropertyAnimation::finished,
                this, &CreditsScene::finishCredits);
}

QPropertyAnimation* CreditsScene::setAnimation(
    QPropertyAnimation* animation,
    QGraphicsSvgItem* animatedObject,
    const double startValue,
    const double endValue) {
  animation =
      new QPropertyAnimation(animatedObject, "y");
  animation->setDuration(160000);
  animation->setStartValue(startValue);
  animation->setEndValue(endValue);
  return animation;
}

void CreditsScene::startCredits() {
  this->firstPart->start();
  this->secondPart->start();
  this->thirdPart->start();
  this->fourthPart->start();
}

