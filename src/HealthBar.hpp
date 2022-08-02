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

 public: // Accesors(General Purpose)
  /// Gets the frame, or background of, the health bar
  inline QGraphicsSvgItem* getFrame() {
    return this;
  }
  /// Gets the bar with their different colors
  inline QGraphicsSvgItem* getBar() {
    return this->bar;
  }

 public: // General methods
  void updateHealthBar(const double newHealth);
  void setHealthPos(const double xPos, const double yPos);
  void flip(bool orientation);

 protected: // Accesor (Health Bar Setter)
  void setHealthBar();
};

#endif // HEALTHBAR_HPP
