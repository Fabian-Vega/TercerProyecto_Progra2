#ifndef SELECTIONPLATE_HPP
#define SELECTIONPLATE_HPP
/*
#include <QGraphicsItemGroup>

// Forward declaration
class QSvgRenderer;
class QGraphicsSvgItem;
class GameButton;

class SelectionPlate : public QGraphicsItemGroup {
  Q_OBJECT

 private:
  QSvgRenderer* renderer;
  QGraphicsSvgItem* base;
  QGraphicsSvgItem* elementHeader;
  QGraphicsSvgItem* typeHeader;
  GameButton* fireButton;
  GameButton* waterButton;
  GameButton* plantButton;

 public:
  SelectionPlate(QSvgRenderer* renderer,
                 QString baseIdentifier,
                 QString elementHeaderIdentifier,
                 QString typeHeaderIdentifier,
                 QString fireButtonIdentifier,
                 QString waterButtonIdentifier,
                 QString plantButtonIdentifier,
                 QGraphicsItem* parentItem = nullptr);

 public:
  void setGroup(QString baseIdentifier,
              QString elementHeaderIdentifier,
              QString typeHeaderIdentifier,
              QString fireButtonIdentifier,
              QString waterButtonIdentifier,
              QString plantButtonIdentifier);

 protected:
  /// This template must never be used with a type
  /// other than QGraphicsSvgItem or classes that
  /// inherit from it, otherwise, behavior is
  /// undefined
  template <typename ObjectType = QGraphicsSvgItem>
  ObjectType* setObject(ObjectType* object,
                        QString identifier,
                        double xPos, double yPos) {
    Q_ASSERT(object);
    object->setSharedRenderer(this->renderer);
    object->setElementId(identifier);
    object->setPos(xPos, yPos);
    this->addToGroup(object);
    return object;
  }
};
*/
#endif // SELECTIONPLATE_HPP
