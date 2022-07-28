#include "SpeedsterMonster.hpp"

FightMon::SpeedsterMonster::SpeedsterMonster(
  size_t type) : Monster(type) {
}

void FightMon::SpeedsterMonster::setStats() {
  this->health = 250;
  this->attack = 10;
  this->defense = 10;
  this->speed = 30;
}