QT += core gui widgets svg multimedia svgwidgets
TEMPLATE = app
TARGET = FightMon
CONFIG += c++17

SOURCES += \
  src/BuffMove.cpp \
  src/Common.cpp \
  src/CreditsScene.cpp \
  src/DamageMove.cpp \
  src/DefenseMove.cpp \
  src/FightScene.cpp \
  src/Game.cpp \
  src/GameButton.cpp \
  src/GameScene.cpp \
  src/GameScreen.cpp \
  src/HealthBar.cpp \
  src/InstructionsScene.cpp \
  src/MenuScene.cpp \
  src/Monster.cpp \
  src/Move.cpp \
  src/MovesetLayout.cpp \
  src/SelectionPlate.cpp \
  src/SelectionScene.cpp \
  src/Sound.cpp \
  src/SpeedsterMonster.cpp \
  src/TankMonster.cpp \
  src/WarriorMonster.cpp \
  src/WinScene.cpp \
  src/main.cpp \

HEADERS += \
  src/BuffMove.hpp \
  src/Common.hpp \
  src/CreditsScene.hpp \
  src/DamageMove.hpp \
  src/DefenseMove.hpp \
  src/FightScene.hpp \
  src/Game.hpp \
  src/GameButton.hpp \
  src/GameScene.hpp \
  src/GameScreen.hpp \
  src/HealthBar.hpp \
  src/InstructionsScene.hpp \
  src/MenuScene.hpp \
  src/Monster.hpp \
  src/Move.hpp \
  src/MovesetLayout.hpp \
  src/SelectionPlate.hpp \
  src/SelectionScene.hpp \
  src/Sound.hpp \
  src/SpeedsterMonster.hpp \
  src/TankMonster.hpp \
  src/WarriorMonster.hpp \
  src/WinScene.hpp

RESOURCES += \
  assets/assets.qrc

FORMS +=
