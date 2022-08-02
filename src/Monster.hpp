#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <QGraphicsSvgItem>
#include <string>
#include <vector>

#include "Move.hpp"

// Forward declaration
class QSvgRenderer;
class QPropertyAnimation;
class Sound;

static const std::string types[3] = {"Fire", "Water", "Plant"};

class Monster : public QGraphicsSvgItem {
  Q_OBJECT

 protected: // Attributes
  struct HealthType {
    double maxHealth = 0;
    double currentHealth = 0;
  };

  QSvgRenderer* renderer;
  QPropertyAnimation* animation;
  Sound* moveSound;

  HealthType health;
  int attack;
  int defense;
  int speed;
  size_t elementalType;
  std::vector<Move*> moveset;

  size_t buffStat = 0;
  size_t debuffStat = 0;

 public: // Constructor and destructor
  explicit Monster(QSvgRenderer* renderer,
                   size_t element = 0,
                   QGraphicsSvgItem *parent = nullptr);
  ~Monster();

 protected: // Initializers
  void initializeMonster();
  /// Loads an object from the Monster class
  virtual void loadMonster() = 0;
  /// Sets the stats for the monster
  virtual void setStats() = 0;
  /// Sets the Moves each Monster wil be using
  virtual void setMoveset();
  /// Changes the orientation of where the monster is looking
  virtual void changeOrientation(bool orientation) = 0;

 public: // Accesors (general purpose)
  /// Returns true if the monsters current health is above 0.0
  inline bool isAlive() const {
    return this->health.currentHealth > 0.0;
  }

  /// Returns the number of the stat choose for the buff
  /// move
  inline size_t getBuffStat() const {
    return this->buffStat;
  }

  /// Returns the number of the stat choose for the
  /// debuff move
  inline size_t getDebuffStat() const {
    return this->debuffStat;
  }

 public: // Accesors (Gets and Sets)
  /// Returns the max value of the monsters health
  inline double getMaxHealth() const {
    return this->health.maxHealth;
  }

  /// Returns the current value of the monsters health
  inline double getCurrentHealth() const {
    return this->health.currentHealth;
  }

  /// Sets the current health to a value below or equal
  /// to the maxHealth
  inline void setHealth(
    const double health) {
    this->health.currentHealth =
        (health > this->health.maxHealth ?
           this->health.maxHealth :
           health <= 0? 0 : health);
  }

  /// Returns the current value of the monsters attack
  inline int getAttack() const {
    return this->attack;
  }

  /// Set the value of the monsters attack
  inline void setAttack(
    const int attack) {
    this->attack = attack;
  }

  /// Returns the current value of the monsters defense
  inline int getDefense() const {
    return this->defense;
  }

  /// Set the value of the monsters defense
  inline void setDefense(
    const int defense) {
    this->defense = defense;
  }

  /// Returns the current value of the monsters speed
  inline int getSpeed() const {
    return this->speed;
  }

  /// Set the value of the monsters speed
  inline void setSpeed(
    const int speed) {
    this->speed = speed;
  }

  /// Returns the number of the elemental type
  /// from the mosnter
  inline size_t getTypeNum() const {
    return this->elementalType;
  }

  /// Returns the name of the elemental type
  /// from the mosnter
  /// @remark behavior having an elementalTyoe < 0 or > 2 is
  /// undefined
  inline std::string getTypeName() const {
    return types[this->elementalType-1];
  }

  /// Uses the chosen move
  bool useMove(const size_t move, Monster* target);

 public: // General functions
  void flip(bool orientation);
  static double typeRelation(const int firstType,
  const int secondType);
};

#endif // MONSTER_HPP
