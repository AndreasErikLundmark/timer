
#ifndef COUNTER_H
#define COUNTER_H



class Counter
{

public:
    static Counter* create(int minutes, int seconds);
    int countDown();
    ~Counter();
    void destroy();
    void printTime();
    void printEnd();
    void printUserInfo();


protected:
    Counter(int minutes, int seconds);
   

private:
    int minutes;
    int seconds;
    
    
};

#endif
