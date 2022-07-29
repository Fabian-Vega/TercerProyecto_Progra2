QT += core gui widgets svg multimedia svgwidgets
TEMPLATE = app
TARGET = FightMon
CONFIG += c++17

SOURCES += \
  src/Game.cpp \
  src/GameButton.cpp \
  src/GameScene.cpp \
  src/GameScreen.cpp \
  src/InstructionsScene.cpp \
  src/MenuScene.cpp \
  src/main.cpp \

HEADERS += \
  src/Game.hpp \
  src/GameButton.hpp \
  src/GameScene.hpp \
  src/GameScreen.hpp \
  src/InstructionsScene.hpp \
  src/MenuScene.hpp

RESOURCES += \
  assets/assets.qrc

FORMS +=
