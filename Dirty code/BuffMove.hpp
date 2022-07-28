#ifndef BUFFMOVE_H
#define BUFFMOVE_H

#include <string>

#include "common.hpp"
#include "Move.hpp"

namespace FightMon { 

class BuffMove : public Move {
 protected:
  // Stat that will be buffed once this move
  // is used
  size_t buffingStat;
  // Buff factor of the buff move
  double buffFactor;
 
 public: // Rule of 4
  DECLARE_RULE4(BuffMove, default);

 public: // Constructor and destructor
   explicit BuffMove(const int stat,
   const double buffFactor = 1.5);
   ~BuffMove() = default;

 protected: // General methods
 bool use(Monster* user,
  Monster* target = nullptr) const override;
};

} // FightMon namespace

#endif // BUFFMOVE_H