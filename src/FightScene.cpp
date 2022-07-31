#include "FightScene.hpp"
#include "HealthBar.hpp"
#include "Monster.hpp"
#include "MovesetLayout.hpp"


FightScene::FightScene(QSvgRenderer* renderer,
                       Monster* player1,
                       Monster* player2,
                       QObject *parent)
  : GameScene(renderer, parent),
    attacker(player1),
    opponent(player2),
    attackerHealthBar(new HealthBar(renderer, player1)),
    opponentHealthBar(new HealthBar(renderer, player1)),
    attackerMoveset(new MovesetLayout(renderer, player1)),
    opponentMoveset(new MovesetLayout(renderer, player2)) {
}

void FightScene::swapFight() {

}

void FightScene::setFight() {
  this->background = this->setObject(
                     this->background, QString("fightBackground"),
                     0, 0);
  this->attacker->setPos(140, 120);
  this->addItem(this->attacker);
  this->attacker->setPos(450, 26);
  this->addItem(this->attacker);
  this->attackerHealthBar->setPos(-80, 120);
  this->addHealthBar(this->attackerHealthBar);

  this->addHealthBar(this->opponentHealthBar);

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
