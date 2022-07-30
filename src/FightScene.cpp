#include "FightScene.hpp"
#include "MovesetLayout.hpp"

FightScene::FightScene(QSvgRenderer* renderer,
                       Monster* player1,
                       Monster* player2,
                       QObject *parent)
  : GameScene(renderer, parent),
    attacker(player1),
    opponent(player2),
    attackerHealthBar(nullptr),
    opponentHealthBar(nullptr),
    attackerMoveset(new MovesetLayout(renderer, player1)),
    opponentMoveset(new MovesetLayout(renderer, player2)) {

}

void FightScene::setFight() {
  this->background = this->setObject(
                     this->background, QString("menuBackground"),
                     0, 0);

}

void FightScene::swapFight() {

}

void FightScene::addGroup(MovesetLayout* group) {
  this->addItem(group->getBase());
  this->addItem(group->getDamageButton());
  this->addItem(group->getDefenseButton());
  this->addItem(group->getBuffButton());
  this->addItem(group->getDebuffButton());
}
