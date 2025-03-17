#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h>  // For instant key detection on macOS/Linux
#include <unistd.h>
#include "counter.h"
#include "timerThread.h"


char getKeyPress() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);   // Get terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore settings
    return ch;
}

int main() {
    int minutes, seconds;
    char command;

    std::cout << "Welcome to Terminal Alarm Timer!!!!!" << std::endl;
    
    std::cout << "Enter minutes: ";
    std::cin >> minutes;

    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    Counter* timer = Counter::create(minutes, seconds);
    TimerThread* timerThread = new TimerThread(timer);

    std::cout << "Press 'S' to start, 'P' to pause, 'R' to restart, 'Q' to quit..." << std::endl;

    while (true) {
        command = getKeyPress();  // Read key press instantly

        switch (command) {
            case 'S': case 's': 
                std::cout << "\nStarting the timer...\n";
                timerThread->start();
                break;

            case 'P': case 'p': 
                std::cout << "\nPausing the timer...\n";
                timerThread->stop();
                break;

            case 'R': case 'r': 
                std::cout << "\nRestarting the timer...\n";
                timerThread->stop();
                delete timerThread;
                delete timer;
                
                std::cout << "\nEnter new minutes: ";
                std::cin >> minutes;
                std::cout << "Enter new seconds: ";
                std::cin >> seconds;
                
                timer = Counter::create(minutes, seconds);
                timerThread = new TimerThread(timer);
                timerThread->start();
                break;

            case 'Q': case 'q': 
                std::cout << "\nQuitting the program...\n";
                timerThread->stop();
                delete timerThread;
                timer->destroy();
                return 0;

            default:
                // std::cout << "\nInvalid command! Use 'S', 'P', 'R', or 'Q'.\n";
        }
    }
}
