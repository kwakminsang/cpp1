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

void addTime(MyTime t1, MyTime t2, MyTime &t3) {
    int totalMinutes = (t1.hours + t2.hours) * 60 + (t1.minutes + t2.minutes);
    t3.hours = totalMinutes / 60;
    t3.minutes = totalMinutes % 60;
}

int main() {
    MyTime t1(2, 50), t2(1, 30), result;
    addTime(t1, t2, result);
    result.display();
    return 0;
}
