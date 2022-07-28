#ifndef DEFENSEMOVE_H
#define DEFENSEMOVE_H

#include "common.hpp"
#include "Move.hpp"

namespace FightMon {

class DefenseMove : public Move {
 public: // Rule of 4
  DECLARE_RULE4(DefenseMove, default);

 public: // Default constructor and destructor
   DefenseMove();
   ~DefenseMove() = default;

 private: // General methods
  bool use(Monster* user,
  Monster* target = nullptr) const override;
};

} // FightMon namespace

#endif // DEFENSEMOVE_H