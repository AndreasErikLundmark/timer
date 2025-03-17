
#ifndef COUNTER_H
#define COUNTER_H



class Counter
{

public:
    static Counter* create(int minutes, int seconds);
    virtual int countDown();
    virtual ~Counter();
    virtual void destroy();
    void printTime();
    void printEnd();


protected:
    Counter(int minutes, int seconds);
   

private:
    int minutes;
    int seconds;
    
    
};

#endif
