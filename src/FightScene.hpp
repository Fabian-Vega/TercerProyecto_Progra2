#ifndef FIGHTSCENE_HPP
#define FIGHTSCENE_HPP

#include "GameScene.hpp"

// Forward declarations
class HealthBar;
class Monster;
class MovesetLayout;

class FightScene : public GameScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(FightScene)

  protected:
   Monster* player1;
   Monster* player2;
   HealthBar* player1HealthBar;
   HealthBar* player2HealthBar;
   MovesetLayout* player1Moveset;
   MovesetLayout* player2Moveset;
   short movesChosen[2] = {0, 0};

 public:
   FightScene(QSvgRenderer* renderer,
              Monster* player1,
              Monster* player2,
              QObject *parent = nullptr);

 protected slots:
   void swapFight(short move);
   void fight(short move);

 protected:
   void setFight();
   void addMoves(MovesetLayout* moves);
   void addHealthBar(HealthBar* healthbar);

 protected:
   void resolveAttack(Monster* attacker,
                     Monster* receiver,
                     short attackerNum);
};

#endif // FIGHTSCENE_HPP
