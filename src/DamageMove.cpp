#include "DamageMove.hpp"
#include "Monster.hpp"

DamageMove::DamageMove(const int baseDamage)
: Move(),
  baseDamage(baseDamage) {
}

bool DamageMove::use(Monster* user,
  Monster* target) const {
  double outDamage =
  Monster::typeRelation(
    user->getTypeNum(), target->getTypeNum())
  * this->baseDamage + user->getAttack();

  target->setHealth(target->getCurrentHealth()-(
    outDamage-target->getDefense()));
  return true;
}
