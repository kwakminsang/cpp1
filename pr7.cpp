#include <iostream>
#include <vector>
using namespace std;

string convertToKorean(int num) {
    if (num <= 0 || num >= 100000) return "범위를 벗어난 입력입니다.";

    vector<string> units = {"", "십", "백", "천", "만"};
    vector<string> numbers = {"", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
    vector<string> result;
    
    int divisor = 10000;
    bool hasPrevious = false;
    for (int i = 4; i >= 0; --i) {
        int digit = num / divisor;
        num %= divisor;
        divisor /= 10;

        if (digit > 0) {
            if (!(digit == 1 && i > 0)) result.push_back(numbers[digit]); // 10단위 이상에서 '1' 생략
            result.push_back(units[i]);
            hasPrevious = true;
        }
    }
    
    string output;
    for (const string &part : result) {
        if (!part.empty()) {
            output += part + " ";
        }
    }
    
    return output;
}

int main() {
    int num;
    cout << "1부터 99999까지의 숫자를 입력하세요: ";
    cin >> num;
    cout << "출력: " << convertToKorean(num) << endl;
    return 0;
}
