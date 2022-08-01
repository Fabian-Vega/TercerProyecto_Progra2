#include <QSoundEffect>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "EndScene.hpp"
#include "FightScene.hpp"
#include "GameScreen.hpp"
#include "InstructionsScene.hpp"
#include "MenuScene.hpp"
#include "Monster.hpp"
#include "SelectionScene.hpp"
#include "SpeedsterMonster.hpp"
#include "TankMonster.hpp"
#include "WarriorMonster.hpp"

GameScreen::GameScreen(QWidget *parent)
  : QGraphicsView(parent),
    renderer(new QSvgRenderer(QString(":/assets/assets.svg"), this)),
    menu(new MenuScene(this->renderer)),
    instructions(new InstructionsScene(this->renderer)),
    selection(new SelectionScene(this->renderer)),
    fight(nullptr),
    end(nullptr) {
  this->showMenu();
  this->connect(this->menu, &MenuScene::playPressed,
                this, &GameScreen::startGame);
  this->connect(this->menu, &MenuScene::instructionsPressed,
                this, &GameScreen::showInstructions);
  this->connect(this->instructions, &InstructionsScene::goBackPressed,
                this, &GameScreen::showMenu);
  this->connect(this->selection, &SelectionScene::continuePressed,
                this, &GameScreen::startFight);

  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setWindowFlags(
        Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
  #endif

  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameScreen::~GameScreen() {
  delete this->renderer;
  delete this->menu;
  delete this->instructions;
  delete this->selection;
  delete this->fight;
  delete this->end;
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
  delete this->end;
  this->end = nullptr;
}

void GameScreen::startGame() {
  Q_ASSERT(this->selection);
  this->setScene(this->selection);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
   this->setFixedSize(this->selection->width(), this->selection->height());
  #endif
}

void GameScreen::startFight() {
  Monster* player1 = this->monsterFactory(
                       this->selection->getPlayerChoice(1, 1),
                       this->selection->getPlayerChoice(1, 2));
  Monster* player2 = this->monsterFactory(
                       this->selection->getPlayerChoice(2, 1),
                       this->selection->getPlayerChoice(2, 2));
  this->fight = new FightScene(this->renderer,
                               player1,
                               player2);
  Q_ASSERT(this->fight);
  this->setScene(this->fight);
  this->connect(this->fight, &FightScene::playerWon,
                this, &GameScreen::showEndScreen);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
   this->setFixedSize(this->fight->width(), this->fight->height());
  #endif
}

void GameScreen::showEndScreen(size_t winner) {
  if (end == nullptr) {
    this->end = new EndScene(this->renderer, winner);
    Q_ASSERT(this->end);
    this->setScene(this->end);
    this->connect(this->end, &EndScene::backToMenu,
                  this, &GameScreen::showMenu);
    // Should free fight here
  }
}

Monster* GameScreen::monsterFactory(
    size_t element, size_t type) const {
  switch(type) {
    case 1:
      return new TankMonster(this->renderer, element);
    break;
    case 2:
      return new SpeedsterMonster(this->renderer, element);
    break;
    case 3:
      return new WarriorMonster(this->renderer, element);
    break;
    default:
      return nullptr;
    break;
  }
}

void GameScreen::wheelEvent(QWheelEvent* event) {
  Q_UNUSED(event);
}





