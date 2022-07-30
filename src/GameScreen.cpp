#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "GameScreen.hpp"
#include "InstructionsScene.hpp"
#include "MenuScene.hpp"
#include "SelectionScene.hpp"

GameScreen::GameScreen(QWidget *parent)
  : QGraphicsView(parent),
    renderer(new QSvgRenderer(QString(":/assets/assets.svg"), this)),
    menu(new MenuScene(this->renderer)),
    instructions(new InstructionsScene(this->renderer)),
    selection(new SelectionScene(this->renderer)) {
  this->showMenu();
  this->connect(this->menu, &MenuScene::playPressed,
                this, &GameScreen::startGame);
  this->connect(this->menu, &MenuScene::instructionsPressed,
                this, &GameScreen::showInstructions);
  this->connect(this->instructions, &InstructionsScene::goBackPressed,
                this, &GameScreen::showMenu);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setWindowFlags(
        Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
  #endif

  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameScreen::~GameScreen() {
  delete this->menu;
  delete this->instructions;
  delete this->selection;
}

void GameScreen::showInstructions() {
  Q_ASSERT(this->instructions);
  this->setScene(this->instructions);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setFixedSize(this->instructions->width(),
                 this->instructions->height());
  #endif
}

void GameScreen::showMenu() {
  Q_ASSERT(this->menu);
  this->setScene(this->menu);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
   this->setFixedSize(this->menu->width(), this->menu->height());
  #endif
}

void GameScreen::startGame() {
  Q_ASSERT(this->selection);
  this->setScene(this->selection);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
   this->setFixedSize(this->selection->width(), this->selection->height());
  #endif
}
