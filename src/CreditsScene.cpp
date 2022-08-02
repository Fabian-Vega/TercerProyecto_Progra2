#include <QPropertyAnimation>
#include <QTimer>

#include "Common.hpp"
#include "CreditsScene.hpp"

CreditsScene::CreditsScene(
    QSvgRenderer* renderer,
    QObject* parent)
    : GameScene(renderer, parent),
    timer(new QTimer(this)),
    creditsp1(nullptr),
    creditsp2(nullptr),
    creditsp3(nullptr),
    creditsp4(nullptr),
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
  this->connect(this->timer, &QTimer::timeout,
                this, &CreditsScene::finishCredits);
  this->creditsp1 = this->setObject(
                 this->creditsp1, QString("credits1"),
                    281, 540);
  this->creditsp2 = this->setObject(
                 this->creditsp2, QString("credits2"),
                    284.1, 1340);
  this->creditsp3 = this->setObject(
                 this->creditsp3, QString("credits3"),
                    237.2, 1710);
  this->creditsp4 = this->setObject(
                 this->creditsp4, QString("credits4"),
                      333.249, 2301);

  this->firstPart = setAnimation(this->firstPart,
                                 this->creditsp1,
                                 540, -1860);

  this->secondPart = setAnimation(this->secondPart,
                                 this->creditsp2,
                                 1340, -1060);

  this->thirdPart = setAnimation(this->thirdPart,
                                 this->creditsp3,
                                 1710, -690);

  this->fourthPart = setAnimation(this->fourthPart,
                                 this->creditsp4,
                                 2301, -99);
}

QPropertyAnimation* CreditsScene::setAnimation(
    QPropertyAnimation* animation,
    QGraphicsSvgItem* animatedObject,
    const double startValue,
    const double endValue) {
  animation =
      new QPropertyAnimation(animatedObject, "y");
  animation->setDuration(5000);
  animation->setStartValue(startValue);
  animation->setEndValue(endValue);
  return animation;
}

void CreditsScene::startCredits() {
  this->timer->start(11000);
  this->firstPart->start();
  this->secondPart->start();
  this->thirdPart->start();
  this->fourthPart->start();
}

