#ifndef TICKING_H
#define TICKING_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Ticking {
public:
    static Ticking* create(std::string tickingUrl);
    void play();
    void stop();
    void resume();
    ~Ticking();

protected:
    Ticking(std::string tickingUrl);

private:
    Mix_Music* ticking;
    std::string tickingUrl;
};

#endif
