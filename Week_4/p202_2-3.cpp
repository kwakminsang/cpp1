#include <iostream>

using namespace std;

void checkMap(int map[5][5]) {
    // 가로줄 검사
    for (int i = 0; i < 5; i++) {
        bool allZero = true, allOne = true;
        for (int j = 0; j < 5; j++) {
            if (map[i][j] != 0) allZero = false;
            if (map[i][j] != 1) allOne = false;
        }
        if (allZero || allOne) {
            cout << "Row " << i << " is all " << (allZero ? "0s" : "1s") << endl;
        }
    }

    // 세로줄 검사
    for (int j = 0; j < 5; j++) {
        bool allZero = true, allOne = true;
        for (int i = 0; i < 5; i++) {
            if (map[i][j] != 0) allZero = false;
            if (map[i][j] != 1) allOne = false;
        }
        if (allZero || allOne) {
            cout << "Column " << j << " is all " << (allZero ? "0s" : "1s") << endl;
        }
    }

    // 주대각선 검사 (왼쪽 위 → 오른쪽 아래)
    bool allZero = true, allOne = true;
    for (int i = 0; i < 5; i++) {
        if (map[i][i] != 0) allZero = false;
        if (map[i][i] != 1) allOne = false;
    }
    if (allZero || allOne) {
        cout << "Main diagonal is all " << (allZero ? "0s" : "1s") << endl;
    }

    // 반대각선 검사 (오른쪽 위 → 왼쪽 아래)
    allZero = true, allOne = true;
    for (int i = 0; i < 5; i++) {
        if (map[i][4 - i] != 0) allZero = false;
        if (map[i][4 - i] != 1) allOne = false;
    }
    if (allZero || allOne) {
        cout << "Anti-diagonal is all " << (allZero ? "0s" : "1s") << endl;
    }
}

int main() {
    int map[5][5] = {
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };

    checkMap(map);

    return 0;
}
