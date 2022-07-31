#include "Common.hpp"
#include "FightScene.hpp"
#include "HealthBar.hpp"
#include "Monster.hpp"
#include "MovesetLayout.hpp"

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
    player2Moveset(new MovesetLayout(renderer, player2)),
    message(nullptr) {
  this->setFight();
}

void FightScene::swapFight(short move) {
  this->movesChosen[0] = move;
  this->player1->flip(false);
  this->player1HealthBar->flip(false);
  this->player2->flip(true);
  this->player2HealthBar->flip(true);
  this->player1->setPos(470, 26);
  this->player2->setPos(140, 120);
  this->player1Moveset->setLayoutPos(outOfScreenX, outOfScreenX);
  this->player2Moveset->setLayoutPos(20, 280);
}

void FightScene::fight(short move) {
  this->movesChosen[1] = move;

  if (this->player1->getSpeed() >= this->player2->getSpeed()) {
    this->resolveAttack(this->player1, this->player2, 1);
    this->player1HealthBar->updateHealthBar(
          this->player1->getCurrentHealth());
    this->resolveAttack(this->player2, this->player1, 2);
    this->player2HealthBar->updateHealthBar(
          this->player2->getCurrentHealth());
  } else {
    this->resolveAttack(this->player2, this->player1, 2);
    this->player2HealthBar->updateHealthBar(
          this->player2->getCurrentHealth());
    this->resolveAttack(this->player1, this->player2, 1);
    this->player1HealthBar->updateHealthBar(
          this->player1->getCurrentHealth());
  }
  this->player1->flip(true);
  this->player1HealthBar->flip(true);
  this->player2->flip(false);
  this->player2HealthBar->flip(false);
  this->player1->setPos(140, 120);
  this->player2->setPos(470, 26);
  this->player1Moveset->setLayoutPos(20, 280);
  this->player2Moveset->setLayoutPos(outOfScreenX, outOfScreenX);

}

void FightScene::player1Won() {
  emit this->playerWon(1);
}

void FightScene::player2Won() {
  emit this->playerWon(2);
}

void FightScene::setFight() {
  this->background = this->setObject(
                     this->background, QString("fightBackground"),
                     0, 0);
  this->player1->setPos(140, 120);
  this->addItem(this->player1);
  this->player2->flip(false);
  this->player2->setPos(470, 26);
  this->addItem(this->player2);
  this->player1HealthBar->setHealthPos(20, 20);
  this->addHealthBar(this->player1HealthBar);
  this->connect(this->player1HealthBar, &HealthBar::monsterDied,
                this, &FightScene::player1Won);
  this->player2HealthBar->flip(false);
  this->player2HealthBar->setHealthPos(670, 20);
  this->addHealthBar(this->player2HealthBar);
  this->connect(this->player2HealthBar, &HealthBar::monsterDied,
                this, &FightScene::player2Won);
  this->player1Moveset->setLayoutPos(20, 280);
  this->addMoves(this->player1Moveset);
  this->connect(this->player1Moveset, &MovesetLayout::moveSelected,
                this, &FightScene::swapFight);
  this->player2Moveset->setLayoutPos(outOfScreenX, outOfScreenY);
  this->addMoves(this->player2Moveset);
  this->connect(this->player2Moveset, &MovesetLayout::moveSelected,
                this, &FightScene::fight);
  this->message = this->setObject(
                  this->message, QString(""),
                  outOfScreenX, outOfScreenY);
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
  if (this->movesChosen[receiverNum] == 2) {
    this->showMessage(receiverNum+1, 2);
    if (receiver->useMove(2, receiver) &&
        this->movesChosen[attackerNum] == 1) {
      this->showMessage(attackerNum+1, 1);
      this->showMessage(attackerNum+1, 5);
      return;
    }
    this->showMessage(receiverNum+1, 5);
  }
  if (this->movesChosen[attackerNum] != 2) {
    attacker->useMove(this->movesChosen[attackerNum],
        this->movesChosen[attackerNum] == 3?
          attacker : receiver);
    showMessage(attackerNum+1,
                (this->movesChosen[attackerNum] == 3?
                   (attacker->getBuffStat() == 1?
                      6:this->movesChosen[attackerNum])
                 :this->movesChosen[attackerNum]));
  }
}

void FightScene::showMessage(const short player,
                             const short action) {
  if (action == 5) {
    this->message->setElementId(QString("failed"));
  } else {
    this->message->setElementId(
          QString("player_%1_%2").arg(player).arg(action));
  }
  this->message->setPos(20, 280);
  wait(2);
  this->message->setPos(outOfScreenX, outOfScreenY);
}
