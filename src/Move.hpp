#ifndef MOVE_HPP
#define MOVE_HPP

#include "Common.hpp"

// Forward declaration
class Monster;

class Move {
 protected:
  // Enumeration for the different stats
  enum Stat {
    healthStat = 1,
    attackStat = 2,
    defenseStat = 3,
    speedStat = 4
  };

 public: // Rule of 4
  DECLARE_RULE4(Move, default);

 public: // Default constructor and destructor
  Move();
  virtual ~Move() = default;

 public: // General methods
  virtual bool use(Monster* user,
  Monster* target = nullptr) const = 0;
};
#endif // MOVE_HPP
