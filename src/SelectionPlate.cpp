#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "SelectionPlate.hpp"
#include "GameButton.hpp"

SelectionPlate::SelectionPlate(QSvgRenderer* renderer,
                               QGraphicsItem* parentItem)
  : QGraphicsObject(parentItem),
    QGraphicsItemGroup(parentItem),
    renderer(renderer),
    base(nullptr),
    elementHeader(nullptr),
    typeHeader(nullptr),
    fireButton(nullptr),
    waterButton(nullptr),
    plantButton(nullptr),
    shieldButton(nullptr),
    bootButton(nullptr),
    swordButton(nullptr) {
}

QGraphicsSvgItem* SelectionPlate::setObject(
                            QGraphicsSvgItem* object,
                            QString identifier) {
  Q_ASSERT(object == nullptr);
  object = new QGraphicsSvgItem();
  Q_ASSERT(object);
  object->setSharedRenderer(this->renderer);
  object->setElementId(identifier);
  this->addToGroup(object);
  return object;
}

GameButton* SelectionPlate::setObject(
                            GameButton* object,
                            QString identifier) {
  Q_ASSERT(object == nullptr);
  object = new GameButton();
  Q_ASSERT(object);
  object->setSharedRenderer(this->renderer);
  object->setElementId(identifier);
  this->addToGroup(object);
  return object;
}

void SelectionPlate::setGroup(
    QString baseIdentifier) {
  this->base = setObject(this->base, baseIdentifier);
  this->elementHeader = setObject(this->elementHeader,
                              QString("elementHeader"));
  this->typeHeader = setObject(this->typeHeader,
                              QString("typeHeader"));
  this->fireButton = setObject(this->fireButton,
                              QString("fireButtonOn"));
  this->waterButton = setObject(this->waterButton,
                              QString("waterButtonOn"));
  this->plantButton = setObject(this->plantButton,
                                QString("plantButtonOn"));
  this->shieldButton = setObject(this->shieldButton,
                                QString("shieldButtonOn"));
  this->bootButton = setObject(this->bootButton,
                                QString("bootButtonOn"));
  this->swordButton = setObject(this->swordButton,
                                QString("swordButtonOn"));
}

void SelectionPlate::setGroupPos(const double xPos,
                                 const double yPos) {
  this->base->setPos(xPos, yPos);
  this->elementHeader->setPos(xPos+80.5, yPos+67);
  this->typeHeader->setPos(xPos+95, yPos+202);
  this->fireButton->setPos(xPos+10.5, yPos+97);
  this->waterButton->setPos(xPos+90, yPos+97);
  this->plantButton->setPos(xPos+169.5, yPos+97);
  this->shieldButton->setPos(xPos+10.5, yPos+237);
  this->bootButton->setPos(xPos+90, yPos+237);
  this->swordButton->setPos(xPos+169.5, yPos+237);
}

QRectF SelectionPlate::boundingRect() const {
  return this->base->boundingRect();
}

void SelectionPlate::paint(QPainter* painter,
                           const QStyleOptionGraphicsItem* option,
                           QWidget* widget) {
  this->base->paint(painter, option, widget);
  this->elementHeader->paint(painter, option, widget);
  this->typeHeader->paint(painter, option, widget);
  this->fireButton->paint(painter, option, widget);
  this->waterButton->paint(painter, option, widget);
  this->plantButton->paint(painter, option, widget);
  this->shieldButton->paint(painter, option, widget);
  this->bootButton->paint(painter, option, widget);
  this->swordButton->paint(painter, option, widget);
}

