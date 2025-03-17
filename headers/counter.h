
#ifndef COUNTER_H
#define COUNTER_H



class Counter
{

public:
    static Counter* create(int minutes, int seconds);
    virtual void countDown();
    virtual ~Counter();
    virtual void destroy();

protected:
    Counter(int minutes, int seconds);
   

private:
    int minutes;
    int seconds;
    
    
};

#endif
