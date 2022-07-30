#ifndef SELECTIONPLATE_HPP
#define SELECTIONPLATE_HPP

#include <QGraphicsSvgItem>

// Forward declaration
class GameButton;
class QGraphicsSvgItem;
class QSvgRenderer;

class SelectionPlate : public QGraphicsSvgItem {
  Q_OBJECT

 private:
  QSvgRenderer* renderer;
  QGraphicsSvgItem* elementHeader;
  QGraphicsSvgItem* typeHeader;
  GameButton* fireButton;
  GameButton* waterButton;
  GameButton* plantButton;
  GameButton* shieldButton;
  GameButton* bootButton;
  GameButton* swordButton;

  short elementSelected = 0;
  short typeSelected = 0;

 public:
  SelectionPlate(QSvgRenderer* renderer,
                 QGraphicsItem* parentItem = nullptr);

 signals:
  void selectionDone();

 protected slots:
  void selectElement(short buttonNumber);
  void selectType(short buttonNumber);

 public:
  inline QGraphicsSvgItem* getBase() {
    return this;
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

  inline short getElementSelected() {
    return this->elementSelected;
  }

  inline short getTypeSelected() {
    return this->typeSelected;
  }

 public:
  void setGroup(QString baseIdentifier);
  void setGroupPos(const double xPos,
                   const double yPos);

 protected:
  QGraphicsSvgItem* setItem(QGraphicsSvgItem* item,
                              QString identifier);

  GameButton* setButton(GameButton* button,
                        short buttonNumber,
                        QString identifier,
                        short category);
};

#endif // SELECTIONPLATE_HPP
