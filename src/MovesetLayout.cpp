#include <QSvgRenderer>

#include "GameButton.hpp"
#include "MovesetLayout.hpp"
#include "Monster.hpp"

MovesetLayout::MovesetLayout(QSvgRenderer* renderer,
                             Monster* monster,
                             QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    renderer(renderer),
    damageMove(nullptr),
    defenseMove(nullptr),
    buffMove(nullptr),
    debuffMove(nullptr) {
  this->setMovesetLayout(monster);
}

void MovesetLayout::selectMove(short buttonNumber) {
  emit this->moveSelected(buttonNumber);
}

void MovesetLayout::setLayoutPos(
    const double xPos,
    const double yPos){
  this->setPos(xPos, yPos);
  this->damageMove->setPos(xPos, yPos);
  this->defenseMove->setPos(xPos, yPos);
  this->buffMove->setPos(xPos, yPos);
  this->debuffMove->setPos(xPos, yPos);
}

GameButton* MovesetLayout::setButton(
    GameButton* button,
    short buttonNumber,
    QString identifier) {
  Q_ASSERT(button == nullptr);
  button = new GameButton(buttonNumber);
  Q_ASSERT(button);
  button->setSharedRenderer(this->renderer);
  button->setElementId(identifier);
  this->connect(button, &GameButton::pressed,
                this, &MovesetLayout::selectMove);
  return button;
}

void MovesetLayout::setMovesetLayout(Monster* monster) {
  this->setSharedRenderer(this->renderer);
  this->setElementId(QString("MovesetBackground"));

  this->damageMove = this->setButton(this->damageMove, 1,
                                   QString("damageMove"));

  this->defenseMove = this->setButton(this->defenseMove, 2,
                                   QString("defenseMove"));

  this->buffMove = this->setButton(
                     this->buffMove, 3,
                     QString("buffMove0%1").arg(
                       monster->getBuffStat()));

  this->debuffMove = this->setButton(
                     this->debuffMove, 4,
                     QString("debuffMove0%1").arg(
                       monster->getBuffStat()));
}
