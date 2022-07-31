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
   Monster* attacker;
   Monster* opponent;
   HealthBar* attackerHealthBar;
   HealthBar* opponentHealthBar;
   MovesetLayout* attackerMoveset;
   MovesetLayout* opponentMoveset;
   short attacksChose[2] = {0, 0};

 public:
   FightScene(QSvgRenderer* renderer,
              Monster* player1,
              Monster* player2,
              QObject *parent = nullptr);

 protected:
   void swapFight();
   void setFight();
   void addMoves(MovesetLayout* moves);
   void addHealthBar(HealthBar* healthbar);
};

#endif // FIGHTSCENE_HPP
