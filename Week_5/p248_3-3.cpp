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

void addTime(MyTime t1, MyTime t2, MyTime *pt) {
    if (pt) {  // NULL 포인터 예외 처리
        int totalMinutes = (t1.hours + t2.hours) * 60 + (t1.minutes + t2.minutes);
        pt->hours = totalMinutes / 60;
        pt->minutes = totalMinutes % 60;
    }
}

int main() {
    MyTime t1(2, 50), t2(1, 30), result;
    addTime(t1, t2, &result);
    result.display();
    return 0;
}
