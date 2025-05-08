#include <iostream>
#include <cstring>

using namespace std;

class Sample {
    char* name;
    static int count;

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 문자열을 받아서 초기화하는 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 정적 함수: 현재 객체 수 출력
    static void printCount() {
        cout << "Sample 객체 수: " << count << endl;
    }

    // 이름 출력 (테스트용)
    void printName() const {
        cout << "이름: " << (name ? name : "없음") << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

// 메인 함수
int main() {
    Sample::printCount(); // 0개

    Sample a("sample");
    Sample::printCount(); // 1개

    Sample b(a);
    Sample::printCount(); // 2개

    a.printName(); // sample
    b.printName(); // sample

    return 0;
}
