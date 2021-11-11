#include <iostream> 

using namespace std;

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

int  main() {
  Counter c1, c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  ++c1;
  for(int i =0; i < 100; ++i)
     ++c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  c1++;
  c2++;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  Counter c3;
  Counter c4(2);
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = c4++;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = ++c4;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  return 0;
}
