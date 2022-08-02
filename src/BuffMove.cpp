#include "BuffMove.hpp"
#include "Monster.hpp"

BuffMove::BuffMove(const size_t stat,
   const double buffFactor)
  : Move(),
    buffingStat(stat),
    buffFactor(buffFactor) {
}

bool BuffMove::use(Monster* user,
  Monster* target) const {
  (void)user;
  switch (this->buffingStat) {
    case healthStat:
      target->setHealth(target->getMaxHealth()*this->buffFactor);
    break;

    case attackStat:
      target->setAttack(target->getAttack()*this->buffFactor);
    break;

    case defenseStat:
      target->setDefense(target->getDefense()*this->buffFactor);
    break;

    case speedStat:
      target->setSpeed(target->getSpeed()*this->buffFactor);
    break;

    default:
    break;
  }

  return true;
}
