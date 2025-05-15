#include <iostream>
using namespace std;

// Point 클래스 정의
class Point {
private:
    int x, y;  // (4) private 멤버 변수

public:
    // 생성자
    Point(int xx, int yy) : x(xx), y(yy) { }

    // 접근자 함수 (해결책)
    int getX() const { return x; }
    int getY() const { return y; }

    // 가상 함수 draw()
    virtual void draw() {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// Rectangle 클래스 정의 (Point 상속)
class Rectangle : public Point {
private:
    int width, height;  // (1) 추가된 멤버 변수

public:
    // 생성자 - 초기화 리스트 사용 (2)
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }

    // draw() 함수 오버라이딩 (3)
    void draw() override {
        cout << getX() << "," << getY()
             << "에 가로 " << width
             << " 세로 " << height
             << "인 사각형을 그려라.\n";
    }
};

// main 함수 - 테스트용
int main() {
    Rectangle r(2, 3, 100, 200);
    r.draw();  // 출력: 2,3에 가로 100 세로 200인 사각형을 그려라.
    return 0;
}
