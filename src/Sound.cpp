#include "Common.hpp"
#include "Sound.hpp"

Sound::Sound(const QUrl url, QObject *parent)
  : QSoundEffect(parent) {
  this->setSound(url);
}

void Sound::setSound(QUrl url) {
  this->setSource(url);
  this->setVolume(generalVolume);
}

void Sound::play(bool loop) {
  if(!this->isPlaying()) {
    if (loop) {
      this->setLoopCount(QSoundEffect::Infinite);
    }
    QSoundEffect::play();
  }
}

void Sound::pause() {
  if (this->isPlaying()) {
    this->stop();
  }
}
