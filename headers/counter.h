
#ifndef COUNTER_H
#define COUNTER_H

#include "alarm.h"



class Counter
{

public:
    static Counter* create(int minutes, int seconds, Alarm* alarm);
    int countDown();
    ~Counter();
    void destroy();
    void printTime();
    void printEnd();
    void printUserInfo();


protected:
    Counter(int minutes, int seconds, Alarm* alarm);
   

private:
    int minutes;
    int seconds;
    Alarm* alarm;
    
    
};

#endif
