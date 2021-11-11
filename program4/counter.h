#ifndef COUNTER_H
#define COUNTER_H

class Counter {
    private: 
        int target;
    public:
        Counter();
        Counter(int);
        int getCount();
        Counter operator++();
        Counter operator++(int);
};

#endif