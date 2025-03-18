#include ALARM_M

#include <SDL2/SDL_mixer.h>

Alarm::Alarm(String alarmUrl):alarmUrl(alarmUrl){
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
}

void Alarm::play(){
    alarm = Mix_LoadMUS((songUrl).c_str());
    Mix_PlayMusic(alarm, -1);
}

void Alarm::stop(){
     Mix_PlayMusic(1);
}

Alarm::~Alarm() {
    Mix_FreeMusic(alarm);
    Mix_CloseAudio();
    SDL_Quit();
}

       

       
       