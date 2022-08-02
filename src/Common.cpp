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
    case attackMove:
      animation =
          new QPropertyAnimation(monster, "rotation");
      animation->setStartValue(0);
      animation->setEndValue(360);
    break;
    case defenseMove:
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
    case buffMove:
      animation =
          new QPropertyAnimation(monster, "scale");
      animation->setStartValue(1);
      animation->setKeyValueAt(0.5, 2);
      animation->setEndValue(1);
    break;
    default: // debuffMove
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
    case attackMove:
      return new Sound(attackSound);
    break;
    case defenseMove:
      return new Sound(defendSound);
    break;
    case buffMove:
      return new Sound(buffSound);
    break;
    default: // debuffMove
      return new Sound(debuffSound);
    break;
  }
}

/// General functions
/// Returns 0.5 if the firstType is weak to the
/// second
/// Returns 1.0 if the firstType is equal to the second
/// Returns a number 1.5 if the firstType is strong to the
/// second
/// @remark Behavior using numbers higher than 3 or lower
/// than 1 is undefined
double typeRelation(const int firstType,
  const int secondType) {
  if (firstType == secondType) {return 1.0;
  } else if (abs(firstType - secondType) < 2 &&
    firstType > secondType) {return 1.5;
  } else if (secondType == 2) {return 0.5;
  } else {return firstType == 1? 1.5:0.5; }
}
