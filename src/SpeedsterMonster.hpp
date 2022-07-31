#ifndef SPEEDSTERMONSTER_HPP
#define SPEEDSTERMONSTER_HPP

#include "Monster.hpp"

// Forward declaration
class QSvgRenderer;

class SpeedsterMonster : public Monster {
 Q_OBJECT

  public: // Constructor and destructor
   explicit SpeedsterMonster(QSvgRenderer* renderer,
                    short type = 0,
                    QGraphicsSvgItem* parent = nullptr);
   ~SpeedsterMonster() = default;

  protected: // Iniatializer
   void setStats() override;
};

#endif // SPEEDSTERMONSTER_HPP
