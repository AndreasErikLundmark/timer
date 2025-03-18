#include "alarm.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>


Alarm::Alarm(std::string alarmUrl):alarmUrl(alarmUrl){
    // SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
}

Alarm* Alarm::create(std::string alarmUrl){
    return new Alarm(alarmUrl);
}

void Alarm::play(){
    alarm = Mix_LoadMUS((alarmUrl).c_str());        
    Mix_PlayMusic(alarm, -1);
}

void Alarm::stop(){
    //  Mix_HaltMusic(-1);
     Mix_HaltMusic();
}

void Alarm::resume(){
    Mix_Resume(-1);
}

Alarm::~Alarm() {
    Mix_FreeMusic(alarm);
    Mix_CloseAudio();
    SDL_Quit();
}

       

       
       