#include <QPropertyAnimation>

#include "Common.hpp"
#include "CreditsScene.hpp"

CreditsScene::CreditsScene(
    QSvgRenderer* renderer,
    QObject* parent)
    : GameScene(renderer, parent),
    creditsp1(nullptr),
    creditsp2(nullptr),
    creditsp3(nullptr),
    creditsp4(nullptr) {
  this->setCredits();
}

void CreditsScene::finishCredits() {
  wait(3);
  emit this->creditsEnded();
}

void CreditsScene::setCredits() {
  this->background = this->setObject(
                     this->background, QString("blackBackground"),
                     0, 0);
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
}

void CreditsScene::startCredits() {
  QPropertyAnimation* firstPart =
      new QPropertyAnimation(this->creditsp1, "y");
  firstPart->setDuration(10000);
  firstPart->setStartValue(540);
  firstPart->setEndValue(-1860);
  firstPart->start();

  QPropertyAnimation* secondPart =
      new QPropertyAnimation(this->creditsp2, "y");
  secondPart->setDuration(10000);
  secondPart->setStartValue(1340);
  secondPart->setEndValue(-1060);
  secondPart->start();

  QPropertyAnimation* thirdPart =
      new QPropertyAnimation(this->creditsp3, "y");
  thirdPart->setDuration(10000);
  thirdPart->setStartValue(1710);
  thirdPart->setEndValue(-690);
  thirdPart->start();

  QPropertyAnimation* fourthPart =
      new QPropertyAnimation(this->creditsp4, "y");
  fourthPart->setDuration(10000);
  fourthPart->setStartValue(2301);
  fourthPart->setEndValue(-99);
  fourthPart->start();

  this->connect(fourthPart, &QPropertyAnimation::finished,
               this, &CreditsScene::finishCredits);
}

