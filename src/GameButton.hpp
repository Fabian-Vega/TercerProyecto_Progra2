#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP

#include <QGraphicsSvgItem>

class GameButton : public QGraphicsSvgItem {
 Q_OBJECT

 private:
  short buttonIdentifier;

 public:
  explicit GameButton(size_t buttonIdentifier = 0,
                      QGraphicsItem* parentItem = nullptr);

 signals:
  void pressed(size_t buttonIdentifier);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // GAMEBUTTON_HPP
