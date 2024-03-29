// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

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

  protected: // Attributes
   Sound message;
   ///Monsters
   Monster* player1;
   Monster* player2;
   HealthBar* player1HealthBar;
   HealthBar* player2HealthBar;
   MovesetLayout* player1Moveset;
   MovesetLayout* player2Moveset;
   QGraphicsSvgItem* messageBox;
   size_t movesChosen[2] = {0, 0};

 public: // Constructor and Destructor
  FightScene(QSvgRenderer* renderer,
             Monster* player1,
             Monster* player2,
             QObject *parent = nullptr);
  ~FightScene();

 signals: // Signals
  void playerWon(size_t player);

 protected slots: // Slots
  void changeTurn(size_t move);
  void fight(size_t move);
  void player1Won();
  void player2Won();

 protected: // Initializers
  void setFight();
  void addMoves(MovesetLayout* moves);
  void addHealthBar(HealthBar* healthbar);
  void setMonster(Monster* monster,
                 const double xPos,
                 const double yPos);

  void setHealthBar(HealthBar* healthBar,
                 const size_t player,
                 const double xPos,
                 const double yPos,
                 const bool orientation);

  void setMoves(MovesetLayout* moves,
                 const size_t player,
                 const double xPos,
                 const double yPos);

 protected: // General Methods
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
