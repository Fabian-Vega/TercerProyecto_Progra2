#include "DamageMove.hpp"
#include "Monster.hpp"

DamageMove::DamageMove(const int baseDamage)
: Move(),
  baseDamage(baseDamage) {
}

bool DamageMove::use(Monster* user,
  Monster* target) const {
  double outDamage =
      (Monster::typeRelation(user->getTypeNum(),
               target->getTypeNum()) *
   this->baseDamage) + user->getAttack();

  double damageTaken = outDamage-target->getDefense();
  damageTaken = damageTaken <= 0? 10: damageTaken;

  target->setHealth(target->getCurrentHealth() - damageTaken);
  return true;
}
