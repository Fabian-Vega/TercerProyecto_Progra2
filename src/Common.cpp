#include <QCoreApplication>
#include <QTime>
#include <QRandomGenerator>

#include "Common.hpp"

void wait(double seconds) {
    QTime stoppingTime = QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < stoppingTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int random(int min, int max) {
  return QRandomGenerator::global()->bounded(min, max+1);
}
