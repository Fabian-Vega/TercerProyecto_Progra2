#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include <QGraphicsSvgItem>

// Forward declaration
class QSvgRenderer;
class Monster;

class HealthBar : public QGraphicsSvgItem {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  QGraphicsSvgItem* bar;
  double maxHealth;
  double currentHealth;

 public:
  explicit HealthBar(QSvgRenderer* renderer,
                     Monster* monster,
                     QGraphicsSvgItem *parentItem = nullptr);

 signals:
  void monsterDied();

 public:
  inline QGraphicsSvgItem* getFrame() {
    return this;
  }
  inline QGraphicsSvgItem* getBar() {
    return this->bar;
  }

 public:
  void updateHealthBar(const double newHealth);
  void setHealthPos(const double xPos, const double yPos);
  void flip(bool orientation);

 protected:
  void setHealthBar();
};

#endif // HEALTHBAR_HPP
