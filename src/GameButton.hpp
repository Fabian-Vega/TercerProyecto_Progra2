#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP

#include <QGraphicsSvgItem>

class GameButton : public QGraphicsSvgItem {
 Q_OBJECT

 private:
  short buttonIdentifier;

 public:
  explicit GameButton(short buttonIdentifier = 0,
                      QGraphicsItem* parentItem = nullptr);

 signals:
  void pressed(short buttonIdentifier);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // GAMEBUTTON_HPP
