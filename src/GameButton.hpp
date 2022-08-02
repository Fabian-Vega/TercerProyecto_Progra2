#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP

#include <QGraphicsSvgItem>

#include "Sound.hpp"

class GameButton : public QGraphicsSvgItem {
 Q_OBJECT

 private: // Attributes
  size_t buttonIdentifier;
  Sound click;
  Sound hover;

 public: // Constructor
  explicit GameButton(size_t buttonIdentifier = 0,
                      QGraphicsItem* parentItem = nullptr);

 signals: // Signals
  void pressed(size_t buttonIdentifier);

 protected: // Event
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif  // GAMEBUTTON_HPP
