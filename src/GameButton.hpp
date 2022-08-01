#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP

#include <QGraphicsSvgItem>

// Forwrd declaration
class QSoundEffect;

class GameButton : public QGraphicsSvgItem {
 Q_OBJECT

 private:
  size_t buttonIdentifier;
  QSoundEffect* clickSound;

 public:
  explicit GameButton(size_t buttonIdentifier = 0,
                      QGraphicsItem* parentItem = nullptr);

 signals:
  void pressed(size_t buttonIdentifier);

 protected:
  void setSound();
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // GAMEBUTTON_HPP
