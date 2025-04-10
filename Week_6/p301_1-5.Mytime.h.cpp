#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour, minute, second, millisecond;

public:
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif