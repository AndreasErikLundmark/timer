#include <iostream>
#include "counter.h"
#include "timerThread.h"

int main() {
    std::cout << "Starting the timer..." << std::endl;

    
    Counter* timer = Counter::create(0, 10);

    
    TimerThread timerThread(timer);
    timerThread.start();

   
    timerThread.stop();

   
    timer->destroy();

    std::cout << "Timer finished." << std::endl;
    return 0;
}