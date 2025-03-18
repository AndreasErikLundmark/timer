#define ALARM_M

#include <SDL2/SDL_mixer.h>

class Alarm
{

    public:
     static Alarm* create();
     void start();
     void stop();
    

    protected:
        Alarm();


    private:
    
}


#endif