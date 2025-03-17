#ifndef TIMER_THREAD_H
#define TIMER_THREAD_H


#include "counter.h"
#include <thread>
#include <atomic>

class TimerThread
{
    public: 
    TimerThread(Counter* counter);

    ~TimerThread();
    
    void start();
    void stop();

    protected:
    void run();

    private:
    Counter* counter;
    std::thread timerThread;
    std::atomic<bool> running;
};
#endif 

