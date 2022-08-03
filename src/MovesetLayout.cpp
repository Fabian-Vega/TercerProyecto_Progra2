// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

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

void MovesetLayout::selectMove(size_t buttonNumber) {
  emit this->moveSelected(buttonNumber);
}

void MovesetLayout::setLayoutPos(
    const double xPos,
    const double yPos){
  this->setPos(xPos, yPos);
  this->damageMove->setPos(xPos+20, yPos+10);
  this->defenseMove->setPos(xPos+180, yPos+10);
  this->buffMove->setPos(xPos+350, yPos+10);
  this->debuffMove->setPos(xPos+510, yPos+10);
}

GameButton* MovesetLayout::setButton(
    GameButton* button,
    size_t buttonNumber,
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
  this->setElementId(QString("movesetLayout"));

  this->damageMove = this->setButton(this->damageMove, 1,
                                   QString("attackButton"));

  this->defenseMove = this->setButton(this->defenseMove, 2,
                                   QString("defenseButton"));

  this->buffMove = this->setButton(
                     this->buffMove, 3,
                     QString("buffButton_%1").arg(
                       monster->getBuffStat()));

  this->debuffMove = this->setButton(
                     this->debuffMove, 4,
                     QString("debuffButton_%1").arg(
                       monster->getDebuffStat()));
}
