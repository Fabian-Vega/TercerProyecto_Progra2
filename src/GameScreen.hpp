#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>

#include "Sound.hpp"

// Forward declarations
class EndScene;
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
  Sound endingSong;
  MenuScene* menu;
  InstructionsScene* instructions;
  SelectionScene* selection;
  FightScene* fight;
  EndScene* end;

 public:
  explicit GameScreen(QWidget* parent = nullptr);
  ~GameScreen();

 protected slots:
  void showInstructions();
  void showMenu();
  void startGame();
  void startFight();
  void showEndScreen(size_t winner);

 protected:
  Monster* monsterFactory(size_t element, size_t type) const;
  void wheelEvent(QWheelEvent *event) override;
};

#endif // GAMESCREEN_HPP
