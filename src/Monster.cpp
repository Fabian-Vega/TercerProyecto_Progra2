#include <QSvgRenderer>

#include "BuffMove.hpp"
#include "DamageMove.hpp"
#include "DefenseMove.hpp"
#include "Monster.hpp"

Monster::Monster(QSvgRenderer* renderer,
                 short type,
                 QGraphicsSvgItem *parent)
  : QGraphicsSvgItem(parent),
    renderer(renderer),
    attack(0),
    defense(0),
    speed(0),
    elementalType(type),
    moveset(nullptr){
}

/// Destructor
Monster::~Monster() {
  for (size_t move = 0; move < 4; ++move) {
    delete this->moveset[move];
    this->moveset[move] = nullptr;
  }
}

// Monster Initializer method
void Monster::initializeMonster() {
  this->setStats();
  this->setMoveset();
}

/// Move initializer method
/// Acts as a pseudo factory
void Monster::setMoveset() {
  this->moveset[0] = new DamageMove(20);
  this->moveset[1] = new DefenseMove();

  srand(time(NULL));
  this->buffStat = 1 + rand() % 4;
  this->moveset[2] = new BuffMove(this->buffStat, 1.5);

  srand(time(NULL));
  this->debuffStat = 1 + rand() % 4;
  this->moveset[2] = new BuffMove(this->debuffStat, 0.5);
}

/// General functions
/// Returns 0.5 if the firstType is weak to the
/// second
/// Returns 1.0 if the firstType is equal to the second
/// Returns a number 1.5 if the firstType is strong to the
/// second
/// @remark Behavior using numbers higher than 2 is undefined
double Monster::typeRelation(const short firstType,
  const short secondType) {
  if (firstType == secondType) { return 1.0;
  } else if (abs(firstType - secondType) != 2 &&
    firstType > secondType) { return 1.5;
  } else if (secondType == 1) { return 0.5;
  } else { return firstType == 0? 1.5:0.5;}
}
