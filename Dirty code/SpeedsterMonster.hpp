#ifndef SPEEDSTERMONSTER_H
#define SPEEDSTERMONSTER_H

#include "common.hpp"
#include "Monster.hpp"

namespace FightMon {

class SpeedsterMonster : public Monster {
 public: // Rule of 4
  DECLARE_RULE4(SpeedsterMonster, default);

 public: // Default constructor and destructor
  SpeedsterMonster(size_t type = 0);
  ~SpeedsterMonster() = default;

 protected: // Iniatializer
  void setStats() override;
};

} // FightMon namespace

#endif // SPEEDSTERMONSTER_H