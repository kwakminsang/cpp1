#include <iostream>
#include <cstdlib>
#include <ctime>

void playMultiplicationOnce(int digits) {
    int a = rand() % (9 * pow(10, digits - 1)) + pow(10, digits - 1);
    int b = rand() % (9 * pow(10, digits - 1)) + pow(10, digits - 1);
    int ans;
    std::cout << a << " × " << b << " = "; std::cin >> ans;
    std::cout << ((ans == a * b) ? "정답입니다! 🎉\n" : "틀렸습니다. 정답: " + std::to_string(a * b) + " ❌\n");
}

void playAdditionOnce(int digits) {
    int a = rand() % (9 * pow(10, digits - 1)) + pow(10, digits - 1);
    int b = rand() % (9 * pow(10, digits - 1)) + pow(10, digits - 1);
    int ans;
    std::cout << a << " + " << b << " = "; std::cin >> ans;
    std::cout << ((ans == a + b) ? "정답입니다! 🎉\n" : "틀렸습니다. 정답: " + std::to_string(a + b) + " ❌\n");
}

int main() {
    srand(time(0));
    int choice;
    
    std::cout << "게임을 선택하세요:\n";
    std::cout << "1: 구구단 문제\n2: 두 자리 수 곱셈 문제\n";
    std::cout << "3~9: 해당 자리 수의 덧셈 문제\n선택: ";
    std::cin >> choice;

    if (choice == 1)
        playMultiplicationOnce(1);
    else if (choice == 2)
        playMultiplicationOnce(2);
    else if (choice >= 3 && choice <= 9)
        playAdditionOnce(choice);
    else
        std::cout << "잘못된 선택입니다. 프로그램을 종료합니다.\n";

    return 0;
}
