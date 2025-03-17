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
      
     
        printEnd();
      
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
   
     std::cout << "'S': START!, 'P': Pause, 'R': Restart, 'Q': Quit " << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        std::cout<<""<< std::endl;
}



