#include "WarriorMonster.hpp"

FightMon::WarriorMonster::WarriorMonster(
  size_t type) : Monster(type) {
}

void FightMon::WarriorMonster::setStats() {
  this->health = 250;
  this->attack = 10;
  this->defense = 10;
  this->speed = 30;
}