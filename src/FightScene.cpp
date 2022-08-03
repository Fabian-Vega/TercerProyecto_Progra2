// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

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
    message(messageSound, this),
    player1(player1),
    player2(player2),
    player1HealthBar(new HealthBar(renderer, player1)),
    player2HealthBar(new HealthBar(renderer, player2)),
    player1Moveset(new MovesetLayout(renderer, player1)),
    player2Moveset(new MovesetLayout(renderer, player2)),
    messageBox(nullptr) {
  this->setFight();
}

FightScene::~FightScene() {
  this->clear();
}

void FightScene::changeTurn(size_t move) {
  if (this->movesChosen[0] == 0) {
    this->movesChosen[0] = move;
    this->showMessage(2, 0);
    this->swapPositions(this->player1, this->player2,
                        this->player1HealthBar,
                        this->player2HealthBar,
                        this->player1Moveset,
                        this->player2Moveset);
  }
}

void FightScene::fight(size_t move) {
  if (this->movesChosen[1] == 0) {
    this->movesChosen[1] = move;

    if (this->player1->getSpeed() >= this->player2->getSpeed()) {
      this->resolveAttack(this->player1, this->player2, 1);
      this->player2HealthBar->updateHealthBar(
            this->player2->getCurrentHealth(), true);
      if (player2->isAlive()) {
        this->resolveAttack(this->player2, this->player1, 2);
        this->player1HealthBar->updateHealthBar(
              this->player1->getCurrentHealth(), false);
      }
    } else {
      this->resolveAttack(this->player2, this->player1, 2);
      this->player1HealthBar->updateHealthBar(
            this->player1->getCurrentHealth(), false);
      if (player1->isAlive()) {
        this->resolveAttack(this->player1, this->player2, 1);
        this->player2HealthBar->updateHealthBar(
              this->player2->getCurrentHealth(), true);
      }
    }

    wait(0.5);
    this->showMessage(1, 0);
    this->swapPositions(this->player2, this->player1,
                        this->player2HealthBar,
                        this->player1HealthBar,
                        this->player2Moveset,
                        this->player1Moveset);
    this->movesChosen[0] = 0;
    this->movesChosen[1] = 0;
  }
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
  this->setMonster(this->player1, 140, 120);
  this->player2->flip(false);
  this->setMonster(this->player2, 470, 26);

  this->setHealthBar(this->player1HealthBar, 1, 20, 20, true);
  this->player2HealthBar->flip(false);
  this->setHealthBar(this->player2HealthBar, 2, 670, 20, false);

  this->setMoves(this->player1Moveset, 1, 20, 280);
  this->setMoves(this->player2Moveset, 2, outOfScreenX, outOfScreenY);

  this->messageBox = this->setObject(
                  this->messageBox, QString(""),
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
                              size_t attackerNum){
  size_t receiverNum = 2-(attackerNum--);
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
    if (this->movesChosen[attackerNum] == 3) {
      showMessage(attackerNum+1,
                   (attacker->getBuffStat() == 1?
                      6 : this->movesChosen[attackerNum]));
    } else {
      showMessage(attackerNum+1,
                  this->movesChosen[attackerNum]);
    }
  }
}

void FightScene::showMessage(const size_t player,
                             const size_t action) {
  if (action == 5) {
    this->messageBox->setElementId(QString("failed"));
  } else {
    this->messageBox->setElementId(
          QString("player_%1_%2").arg(player).arg(action));
  }
  this->message.play(false);
  this->messageBox->setPos(20, 280);
  wait(2);
  this->messageBox->setPos(outOfScreenX, outOfScreenY);
}

void FightScene::swapPositions(Monster* first, Monster* second,
                               HealthBar* firstHealthBar,
                               HealthBar* secondHealthBar,
                               MovesetLayout* firstMoveset,
                               MovesetLayout* secondMoveset) {
  first->flip(false);
  firstHealthBar->flip(false);
  second->flip(true);
  secondHealthBar->flip(true);
  first->setPos(470, 26);
  second->setPos(140, 120);
  firstHealthBar->setHealthPos(670, 20, false);
  secondHealthBar->setHealthPos(20, 20, true);
  firstMoveset->setLayoutPos(outOfScreenX, outOfScreenX);
  secondMoveset->setLayoutPos(20, 280);
}

void FightScene::setMonster(Monster* monster,
                           const double xPos,
                           const double yPos) {
  monster->setPos(xPos, yPos);
  this->addItem(monster);
}

void FightScene::setHealthBar(HealthBar* healthBar,
                           const size_t player,
                           const double xPos,
                           const double yPos,
                           const bool orientation) {
  healthBar->setHealthPos(xPos, yPos, orientation);
  this->addHealthBar(healthBar);
  this->connect(healthBar, &HealthBar::monsterDied,
                this, (player == 1?
                      &FightScene::player2Won :
                      &FightScene::player1Won));
}

void FightScene::setMoves(MovesetLayout* moves,
                           const size_t player,
                           const double xPos,
                           const double yPos) {
  moves->setLayoutPos(xPos, yPos);
  this->addMoves(moves);
  this->connect(moves, &MovesetLayout::moveSelected,
                this, (player == 1?
                  &FightScene::changeTurn :
                  &FightScene::fight));
}
