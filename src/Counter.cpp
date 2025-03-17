#include "counter.h"
#include <iostream>

using namespace std; 

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


int Counter::countDown() {
    if (seconds > 0) {
        seconds--;
    } else if (minutes > 0) {
        minutes--;
        seconds = 59;
    } else {
        return 0;
    
    }
    return 1;


}


