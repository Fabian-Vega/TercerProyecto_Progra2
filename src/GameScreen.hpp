#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>

// Forward declarations
class InstructionsScene;
class MenuScene;
class QSvgRenderer;
class SelectionScene;

class GameScreen : public QGraphicsView {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  MenuScene* menu;
  InstructionsScene* instructions;
  SelectionScene* selection;

 public:
  explicit GameScreen(QWidget* parent = nullptr);
  ~GameScreen();

 protected slots:
  void showInstructions();
  void showMenu();
  void startGame();
};

#endif // GAMESCREEN_HPP
