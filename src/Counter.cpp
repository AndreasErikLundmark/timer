#include "counter.h"
#include <iostream>
#include "alarm.h"
#include "ticking.h"

using namespace std; 

Counter* Counter::create(int minutes, int seconds, Alarm* alarm, Ticking* ticking)
{
    return new Counter(minutes, seconds, alarm, ticking);
}

Counter::Counter(int minutes, int seconds, Alarm* alarm, Ticking* ticking) 
    : minutes(minutes), seconds(seconds), alarm(alarm), ticking(ticking) {} 


Counter::~Counter() {
   
}


void Counter::destroy() {
    delete this;  
}


int Counter::countDown() {
    ticking->play();
    if (seconds > 0) {
        seconds--;
    } else if (minutes > 0) {
        minutes--;
        seconds = 59;
    } else {
      
        printEnd();
        ticking->stop();
        alarm->play();
        return 0;
    
    }
  
    printTime();
    

    return 1;


}
void Counter::printTime(){
     std::cout << "\033[2J\033[H";
      printUserInfo(); 
    std::cout << "Min: " << minutes << " Seconds: " << seconds << std::endl;
}

void Counter::printEnd(){
    std::cout << "\033[2J\033[H"; 
     printUserInfo();

    std::cout << "Time is Up!!!"<< std::endl;
    
}

void Counter::printUserInfo(){
   
        std::cout << "Press 'S' to start, 'P' to pause, ,'C' to continue, 'R' to restart, 'Q' to quit..." << std::endl;
        std::cout << "----------------------------------------------------------------------------------" << std::endl;
        std::cout<<""<< std::endl;
}




