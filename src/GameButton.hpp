#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP

#include <QGraphicsSvgItem>

class GameButton : public QGraphicsSvgItem {
  Q_OBJECT

 public:
  explicit GameButton(QGraphicsItem* parentItem = nullptr);

 signals:
  void pressed();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // GAMEBUTTON_HPP
