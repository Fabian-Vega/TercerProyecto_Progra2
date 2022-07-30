#include <ctime>
#include <qglobal.h>

#include "DefenseMove.hpp"

DefenseMove::DefenseMove()
: Move() {
}

bool DefenseMove::use(Monster* user,
  Monster* target) const {
  Q_UNUSED(user);
  Q_UNUSED(target);

  time_t seconds = time(nullptr);
  return seconds % 2 == 0? true:false;
}
