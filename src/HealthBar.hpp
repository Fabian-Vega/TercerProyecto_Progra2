#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include <QGraphicsSvgItem>

// Forward declaration
class QSvgRenderer;
class Monster;

static const double barHeight = 185.0;
static const double barWidth = 9.5;

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
  void healHealthBar(const double newHealth);
  void reduceHealthBar(const double newHealth);
};

#endif // HEALTHBAR_HPP
