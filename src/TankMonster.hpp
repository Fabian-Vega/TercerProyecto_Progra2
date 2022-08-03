// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef TANKMONSTER_HPP
#define TANKMONSTER_HPP

#include "Monster.hpp"

// Forward declaration
class QSvgRenderer;

class TankMonster : public Monster {
 Q_OBJECT

  public: // Constructor and destructor
   explicit TankMonster(QSvgRenderer* renderer,
                    size_t type = 1,
                    QGraphicsSvgItem* parent = nullptr);
   ~TankMonster() = default;

  protected: // Iniatializer
   void loadMonster() override;
   void setStats() override;
   void changeOrientation(bool orientation) override;
};

#endif // TANKMONSTER_HPP
