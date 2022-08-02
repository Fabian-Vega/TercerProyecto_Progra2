#ifndef SOUND_HPP
#define SOUND_HPP

#include <QSoundEffect>

class Sound : public QSoundEffect {
 Q_OBJECT


 public: // Constructor
  Sound(const QUrl url, QObject *parent = nullptr);

 protected: // Accesor (Sets and Gets)
  void setSound(const QUrl url);

 public: // General Methods
  void play(bool loop);
  void pause();
};

#endif // SOUND_HPP
