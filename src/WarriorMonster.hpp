// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef WARRIORMONSTER_HPP
#define WARRIORMONSTER_HPP

#include "Monster.hpp"

// Forward declaration
class QSvgRenderer;

class WarriorMonster : public Monster {
 Q_OBJECT

  public: // Constructor and destructor
   explicit WarriorMonster(QSvgRenderer* renderer,
                    size_t type = 1,
                    QGraphicsSvgItem* parent = nullptr);
   ~WarriorMonster() = default;

  protected: // Iniatializer
   void loadMonster() override;
   void setStats() override;
   void changeOrientation(bool orientation) override;
};

#endif // WARRIORMONSTER_HPP
