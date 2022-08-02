#ifndef DAMAGEMOVE_HPP
#define DAMAGEMOVE_HPP

#include "Move.hpp"

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

#endif // DAMAGEMOVE_HPP
