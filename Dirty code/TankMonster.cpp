#include "TankMonster.hpp"

FightMon::TankMonster::TankMonster(
  size_t type) : Monster(type) {
}

void FightMon::TankMonster::setStats() {
  this->health = 110;
  this->attack = 15;
  this->defense = 30;
  this->speed = 5;
}