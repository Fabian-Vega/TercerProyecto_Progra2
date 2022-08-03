#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>
#include <vector>

#include "Sound.hpp"

// Forward declarations
class CreditsScene;
class WinScene;
class FightScene;
class InstructionsScene;
class MenuScene;
class Monster;
class QSoundEffect;
class QSvgRenderer;
class SelectionScene;

class GameScreen : public QGraphicsView {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  Sound mainSong;
  Sound fightSong;
  Sound winningSong;
  Sound creditsSong;

  MenuScene* menu;
  InstructionsScene* instructions;
  SelectionScene* selection;
  FightScene* fight;
  WinScene* win;
  CreditsScene* credits;

  std::vector<FightScene*> oldFights;

 public:
  explicit GameScreen(QWidget* parent = nullptr);
  ~GameScreen();

 protected slots:
  void showCredits();
  void showInstructions();
  void showMenu();
  void startGame();
  void startFight();
  void showWin(size_t winner);

 protected:
  Monster* monsterFactory(size_t element, size_t type) const;
  void wheelEvent(QWheelEvent *event) override;
};

#endif // GAMESCREEN_HPP
