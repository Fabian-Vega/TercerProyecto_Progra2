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
   QGraphicsSvgItem* message;
   size_t movesChosen[2] = {0, 0};

 public:
  FightScene(QSvgRenderer* renderer,
             Monster* player1,
             Monster* player2,
             QObject *parent = nullptr);
  ~FightScene();

 signals:
  void playerWon(size_t player);

 protected slots:
  void changeTurn(size_t move);
  void fight(size_t move);
  void player1Won();
  void player2Won();

 protected:
  void setFight();
  void addMoves(MovesetLayout* moves);
  void addHealthBar(HealthBar* healthbar);
  void setMonster(Monster* monster,
                 const double xPos,
                 const double yPos);

  void setHealthBar(HealthBar* healthBar,
                 const size_t player,
                 const double xPos,
                 const double yPos);

  void setMoves(MovesetLayout* moves,
                 const size_t player,
                 const double xPos,
                 const double yPos);

 protected:
  void resolveAttack(Monster* attacker,
                     Monster* receiver,
                     size_t attackerNum);

  void showMessage(const size_t player,
                   const size_t action);

  void swapPositions(Monster* first, Monster* second,
                     HealthBar* firstHealthBar,
                     HealthBar* secondHealthBar,
                     MovesetLayout* firstMoveset,
                     MovesetLayout* secondMoveset);
};

#endif // FIGHTSCENE_HPP
