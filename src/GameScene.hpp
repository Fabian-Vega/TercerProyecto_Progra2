#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "GameButton.hpp"

// Forward delcaration
class MovesetLayout;
class SelectionPlate;

class GameScene : public QGraphicsScene {
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(GameScene)

 protected: // Attributes
  QSvgRenderer* renderer;
  QGraphicsSvgItem* background;

 public: // Constructor
  explicit GameScene(QSvgRenderer* renderer,
                     QObject* parent = nullptr);
  virtual ~GameScene();

 public: // Accesors
  inline qreal height() const {
    return this->getBackground()->boundingRect().height();
  }

  inline qreal width() const {
    return this->getBackground()->boundingRect().width();
  }

 protected:
  inline QGraphicsSvgItem* getBackground() const {
    return this->background;
  }

 protected: // Initializers
  QGraphicsSvgItem* setObject(QGraphicsSvgItem* object,
                 const QString identifier,
                 const double xPos,
                 const double yPos);
  GameButton* setObject(GameButton* object,
                 const QString identifier,
                 const double xPos,
                 const double yPos);
};

#endif  // GAMESCENE_HPP
