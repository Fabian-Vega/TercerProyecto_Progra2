#include <ctime>

#include "DefenseMove.hpp"

FightMon::DefenseMove::DefenseMove()
: Move() {
}

bool FightMon::DefenseMove::use(Monster* user,
  Monster* target) const {
  time_t seconds = time(nullptr);
  return seconds % 2 == 0? true:false;
}