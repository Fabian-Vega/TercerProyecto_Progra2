#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <QGraphicsView>

// Forward declarations
class MenuScene;
class QSvgRenderer;

class GameScreen : public QGraphicsView {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  MenuScene* menu;

 public:
  explicit GameScreen(QWidget *parent = nullptr);
  ~GameScreen();
};

#endif // GAMESCREEN_HPP
