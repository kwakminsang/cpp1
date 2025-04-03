#include <iostream>
using namespace std;

class MyTime {
public:
    int hours, minutes;
    
    MyTime(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() {
        cout << hours << "시간 " << minutes << "분" << endl;
    }
};

MyTime addTime(MyTime t1, MyTime t2) {
    int totalMinutes = (t1.hours + t2.hours) * 60 + (t1.minutes + t2.minutes);
    return MyTime(totalMinutes / 60, totalMinutes % 60);
}

int main() {
    MyTime t1(2, 50), t2(1, 30);
    MyTime result = addTime(t1, t2);
    result.display();
    return 0;
}
