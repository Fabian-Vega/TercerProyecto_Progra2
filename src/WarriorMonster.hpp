#ifndef WARRIORMONSTER_HPP
#define WARRIORMONSTER_HPP

#include "Monster.hpp"

// Forward declaration
class QSvgRenderer;

class WarriorMonster : public Monster {
 Q_OBJECT

  public: // Constructor and destructor
   explicit WarriorMonster(QSvgRenderer* renderer,
                    short type = 0,
                    QGraphicsSvgItem* parent = nullptr);
   ~WarriorMonster() = default;

  protected: // Iniatializer
   void setStats() override;
};

#endif // WARRIORMONSTER_HPP
