#include <QCoreApplication>
#include <QTime>
#include <QRandomGenerator>

#include "Common.hpp"
#include "Monster.hpp"
#include "Sound.hpp"

void wait(double seconds) {
    QTime stoppingTime = QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < stoppingTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int random(int min, int max) {
  return QRandomGenerator::global()->bounded(min, max+1);
}

QPropertyAnimation* createMoveAnimation(Monster* monster,
                                        size_t move) {
  QPropertyAnimation* animation;
  switch (move) {
    case 1:
      animation =
          new QPropertyAnimation(monster, "rotation");
      animation->setStartValue(0);
      animation->setEndValue(360);
    break;
    case 2:
      animation =
          new QPropertyAnimation(monster, "x");
      animation->setStartValue(monster->x());
      animation->setKeyValueAt(0.1, monster->x()+4);
      animation->setKeyValueAt(0.2, monster->x()-4);
      animation->setKeyValueAt(0.3, monster->x()+4);
      animation->setKeyValueAt(0.4, monster->x()-4);
      animation->setKeyValueAt(0.5, monster->x()+4);
      animation->setKeyValueAt(0.6, monster->x()-4);
      animation->setKeyValueAt(0.7, monster->x()+4);
      animation->setKeyValueAt(0.8, monster->x()-4);
      animation->setKeyValueAt(0.9, monster->x()+4);
      animation->setEndValue(monster->x());
    break;
    case 3:
      animation =
          new QPropertyAnimation(monster, "scale");
      animation->setStartValue(1);
      animation->setKeyValueAt(0.5, 2);
      animation->setEndValue(1);
    break;
    default:
      animation =
          new QPropertyAnimation(monster, "scale");
      animation->setStartValue(1);
      animation->setKeyValueAt(0.5, 0.5);
      animation->setEndValue(1);
    break;
  }
  animation->setDuration(500);

  return animation;
}

Sound* chooseSound(size_t move) {
  switch(move) {
    case 1:
      return new Sound(attackSound);
    break;
    case 2:
      return new Sound(defendSound);
    break;
    case 3:
      return new Sound(buffSound);
    break;
    default:
      return new Sound(debuffSound);
    break;
  }
}
