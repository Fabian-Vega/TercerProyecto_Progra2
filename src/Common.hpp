#ifndef COMMON_HPP
#define COMMON_HPP

#include <QUrl>

static const double outOfScreenX = 1690;
static const double outOfScreenY = 1690;

static const QUrl clickSound("qrc:/sounds/ClickSound.wav");
static const QUrl attackSound("qrc:/sounds/AttackSound.wav");
static const QUrl defendSound("qrc:/sounds/DefenseSound.wav");
static const QUrl buffSound("qrc:/sounds/BuffSound.wav");
static const QUrl debuffSound("qrc:/sounds/DebuffSound.wav");
static const QUrl messageSound("qrc:/sounds/MessageSound.wav");

static const QUrl menuSong("qrc:/songs/MenuSong.wav");
static const QUrl battleSong("qrc:/songs/BattleSong.wav");
static const QUrl endSong("qrc:/songs/BattleSong.wav");

static const float generalVolume = 0.50f;

#define DECLARE_RULE4(Class, action) \
  Class(const Class& other) = action; \
  Class(Class&& other) = action; \
  Class& operator=(const Class& other) = action; \
  Class& operator=(Class&& other) = action

#define DISABLE_COPY(Class) \
  DECLARE_RULE4(Class, delete)

void wait(double seconds);

/// Function adapted from Jeisson Hidalgo-Cespedes 2022
int random(int min, int max);

#endif  // COMMON_HPP
