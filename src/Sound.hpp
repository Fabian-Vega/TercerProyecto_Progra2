#ifndef SOUND_HPP
#define SOUND_HPP

#include <QSoundEffect>

class Sound : public QSoundEffect {
 Q_OBJECT


 public:
  Sound(const QUrl url, QObject *parent = nullptr);

 protected:
  void setSound(const QUrl url);

 public:
  void play(bool loop);
  void pause();
};

#endif // SOUND_HPP
