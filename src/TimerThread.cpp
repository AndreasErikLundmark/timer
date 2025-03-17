
#include <iostream>
#include "counter.h"
#include "timerThread.h"

TimerThread::TimerThread(Counter* counter) : counter(counter)
{
}

TimerThread::~TimerThread() 
{
    stop();
}

void TimerThread::start()
{
    if(!running){
        running = true;
        timerThread = std::thread(&TimerThread::run, this);

    }
}
void TimerThread::stop(){
    running=false;
    if(timerThread.joinable()){
        timerThread.join();
    }

}
void TimerThread::run(){
    int counting = 1;
    while(counting!=0){
        counting= counter->countDown();
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}


