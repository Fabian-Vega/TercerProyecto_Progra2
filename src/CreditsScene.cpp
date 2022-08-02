#include <QPropertyAnimation>

#include "Common.hpp"
#include "CreditsScene.hpp"

CreditsScene::CreditsScene(
    QSvgRenderer* renderer,
    QObject* parent)
    : GameScene(renderer, parent),
    creditsp1(nullptr),
    creditsp2(nullptr) {
  this->setCredits();
  this->startCredits();
}

void CreditsScene::setCredits() {
  this->background = this->setObject(
                     this->background, QString("blackBackground"),
                     0, 0);
  this->creditsp1 = this->setObject(
                 this->creditsp1, QString("credits1"),
                    320, 500);
  this->creditsp2 = this->setObject(
                 this->creditsp2, QString("credits2"),
                    240, 1330);
}

void CreditsScene::startCredits() {
  QPropertyAnimation* firstPart =
      new QPropertyAnimation(this->creditsp1, "y");
  firstPart->setDuration(50000);
  firstPart->setStartValue(500);
  firstPart->setEndValue(-610);
  firstPart->start();

  QPropertyAnimation* secondPart =
      new QPropertyAnimation(this->creditsp2, "y");
  secondPart->setDuration(50000);
  secondPart->setStartValue(1320);
  secondPart->setEndValue(-610);
  secondPart->start();

  emit this->creditsEnded();
}

