/*#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "SelectionPlate.hpp"
#include "GameButton.hpp"



SelectionPlate::SelectionPlate(QSvgRenderer* renderer,
                               QString baseIdentifier,
                               QString elementHeaderIdentifier,
                               QString typeHeaderIdentifier,
                               QString fireButtonIdentifier,
                               QString waterButtonIdentifier,
                               QString plantButtonIdentifier,
                               QGraphicsItem* parentItem)
  : QGraphicsItemGroup(parentItem),
    renderer(renderer),
    base(new QGraphicsSvgItem()),
    elementHeader(new QGraphicsSvgItem()),
    typeHeader(new QGraphicsSvgItem()),
    fireButton(new GameButton()),
    waterButton(new GameButton()),
    plantButton(new GameButton()) {
  this->setGroup(baseIdentifier,
                 elementHeaderIdentifier,
                 typeHeaderIdentifier,
                 fireButtonIdentifier,
                 waterButtonIdentifier,
                 plantButtonIdentifier);
}

void SelectionPlate::setGroup(
    QString baseIdentifier,
    QString elementHeaderIdentifier,
    QString typeHeaderIdentifier,
    QString fireButtonIdentifier,
    QString waterButtonIdentifier,
    QString plantButtonIdentifier) {
  this->base->setSharedRenderer(this->renderer);
  this->elementHeader->setSharedRenderer(this->renderer);
  this->typeHeader->setSharedRenderer(this->renderer);
  this->fireButton->setSharedRenderer(this->renderer);
  this->waterButton->setSharedRenderer(this->renderer);
  this->plantButton->setSharedRenderer(this->renderer);

  this->base->setElementId(baseIdentifier);
  this->elementHeader->setElementId(elementHeaderIdentifier);
  this->typeHeader->setElementId(typeHeaderIdentifier);
  this->fireButton->setElementId(fireButtonIdentifier);
  this->waterButton->setElementId(waterButtonIdentifier);
  this->plantButton->setElementId(plantButtonIdentifier);
}
*/
