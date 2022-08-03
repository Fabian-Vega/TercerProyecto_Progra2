// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstddef>
#include <QPropertyAnimation>
#include <QUrl>

// Forward declarations
class Monster;
class Sound;

static const std::string types[3] = {"Fire", "Water", "Plant"};

static const double outOfScreenX = 1690;
static const double outOfScreenY = 1690;

static const QString assets(":/images/assets.svg");

static const QUrl clickSound("qrc:/sounds/ClickSound.wav");
static const QUrl hoverSound("qrc:/sounds/HoverSound.wav");
static const QUrl attackSound("qrc:/sounds/AttackSound.wav");
static const QUrl defendSound("qrc:/sounds/DefenseSound.wav");
static const QUrl buffSound("qrc:/sounds/BuffSound.wav");
static const QUrl debuffSound("qrc:/sounds/DebuffSound.wav");
static const QUrl messageSound("qrc:/sounds/MessageSound.wav");

static const QUrl menuSong("qrc:/songs/MenuSong.wav");
static const QUrl battleSong("qrc:/songs/BattleSong.wav");
static const QUrl winSong("qrc:/songs/winningSong.wav");
static const QUrl finalSong("qrc:/songs/CreditsSong.wav");

static const float generalVolume = 0.50f;

#define DECLARE_RULE4(Class, action) \
  Class(const Class& other) = action; \
  Class(Class&& other) = action; \
  Class& operator=(const Class& other) = action; \
  Class& operator=(Class&& other) = action

#define DISABLE_COPY(Class) \
  DECLARE_RULE4(Class, delete)

// Enumeration for the different stats
enum StatNum {
  healthStat = 1,
  attackStat = 2,
  defenseStat = 3,
  speedStat = 4
};

// Enumeration for the different moves
enum MoveNum {
  attackMove = 1,
  defenseMove = 2,
  buffMove = 3,
  debuffMove = 4
};

/// Holds the systme for a number of seconds
void wait(double seconds);

/// Function adapted from Jeisson Hidalgo-Cespedes 2022
/// returns a random number between min and max
int random(int min, int max);

/// Creates the proper animation based on the move
QPropertyAnimation* createMoveAnimation(Monster* monster,
                                        size_t move);

/// Creates the proper sound based on the move
Sound* chooseSound(size_t move);

/// Returns the elemetal type modifier
double typeRelation(const int firstType,
const int secondType);

#endif  // COMMON_HPP
