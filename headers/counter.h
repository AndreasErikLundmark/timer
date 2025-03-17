
#ifndef COUNTER_H
#define COUNTER_H



class Counter
{

public:
    static create(int minutes, int seconds);
    virtual void countDown();

protected:
    Counter*(int minutes, int seconds)
   

private:
    int minutes;
    int seconds;
    
    
};

#endif
