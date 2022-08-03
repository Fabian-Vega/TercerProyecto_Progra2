// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include "DefenseMove.hpp"

DefenseMove::DefenseMove()
: Move() {
}

bool DefenseMove::use(Monster* user,
  Monster* target) const {
  Q_UNUSED(user);
  Q_UNUSED(target);

  return random(1, 100) <= 70? true:false;
}
