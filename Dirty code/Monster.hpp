#ifndef MONSTER_H
#define MONSTER_H

#include <cstddef>
#include <string>

#include "common.hpp"
#include "Move.hpp"

namespace FightMon {

static const std::string types[3] = {"Fire", "Water", "PLant"};

class Monster {
 protected: // Attributes
  double health;
  int attack;
  int defense;
  int speed;
  size_t elementalType;
  Move** moveset;

 public: // Rule of 4
  DECLARE_RULE4(Monster, default);

 public: // Default constructor and destructor
  explicit Monster(size_t type = 0);
  ~Monster();

 protected: // Initializers
  void initializeMonster();
  virtual void setStats() = 0;
  virtual void setMoveset();

 public: // Accesors (general purpose)
  inline bool isAlive() const;

 public: // Accesors (Gets and Sets)
  inline double getHealth() const;
  inline void setHealth(const double health);
  inline int getAttack() const;
  inline void setAttack(const int attack);
  inline int getDefense() const;
  inline void setDefense(const int defense);
  inline int getSpeed() const;
  inline void setSpeed(const int speed);
  inline size_t getTypeNum() const;
  inline std::string getTypeName() const;
  
 public: // General Methods
  inline bool useMove(const size_t moveIndex,
  Monster* target = nullptr);

 public: // General functions
  static double typeRelation(const size_t firstType, 
  const size_t secondType);
};

} // FightMon namespace

#endif // MONSTER_H