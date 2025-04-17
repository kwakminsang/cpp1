#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // 1. 일반 함수 - void 리턴, 참조 전달
    friend void add1(Complex& a, Complex& b, Complex& result) {
        result.real = a.real + b.real;
        result.imag = a.imag + b.imag;
    }

    // 2. 일반 함수 - 값 리턴
    friend Complex add2(Complex a, Complex b) {
        return Complex(a.real + b.real, a.imag + b.imag);
    }

    // 3. 멤버 함수 - void 리턴, 참조 전달
    void add3(Complex& a, Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 4. 멤버 함수 - 값 리턴
    Complex add4(Complex& b) {
        return Complex(real + b.real, imag + b.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(Complex& b) {
        return Complex(real + b.real, imag + b.imag);
    }
};

int main() {
    Complex a(1, 2), b(3, 4), c;

    // 방식 1
    add1(a, b, c);
    cout << "1. 일반 함수 (void, 참조): ";
    c.print();

    // 방식 2
    c = add2(a, b);
    cout << "2. 일반 함수 (값 리턴): ";
    c.print();

    // 방식 3
    c.add3(a, b);
    cout << "3. 멤버 함수 (void, 참조): ";
    c.print();

    // 방식 4
    c = a.add4(b);
    cout << "4. 멤버 함수 (값 리턴): ";
    c.print();

    // 방식 5
    c = a + b;
    cout << "5. 연산자 오버로딩: ";
    c.print();

    return 0;
}
