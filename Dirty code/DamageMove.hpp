#ifndef DAMAGEMOVE_H
#define DAMAGEMOVE_H

#include "common.hpp"
#include "Move.hpp"

namespace FightMon {

class DamageMove : public Move {
 protected:
  // Base damage of all damage moves
  int baseDamage;
 
 public: // Rule of 4
  DECLARE_RULE4(DamageMove, default);

 public: // Default constructor and destructor
  explicit DamageMove(const int baseDamage = 20);
  ~DamageMove() = default;

 public: // General methods
  bool use(Monster* user,
  Monster* target = nullptr) const override;
};

} // FightMon namespace

#endif // DAMAGEMOVE_H