#include "FightScene.hpp"
#include "HealthBar.hpp"
#include "Monster.hpp"
#include "MovesetLayout.hpp"

static const double outOfScreenX = 1690;
static const double outOfScreenY = 1690;

FightScene::FightScene(QSvgRenderer* renderer,
                       Monster* player1,
                       Monster* player2,
                       QObject *parent)
  : GameScene(renderer, parent),
    player1(player1),
    player2(player2),
    player1HealthBar(new HealthBar(renderer, player1)),
    player2HealthBar(new HealthBar(renderer, player1)),
    player1Moveset(new MovesetLayout(renderer, player1)),
    player2Moveset(new MovesetLayout(renderer, player2)) {
  this->setFight();
}

void FightScene::swapFight(short move) {
  this->movesChosen[0] = move;
  this->player1->flip(false);
  this->player1HealthBar->flip(false);
  this->player2->flip(true);
  this->player2HealthBar->flip(true);
  this->player1->setPos(450, 26);
  this->player2->setPos(140, 120);
  this->player1Moveset->setLayoutPos(outOfScreenX, outOfScreenX);
  this->player2Moveset->setLayoutPos(20, 280);
}

void FightScene::fight(short move) {
  this->movesChosen[1] = move;
  this->resolveAttack(this->player1, this->player2, 1);
  this->resolveAttack(this->player2, this->player1, 2);

  if (this->player1->getSpeed() >= this->player2->getSpeed()) {
    this->player1HealthBar->updateHealthBar(
          this->player1->getCurrentHealth());
    this->player2HealthBar->updateHealthBar(
          this->player2->getCurrentHealth());
  } else {
    this->player2HealthBar->updateHealthBar(
          this->player2->getCurrentHealth());
    this->player1HealthBar->updateHealthBar(
          this->player1->getCurrentHealth());
  }
  this->player1->flip(true);
  this->player1HealthBar->flip(true);
  this->player2->flip(false);
  this->player2HealthBar->flip(false);
  this->player1->setPos(140, 120);
  this->player2->setPos(450, 26);
  this->player1Moveset->setLayoutPos(20, 280);
  this->player2Moveset->setLayoutPos(outOfScreenX, outOfScreenX);

}

void FightScene::setFight() {
  this->background = this->setObject(
                     this->background, QString("fightBackground"),
                     0, 0);
  this->player1->setPos(140, 120);
  this->addItem(this->player1);
  this->player2->flip(false);
  this->player2->setPos(450, 26);
  this->addItem(this->player2);
  this->player1HealthBar->setHealthPos(20, 20);
  this->addHealthBar(this->player1HealthBar);
  this->player2HealthBar->flip(false);
  this->player2HealthBar->setHealthPos(670, 20);
  this->addHealthBar(this->player2HealthBar);
  this->player1Moveset->setLayoutPos(20, 280);
  this->addMoves(this->player1Moveset);
  this->connect(this->player1Moveset, &MovesetLayout::moveSelected,
                this, &FightScene::swapFight);
  this->player2Moveset->setLayoutPos(outOfScreenX, outOfScreenY);
  this->addMoves(this->player2Moveset);
  this->connect(this->player2Moveset, &MovesetLayout::moveSelected,
                this, &FightScene::fight);
}

void FightScene::addMoves(MovesetLayout* moves) {
  this->addItem(moves->getBase());
  this->addItem(moves->getDamageButton());
  this->addItem(moves->getDefenseButton());
  this->addItem(moves->getBuffButton());
  this->addItem(moves->getDebuffButton());
}

void FightScene::addHealthBar(HealthBar* healthbar) {
  this->addItem(healthbar->getFrame());
  this->addItem(healthbar->getBar());
}

void FightScene::resolveAttack(Monster* attacker,
                              Monster* receiver,
                              short attackerNum){
  short receiverNum = 2-(attackerNum--);
  if (this->movesChosen[receiverNum] == 2 &&
      this->movesChosen[attackerNum] != 2) {
    if (receiver->useMove(2, receiver) &&
        this->movesChosen[attackerNum] == 1) {
      return;
    }
    attacker->useMove(this->movesChosen[attackerNum],
        this->movesChosen[attackerNum] == 3?
          attacker : receiver);
  }
}
