#include <iostream>
#include "counter.h"

using namespace std;

Counter::Counter() {
    target = 0;
}

Counter::Counter(int count) {
    target = count;
}

int Counter::getCount(){
    return target;
}

Counter Counter::operator++(){
    Counter temp;
    temp.target = ++target;
    return temp;
}

Counter Counter::operator++(int) {
    Counter temp;
    temp.target = target++;
    return temp;
}
