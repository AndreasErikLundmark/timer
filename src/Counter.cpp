#include "counter.h"

using namespace std;  // Only use if necessary

Counter* Counter::create(int minutes, int seconds)
{
    return new Counter(minutes, seconds);
}

Counter::Counter(int minutes, int seconds) 
    : minutes(minutes), seconds(seconds) {} 


Counter::~Counter() {
    std::cout << "Counter deleted" << std::endl;
}


void Counter::destroy() {
    delete this;  
}


void Counter::countDown() {
    if (seconds > 0) {
        seconds--;
    } else if (minutes > 0) {
        minutes--;
        seconds = 59;
    } else {
        // Time is up
    }
}
