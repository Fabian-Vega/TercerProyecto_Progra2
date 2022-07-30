#ifndef SELECTIONPLATE_HPP
#define SELECTIONPLATE_HPP

#include <QGraphicsItemGroup>
#include <QGraphicsObject>

// Forward declaration
class GameButton;
class QGraphicsSvgItem;
class QSvgRenderer;

class SelectionPlate : public QGraphicsObject, public QGraphicsItemGroup {
  Q_OBJECT

 private:
  QSvgRenderer* renderer;
  QGraphicsSvgItem* base;
  QGraphicsSvgItem* elementHeader;
  QGraphicsSvgItem* typeHeader;
  GameButton* fireButton;
  GameButton* waterButton;
  GameButton* plantButton;
  GameButton* shieldButton;
  GameButton* bootButton;
  GameButton* swordButton;

  bool elementSelected = false;
  bool typeSelected = false;

 public:
  SelectionPlate(QSvgRenderer* renderer,
                 QGraphicsItem* parentItem = nullptr);

 public:
  inline QGraphicsSvgItem* getBase() {
    return this->base;
  }

  inline QGraphicsSvgItem* getElementHeader() {
    return this->elementHeader;
  }

  inline QGraphicsSvgItem* getTypeHeader() {
    return this->typeHeader;
  }

  inline GameButton* getFireButton() {
    return this->fireButton;
  }

  inline GameButton* getWaterButton() {
    return this->waterButton;
  }

  inline GameButton* getPlantButton() {
    return this->plantButton;
  }

  inline GameButton* getShieldButton() {
    return this->shieldButton;
  }

  inline GameButton* getBootButton() {
    return this->bootButton;
  }

  inline GameButton* getSwordButton() {
    return this->swordButton;
  }

 public:
  void setGroup(QString baseIdentifier);
  void setGroupPos(const double xPos,
                   const double yPos);
  QRectF boundingRect() const override;
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;

 protected:
  QGraphicsSvgItem* setObject(QGraphicsSvgItem* object,
                              QString identifier);

  GameButton* setObject(GameButton* object,
                              QString identifier);
};

#endif // SELECTIONPLATE_HPP
