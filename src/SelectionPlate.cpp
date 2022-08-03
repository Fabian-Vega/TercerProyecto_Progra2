// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#include <QSvgRenderer>

#include "SelectionPlate.hpp"
#include "GameButton.hpp"

SelectionPlate::SelectionPlate(QSvgRenderer* renderer,
                               QGraphicsItem* parentItem)
  : QGraphicsSvgItem(parentItem),
    renderer(renderer),
    elementHeader(nullptr),
    typeHeader(nullptr),
    fireButton(nullptr),
    waterButton(nullptr),
    plantButton(nullptr),
    shieldButton(nullptr),
    bootButton(nullptr),
    swordButton(nullptr) {
}

void SelectionPlate::selectElement(size_t buttonNumber) {
  switch(buttonNumber) {
    case 1:
      this->fireButton->setElementId(QString("fireButtonOn"));
      this->waterButton->setElementId(QString("waterButtonOff"));
      this->plantButton->setElementId(QString("plantButtonOff"));
    break;

    case 2:
      this->fireButton->setElementId(QString("fireButtonOff"));
      this->waterButton->setElementId(QString("waterButtonOn"));
      this->plantButton->setElementId(QString("plantButtonOff"));
    break;

    case 3:
      this->fireButton->setElementId(QString("fireButtonOff"));
      this->waterButton->setElementId(QString("waterButtonOff"));
      this->plantButton->setElementId(QString("plantButtonOn"));
    break;
  }
  this->elementSelected = buttonNumber;
  if (typeSelected) {
    emit this->selectionDone();
  }
}

void SelectionPlate::selectType(size_t buttonNumber) {
  switch(buttonNumber) {
    case 1:
      this->shieldButton->setElementId(QString("shieldButtonOn"));
      this->bootButton->setElementId(QString("bootButtonOff"));
      this->swordButton->setElementId(QString("swordButtonOff"));
    break;

    case 2:
      this->shieldButton->setElementId(QString("shieldButtonOff"));
      this->bootButton->setElementId(QString("bootButtonOn"));
      this->swordButton->setElementId(QString("swordButtonOff"));
    break;

    case 3:
      this->shieldButton->setElementId(QString("shieldButtonOff"));
      this->bootButton->setElementId(QString("bootButtonOff"));
      this->swordButton->setElementId(QString("swordButtonOn"));
    break;
  }
  this->typeSelected = buttonNumber;
  if (elementSelected) {
    emit this->selectionDone();
  }
}

void SelectionPlate::setGroup(
    QString baseIdentifier) {
  setItem(this, baseIdentifier);
  this->elementHeader = this->setItem(this->elementHeader,
                              QString("elementHeader"));
  this->typeHeader = this->setItem(this->typeHeader,
                              QString("typeHeader"));

  this->fireButton = this->setButton(this->fireButton, 1,
                             QString("fireButtonOn"), 0);

  this->waterButton = this->setButton(this->waterButton, 2,
                              QString("waterButtonOn"), 0);

  this->plantButton = this->setButton(this->plantButton, 3,
                              QString("plantButtonOn"), 0);

  this->shieldButton = this->setButton(this->shieldButton, 1,
                               QString("shieldButtonOn"), 1);

  this->bootButton = this->setButton(this->bootButton, 2,
                              QString("bootButtonOn"), 1);

  this->swordButton = this->setButton(this->swordButton, 3,
                              QString("swordButtonOn"), 1);
}

void SelectionPlate::setGroupPos(const double xPos,
                                 const double yPos) {
  this->setPos(xPos, yPos);
  this->elementHeader->setPos(xPos+80.5, yPos+67);
  this->typeHeader->setPos(xPos+95, yPos+202);
  this->fireButton->setPos(xPos+10.5, yPos+97);
  this->waterButton->setPos(xPos+90, yPos+97);
  this->plantButton->setPos(xPos+169.5, yPos+97);
  this->shieldButton->setPos(xPos+10.5, yPos+237);
  this->bootButton->setPos(xPos+90, yPos+237);
  this->swordButton->setPos(xPos+169.5, yPos+237);
}

QGraphicsSvgItem* SelectionPlate::setItem(
                            QGraphicsSvgItem* item,
                            QString identifier) {
  if (item == nullptr) {
    item = new QGraphicsSvgItem();
  }
  Q_ASSERT(item);
  item->setSharedRenderer(this->renderer);
  item->setElementId(identifier);
  return item;
}

GameButton* SelectionPlate::setButton(
                            GameButton* button,
                            size_t buttonNumber,
                            QString identifier,
                            size_t category) {
  Q_ASSERT(button == nullptr);
  button = new GameButton(buttonNumber);
  Q_ASSERT(button);
  button->setSharedRenderer(this->renderer);
  button->setElementId(identifier);
  if (category == 0) {
    this->connect(button, &GameButton::pressed,
                  this, &SelectionPlate::selectElement);
  } else {
    this->connect(button, &GameButton::pressed,
                  this, &SelectionPlate::selectType);
  }
  return button;
}
