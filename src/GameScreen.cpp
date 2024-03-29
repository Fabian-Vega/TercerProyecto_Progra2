// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

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

GameScreen::GameScreen(QWidget* parent)
  : QGraphicsView(parent),
    renderer(new QSvgRenderer(assets, this)),
    mainSong(menuSong, this),
    fightSong(battleSong, this),
    winningSong(winSong, this),
    creditsSong(finalSong, this),
    menu(new MenuScene(this->renderer)),
    instructions(new InstructionsScene(this->renderer)),
    selection(new SelectionScene(this->renderer)),
    fight(nullptr),
    win(new WinScene(this->renderer)),
    credits(new CreditsScene(this->renderer)),
    oldFights() {

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
  this->connect(this->win, &WinScene::backToMenu,
                this, &GameScreen::showMenu);

  this->showMenu();
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

  for (size_t oldFight = 0;
       oldFight < this->oldFights.size();
       ++oldFight) {
    delete this->oldFights[oldFight];
  }
  this->oldFights.clear();
}

void GameScreen::showCredits() {
  Q_ASSERT(this->credits);
  this->mainSong.pause();
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
  Q_ASSERT(this->menu);
  this->creditsSong.pause();
  this->winningSong.pause();
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
  Monster* player1 = monsterFactory(this->renderer,
                       this->selection->getPlayerChoice(1, 1),
                       this->selection->getPlayerChoice(1, 2));
  Monster* player2 = monsterFactory(this->renderer,
                       this->selection->getPlayerChoice(2, 1),
                       this->selection->getPlayerChoice(2, 2));
  this->fight = new FightScene(this->renderer,
                               player1,
                               player2);
  Q_ASSERT(this->fight);
  this->mainSong.pause();
  this->connect(this->fight, &FightScene::playerWon,
                this, &GameScreen::showWin);
  this->fightSong.play(true);
  this->setScene(this->fight);
  #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    this->setFixedSize(this->fight->width(), this->fight->height());
  #endif
}

void GameScreen::showWin(size_t winner) {
  Q_ASSERT(this->win);
  this->disconnect(this->fight, &FightScene::playerWon,
                this, &GameScreen::showWin);
  this->fightSong.pause();
  this->win->setWinner(winner);
  this->winningSong.play(true);
  this->setScene(this->win);
  this->oldFights.push_back(this->fight);
}

void GameScreen::wheelEvent(QWheelEvent* event) {
  Q_UNUSED(event);
}
