#ifndef WARRIORMONSTER_H
#define WARRIORMONSTER_H

#include "common.hpp"
#include "Monster.hpp"

namespace FightMon {

class WarriorMonster : public Monster {
 public: // Rule of 4
  DECLARE_RULE4(WarriorMonster, default);

 public: // Default constructor and destructor
  WarriorMonster(size_t type = 0);
  ~WarriorMonster() = default;

 protected: // Iniatializer
  void setStats() override;
};

} // FightMon namespace

#endif // WARRIORMONSTER_H