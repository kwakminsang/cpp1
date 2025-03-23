#include <iostream>

int reverse(int num) {
    int revNum = 0;
    while (num > 0) {
        revNum = revNum * 10 + num % 10; // 마지막 자리 숫자를 추가
        num /= 10; // 숫자를 한 자리 줄임
    }
    return revNum;
}

int main() {
    int number;
    std::cout << "정수를 입력하세요: ";
    std::cin >> number;

    int reversed = reverse(number);
    std::cout << "역순 결과: " << reversed << std::endl;

    return 0;
}
