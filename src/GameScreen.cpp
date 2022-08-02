#include <QSoundEffect>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>

#include "CreditsScene.hpp"
#include "WinScene.hpp"
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
    renderer(new QSvgRenderer(QString(":/images/assets.svg"), this)),
    mainSong(menuSong, this),
    fightSong(battleSong, this),
    winningSong(winSong, this),
    creditsSong(finalSong, this),
    menu(new MenuScene(this->renderer)),
    instructions(new InstructionsScene(this->renderer)),
    selection(new SelectionScene(this->renderer)),
    fight(nullptr),
    win(nullptr),
    credits(new CreditsScene(this->renderer)) {
  this->showMenu();
  this->connect(this->menu, &MenuScene::creditsPressed,
                this, &GameScreen::showCredits);
  this->connect(this->menu, &MenuScene::playPressed,
                this, &GameScreen::startGame);
  this->connect(this->menu, &MenuScene::instructionsPressed,
                this, &GameScreen::showInstructions);
  this->connect(this->instructions, &InstructionsScene::goBackPressed,
                this, &GameScreen::showMenu);
  this->connect(this->credits, &CreditsScene::creditsEnded,
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
  delete this->win;
  delete this->credits;
}

void GameScreen::showCredits() {
  this->mainSong.pause();
  Q_ASSERT(this->credits);
  this->creditsSong.play(true);
  this->setScene(this->credits);
  this->credits->startCredits();
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setFixedSize(this->credits->width(),
                 this->credits->height());
  #endif
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
  this->creditsSong.pause();
  this->winningSong.pause();
  Q_ASSERT(this->menu);
  this->mainSong.play(true);
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

void GameScreen::startFight() {
  this->mainSong.pause();
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
  this->connect(this->fight, &FightScene::playerWon,
                this, &GameScreen::showWin);
  this->fightSong.play(true);
  this->setScene(this->fight);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setFixedSize(this->fight->width(), this->fight->height());
  #endif
}

void GameScreen::showWin(size_t winner) {
  if (win == nullptr) {
    this->fightSong.pause();
    this->win = new WinScene(this->renderer, winner);
    Q_ASSERT(this->win);
    this->disconnect(this->fight, &FightScene::playerWon,
                  this, &GameScreen::showWin);
    this->fight = nullptr;
    this->winningSong.play(true);
    this->setScene(this->win);
    this->connect(this->win, &WinScene::backToMenu,
                  this, &GameScreen::showMenu);
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
