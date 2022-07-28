#include "DamageMove.hpp"

FightMon::DamageMove::DamageMove(const int baseDamage)
: Move(),
  baseDamage(baseDamage) {
}

bool FightMon::DamageMove::use(Monster* user,
  Monster* target) const {
  double outDamage = 
  FightMon::Monster::typeRelation(
    user->getTypeNum(), target->getTypeNum())
  * this->baseDamage + user->getAttack();
  
  target->setHealth(target->getHealth()-(
    outDamage-target->getDefense()));
  return true;
}