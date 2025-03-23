#include <iostream>
#include <cstdlib>
#include <ctime>

void playAdditionOnce() {
    int num1 = rand() % 900 + 100; // 100~999 사이의 숫자
    int num2 = rand() % 900 + 100; // 100~999 사이의 숫자
    int answer;

    std::cout << num1 << " + " << num2 << " = ";
    std::cin >> answer;

    std::cout << ((answer == num1 + num2) ? "정답입니다! 🎉\n" : "틀렸습니다. 정답: " + std::to_string(num1 + num2) + " ❌\n");
}

int main() {
    srand(time(0)); // 랜덤 시드 설정
    playAdditionOnce(); // 덧셈 문제 실행
    return 0;
}
