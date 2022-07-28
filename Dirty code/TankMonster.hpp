#ifndef TANKMONSTER_H
#define TANKMONSTER_H

#include "common.hpp"
#include "Monster.hpp"

namespace FightMon {

class TankMonster : public Monster {
 public: // Rule of 4
  DECLARE_RULE4(TankMonster, default);

 public: // Default constructor and destructor
  TankMonster(size_t type = 0);
  ~TankMonster() = default;

 protected: // Iniatializer
  void setStats() override;
};

} // FightMon namespace

#endif // TANKMONSTER_H