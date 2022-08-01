#ifndef MOVESETLAYOUT_H
#define MOVESETLAYOUT_H

#include <QGraphicsSvgItem>

// Forward declaration
class GameButton;
class Monster;
class QSvgRenderer;

class MovesetLayout : public QGraphicsSvgItem {
  Q_OBJECT

 protected:
  QSvgRenderer* renderer;
  GameButton* damageMove;
  GameButton* defenseMove;
  GameButton* buffMove;
  GameButton* debuffMove;

 public:
  MovesetLayout(QSvgRenderer* renderer,
                Monster* monster,
                QGraphicsItem* parentItem = nullptr);
  ~MovesetLayout();
 signals:
  void moveSelected(size_t move);

 protected slots:
  void selectMove(size_t buttonNumber);

 public:
  inline QGraphicsSvgItem* getBase() {
    return this;
  }

  inline GameButton* getDamageButton() {
    return this->damageMove;
  }

  inline GameButton* getDefenseButton() {
    return this->defenseMove;
  }

  inline GameButton* getBuffButton() {
    return this->buffMove;
  }

  inline GameButton* getDebuffButton() {
    return this->debuffMove;
  }

 public:
  void setLayoutPos(const double xPos,
                    const double yPos);

 protected:
  GameButton* setButton(GameButton* button,
                        size_t buttonNumber,
                        QString identifier);
  void setMovesetLayout(Monster* monster);
};

#endif // MOVESETLAYOUT_H
