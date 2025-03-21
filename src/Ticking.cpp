#include "ticking.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>


Ticking::Ticking(std::string tickingUrl):tickingUrl(tickingUrl){
    
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
}

Ticking* Ticking::create(std::string tickingUrl){
    return new Ticking(tickingUrl);
}

void Ticking::play(){
    ticking = Mix_LoadMUS((tickingUrl).c_str());        
    Mix_PlayMusic(ticking, -1);
}

void Ticking::stop(){
    //  Mix_HaltMusic(-1);
     Mix_HaltMusic();
}

void Ticking::resume(){
    Mix_Resume(-1);
}

Ticking::~Ticking() {
    Mix_FreeMusic(ticking);
    Mix_CloseAudio();
    SDL_Quit();
}

       
