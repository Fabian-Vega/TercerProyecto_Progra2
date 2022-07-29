#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include <QGraphicsScene>

// Forward declarations
class QGraphicsSvgItem;
class QSvgRenderer;

class MenuScene : public QGraphicsScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(MenuScene)

 protected:
  QSvgRenderer* renderer;
  QGraphicsSvgItem* background;
  QGraphicsSvgItem* tittle;
  QGraphicsSvgItem* playButton;
  QGraphicsSvgItem* instrucctionsButton;

 public:
  explicit MenuScene(QSvgRenderer* renderer, QObject *parent = nullptr);

 protected:
  QGraphicsSvgItem* setObject(QGraphicsSvgItem* object,
                 const QString identifier,
                 const double xPos,
                 const double yPos);
  void setMenu();

 public:
  QGraphicsSvgItem* getBackground();
};

#endif // MENUSCENE_HPP
