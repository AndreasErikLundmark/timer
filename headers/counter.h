
#ifndef COUNTER_H
#define COUNTER_H

#include "alarm.h"
#include "ticking.h"




class Counter
{

public:
    static Counter* create(int minutes, int seconds, Alarm* alarm, Ticking* ticking);
    int countDown();
    ~Counter();
    void destroy();
    void printTime();
    void printEnd();
    void printUserInfo();


protected:
    Counter(int minutes, int seconds, Alarm* alarm, Ticking* ticking);
   

private:
    int minutes;
    int seconds;
    Alarm* alarm;
    Ticking* ticking;    
};

#endif
