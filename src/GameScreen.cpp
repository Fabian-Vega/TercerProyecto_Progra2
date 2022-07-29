#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "GameScreen.hpp"
#include "MenuScene.hpp"

GameScreen::GameScreen(QWidget *parent)
  : QGraphicsView{parent},
    renderer(new QSvgRenderer(QString(":/assets/assets.svg"), this)),
    menu(new MenuScene(this->renderer)) {
  this->setScene(this->menu);

  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->fitInView(this->menu->getBackground());
  #endif

  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
}

GameScreen::~GameScreen() {
  delete this->menu;
}
