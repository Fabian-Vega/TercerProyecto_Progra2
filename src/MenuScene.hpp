#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include <QGraphicsScene>

class MenuScene : public QGraphicsScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(MenuScene)

 public:
  explicit MenuScene(QObject *parent = nullptr);

 protected:
  void setBackground();
};

#endif // MENUSCENE_HPP
