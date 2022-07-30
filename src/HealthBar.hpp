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
  QGraphicsSvgItem* currentHealth;
  double totalHealth;
  double health;

 public:
  explicit HealthBar(QSvgRenderer* renderer,
                     Monster* monster,
                     QGraphicsSvgItem *parentItem = nullptr);

 protected:
  void setHealthBar();

};

#endif // HEALTHBAR_HPP
