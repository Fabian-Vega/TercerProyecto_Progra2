QT += core gui widgets svg multimedia svgwidgets
TEMPLATE = app
TARGET = FightMon
CONFIG += c++17

SOURCES += \
  src/Game.cpp \
  src/GameScreen.cpp \
  src/MenuScene.cpp \
  src/SelectionScreen.cpp \
  src/main.cpp \

HEADERS += \
  src/Game.hpp \
  src/GameScreen.hpp \
<<<<<<< Updated upstream
  src/MenuScene.hpp
=======
  src/InstructionsScene.hpp \
  src/MenuScene.hpp \
  src/SelectionScreen.hpp
>>>>>>> Stashed changes

RESOURCES += \
  assets/assets.qrc

FORMS +=
