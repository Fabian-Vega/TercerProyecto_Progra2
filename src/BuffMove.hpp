#ifndef BUFFMOVE_HPP
#define BUFFMOVE_HPP

#include "Move.hpp"

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
   explicit BuffMove(const size_t stat,
   const double buffFactor = 1.5);
   ~BuffMove() = default;

 protected: // General methods
 bool use(Monster* user,
  Monster* target = nullptr) const override;
};

#endif // BUFFMOVE_HPP
