#ifndef MOVESETLAYOUT_H
#define MOVESETLAYOUT_H

#include <QGraphicsSvgItem>

// Forward declaration
class GameButton;
class Monster;
class QSvgRenderer;

class MovesetLayout : public QGraphicsSvgItem {
  Q_OBJECT

 protected: // Attributes
  QSvgRenderer* renderer;
  GameButton* damageMove;
  GameButton* defenseMove;
  GameButton* buffMove;
  GameButton* debuffMove;

 public: // Constructor and Destructor
  MovesetLayout(QSvgRenderer* renderer,
                Monster* monster,
                QGraphicsItem* parentItem = nullptr);

 signals: // Signals
  void moveSelected(size_t move);

 protected slots: // selectMove Method
  void selectMove(size_t buttonNumber);

 public: // Accesors(Sets and Gets)
  /// Gets the background for the moves
  inline QGraphicsSvgItem* getBase() {
    return this;
  }
  /// Gets the button corresponding to the attack move
  inline GameButton* getDamageButton() {
    return this->damageMove;
  }
  /// Gets the button corresponding to the defense move
  inline GameButton* getDefenseButton() {
    return this->defenseMove;
  }
  /// Gets the button corresponding to the buff move
  inline GameButton* getBuffButton() {
    return this->buffMove;
  }
  /// Gets the button corresponding to the debuff move
  inline GameButton* getDebuffButton() {
    return this->debuffMove;
  }

 public: // General Methods
  void setLayoutPos(const double xPos,
                    const double yPos);

 protected: // Initializers
  GameButton* setButton(GameButton* button,
                        size_t buttonNumber,
                        QString identifier);
  void setMovesetLayout(Monster* monster);
};

#endif // MOVESETLAYOUT_H
