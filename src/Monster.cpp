#include <QSvgRenderer>

#include "Common.hpp"
#include "BuffMove.hpp"
#include "DamageMove.hpp"
#include "DefenseMove.hpp"
#include "Monster.hpp"
#include "Move.hpp"

Monster::Monster(QSvgRenderer* renderer,
                 size_t element,
                 QGraphicsSvgItem *parent)
  : QGraphicsSvgItem(parent),
    renderer(renderer),
    attack(0),
    defense(0),
    speed(0),
    elementalType(element),
    moveset(4){
}

/// Destructor
Monster::~Monster() {
  for (size_t move = 0; move < moveset.size(); ++move) {
    delete this->moveset[move];
    this->moveset[move] = nullptr;
  }
}

// Monster Initializer method
void Monster::initializeMonster() {
  this->setSharedRenderer(this->renderer);
  this->loadMonster();
  this->setStats();
  this->setMoveset();
}

/// Move initializer method
/// Acts as a pseudo factory
void Monster::setMoveset() {
  this->moveset[0] = new DamageMove(30);
  this->moveset[1] = new DefenseMove();

  this->buffStat = random(1, 4);
  this->moveset[2] = new BuffMove(this->buffStat, 1.3);

  this->debuffStat = random(2, 4);
  this->moveset[3] = new BuffMove(this->debuffStat, 0.7);
}

void Monster::flip(bool orientation) {
  this->changeOrientation(orientation);
}

/// General functions
/// Returns 0.5 if the firstType is weak to the
/// second
/// Returns 1.0 if the firstType is equal to the second
/// Returns a number 1.5 if the firstType is strong to the
/// second
/// @remark Behavior using numbers higher than 3 or lower
/// than 1 is undefined
double Monster::typeRelation(const int firstType,
  const int secondType) {
  if (firstType == secondType) {return 1.0;
  } else if (abs(firstType - secondType) < 2 &&
    firstType > secondType) {return 1.5;
  } else if (secondType == 2) {return 0.5;
  } else {return firstType == 1? 1.5:0.5; }
}
