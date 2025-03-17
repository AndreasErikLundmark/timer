#include <iostream>
#include "counter.h"
#include "timerThread.h"

int main() {
    std::cout << "Starting the timer..." << std::endl;

    
    Counter* timer = Counter::create(0, 10);

    
    TimerThread timerThread(timer);
    timerThread.start();

    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Main thread is still running..." << std::endl;

   
    timerThread.stop();

   
    timer->destroy();

    std::cout << "Timer finished." << std::endl;
    return 0;
}