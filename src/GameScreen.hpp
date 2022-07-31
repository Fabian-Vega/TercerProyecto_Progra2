#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>

// Forward declarations
class FightScene;
class InstructionsScene;
class MenuScene;
class Monster;
class QSvgRenderer;
class SelectionScene;

class GameScreen : public QGraphicsView {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  MenuScene* menu;
  InstructionsScene* instructions;
  SelectionScene* selection;
  FightScene* fight = nullptr;

 public:
  explicit GameScreen(QWidget* parent = nullptr);
  ~GameScreen();

 protected slots:
  void showInstructions();
  void showMenu();
  void startGame();
  void startFight();

 protected:
  Monster* monsterFactory(short element, short type) const;
};

#endif // GAMESCREEN_HPP
