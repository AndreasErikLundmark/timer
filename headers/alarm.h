#ifndef ALARM_H
#define ALARM_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Alarm {
public:
    static Alarm* create(std::string alarmUrl);
    void play();
    void stop();
    ~Alarm();

protected:
    Alarm(std::string alarmUrl);

private:
    Mix_Music* alarm;
    std::string alarmUrl;
};

#endif
