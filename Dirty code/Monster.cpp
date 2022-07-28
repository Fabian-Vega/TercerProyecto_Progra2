#include <cmath>

#include "DamageMove.hpp"
#include "DefenseMove.hpp"
#include "BuffMove.hpp"
#include "Monster.hpp"

/// Default constructor
FightMon::Monster::Monster(size_t type)
: health(0.0),
  attack(0),
  defense(0),
  speed(0),
  elementalType(type),
  moveset(nullptr) {
}

/// Destructor
FightMon::Monster::~Monster() {
  for (size_t move = 0; move < 4; ++move) {
    delete this->moveset[move];
    this->moveset[move] = nullptr;
  }
}

/// Monster Initializer method
void FightMon::Monster::initializeMonster() {
  this->setStats();
  this->setMoveset();
}

/// Move initializer method
/// Acts as a pseudo factory
void FightMon::Monster::setMoveset() {
  this->moveset[0] = new DamageMove(20);
  this->moveset[1] = new DefenseMove();
  
  srand(time(NULL));
  int randomStat = 1 + rand() % 4; 
  this->moveset[2] = new BuffMove(randomStat, 1.5);

  srand(time(NULL));
  randomStat = 1 + rand() % 4; 
  this->moveset[2] = new BuffMove(randomStat, 0.5);
}

/// Returns true if the monsters health is above 0.0
inline bool FightMon::Monster::isAlive() const {
  return this->health > 0.0;
}

/// Sets and gets
/// Returns the current value of the monsters health
inline double FightMon::Monster::getHealth() const {
  return this->health;
}

inline void FightMon::Monster::setHealth(
  const double health) {
  this->health = health;
}

/// Returns the current value of the monsters attack
inline int FightMon::Monster::getAttack() const {
  return this->attack;
}

inline void FightMon::Monster::setAttack(
  const int attack) {
  this->attack = attack;
}

/// Returns the current value of the monsters defense
inline int FightMon::Monster::getDefense() const {
  return this->defense;
}

inline void FightMon::Monster::setDefense(
  const int defense) {
  this->defense;
}

/// Returns the current value of the monsters speed
inline int FightMon::Monster::getSpeed() const {
  return this->speed;
}

inline void FightMon::Monster::setSpeed(
  const int speed) {
  this->speed = speed;
}

/// Returns the number of the elemental type
/// from the mosnter
inline size_t FightMon::Monster::getTypeNum() const {
  return this->elementalType;
}

/// Returns the name of the elemental type
/// from the mosnter
/// @remark behavior having an elementalTyoe < 0 or > 2 is
/// undefined
inline std::string FightMon::Monster::getTypeName() const {
  return FightMon::types[this->elementalType];
}

/// General methods
/// The monster uses the choosen move on the target
/// Returns true if i used the move correctly or
/// false if the monster failed
/// @remark behavior with an index > 3 is
/// undefined
inline bool FightMon::Monster::useMove(
  const size_t moveIndex, Monster* target) {
  return this->moveset[moveIndex]->use(this, target);
}

/// General functions
/// Returns 0.5 if the firstType is weak to the
/// second
/// Returns 1.0 if the firstType is equal to the second
/// Returns a number 1.5 if the firstType is strong to the
/// second
/// @remark Behavior using numbers higher than 2 is undefined
double FightMon::Monster::typeRelation(const size_t firstType, 
  const size_t secondType) {
  if (firstType == secondType) { return 1.0;
  } else if (abs(firstType - secondType) != 2 &&
    firstType > secondType) { return 1.5;
  } else if (secondType == 1) { return 0.5;
  } else { return firstType == 0? 1.5:0.5;}
}
