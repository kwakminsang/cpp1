#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

void MyTime::convert(double duration) {
    int t = duration * 1000;
    hour = t / 3600000; t %= 3600000;
    minute = t / 60000; t %= 60000;
    second = t / 1000;
    millisecond = t % 1000;
}

void MyTime::print() {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << "."
         << setw(3) << millisecond << endl;
}

MyTime MyTime::add(MyTime t) {
    MyTime tmp;
    int ms1 = ((hour * 3600 + minute * 60 + second) * 1000) + millisecond;
    int ms2 = ((t.hour * 3600 + t.minute * 60 + t.second) * 1000) + t.millisecond;
    tmp.convert((ms1 + ms2) / 1000.0);
    return tmp;
}

void MyTime::reset() {
    hour = minute = second = millisecond = 0;
}

void MyTime::read() {
    cout << "시간 (hour)을 입력하세요: ";
    cin >> hour;
    cout << "분 (minute)을 입력하세요: ";
    cin >> minute;
    cout << "초 (second)를 입력하세요: ";
    cin >> second;
    cout << "밀리초 (millisecond)를 입력하세요: ";
    cin >> millisecond;
}
