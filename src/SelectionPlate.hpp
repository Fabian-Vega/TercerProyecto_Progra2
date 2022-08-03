// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef SELECTIONPLATE_HPP
#define SELECTIONPLATE_HPP

#include <QGraphicsSvgItem>

// Forward declaration
class GameButton;
class QGraphicsSvgItem;
class QSvgRenderer;

class SelectionPlate : public QGraphicsSvgItem {
  Q_OBJECT

 private: // Attributes
  QSvgRenderer* renderer;
  QGraphicsSvgItem* elementHeader;
  QGraphicsSvgItem* typeHeader;
  GameButton* fireButton;
  GameButton* waterButton;
  GameButton* plantButton;
  GameButton* shieldButton;
  GameButton* bootButton;
  GameButton* swordButton;

  size_t elementSelected = 0;
  size_t typeSelected = 0;

 public: // Constructor
  SelectionPlate(QSvgRenderer* renderer,
                 QGraphicsItem* parentItem = nullptr);

 signals: // Signals
  void selectionDone();

 protected slots: // Slots
  void selectElement(size_t buttonNumber);
  void selectType(size_t buttonNumber);

 public: // Accesors
  /// Gets the base plate where the options will be displayed
  inline QGraphicsSvgItem* getBase() {
    return this;
  }
  /// Gets the header for the elements
  inline QGraphicsSvgItem* getElementHeader() {
    return this->elementHeader;
  }
  /// Gets the header for the types
  inline QGraphicsSvgItem* getTypeHeader() {
    return this->typeHeader;
  }
  /// Gets the button corresponding to the fire element
  inline GameButton* getFireButton() {
    return this->fireButton;
  }
  /// Gets the button corresponding to the water element
  inline GameButton* getWaterButton() {
    return this->waterButton;
  }
  /// Gets the button corresponding to the plant element
  inline GameButton* getPlantButton() {
    return this->plantButton;
  }
  /// Gets the button corresponding to the defender class
  inline GameButton* getShieldButton() {
    return this->shieldButton;
  }
  /// Gets the button corresponding to the speedster class
  inline GameButton* getBootButton() {
    return this->bootButton;
  }
  /// Gets the button corresponding to the attacker class
  inline GameButton* getSwordButton() {
    return this->swordButton;
  }
  /// Gets the button corresponding to the action of selecting an element
  inline size_t getElementSelected() {
    return this->elementSelected;
  }
  /// Gets the button corresponding to the action of selecting a type
  inline size_t getTypeSelected() {
    return this->typeSelected;
  }

 public: // Initializers
  void setGroup(QString baseIdentifier);
  void setGroupPos(const double xPos,
                   const double yPos);

 protected: // Accesors(General methods)
  QGraphicsSvgItem* setItem(QGraphicsSvgItem* item,
                              QString identifier);

  GameButton* setButton(GameButton* button,
                        size_t buttonNumber,
                        QString identifier,
                        size_t category);
};

#endif // SELECTIONPLATE_HPP
