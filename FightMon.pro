QT += core gui widgets svg multimedia svgwidgets
TEMPLATE = app
TARGET = FightMon
CONFIG += c++17

SOURCES += \
  src/Game.cpp \
  src/GameScreen.cpp \
  src/MenuScene.cpp \
  src/main.cpp \

HEADERS += \
  src/Game.hpp \
  src/GameScreen.hpp \
  src/MenuScene.hpp

RESOURCES += \
  assets/assets.qrc
