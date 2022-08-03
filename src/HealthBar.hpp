// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include <QGraphicsSvgItem>

// Forward declaration
class QSvgRenderer;
class Monster;

class HealthBar : public QGraphicsSvgItem {
  Q_OBJECT

 protected: // Attributes
  QSvgRenderer* renderer;
  QGraphicsSvgItem* bar;
  double maxHealth;
  double currentHealth;

 public: // Constructor
  explicit HealthBar(QSvgRenderer* renderer,
                     Monster* monster,
                     QGraphicsSvgItem *parentItem = nullptr);

 signals: // Signals
  void monsterDied();

 public: // Accesors (General Purpose)
  /// Gets the frame, or background of, the health bar
  inline QGraphicsSvgItem* getFrame() {
    return this;
  }
  /// Gets the bar with their different colors
  inline QGraphicsSvgItem* getBar() {
    return this->bar;
  }

 public: // General methods
  void updateHealthBar(const double newHealth,
                       const bool orientation = true);
  void setHealthPos(const double xPos, const double yPos,
                    const bool orientation = true);
  void flip(bool orientation);

 protected: // Initializer
  void setHealthBar();

 protected: // Handy math functions
  /// Returns the current porcentage of health
  /// reamining
  inline int getHealthPorcentage() const {
    return round(
          (this->currentHealth*10)/this->maxHealth)*10;
  }

  /// Calclulates the position in the y axis
  /// when the bar is nor inverted
  inline int upPos() const {
    return (11 - this->getHealthPorcentage()/10)*20-2;
  }
};

#endif // HEALTHBAR_HPP
