#include <iostream>
#include <vector>

using namespace std;

// 퍼즐 맵 출력 함수
void printPuzzle(const vector<vector<int>>& puzzle) {
    for (size_t i = 0; i < puzzle.size(); ++i) {
        for (size_t j = 0; j < puzzle[i].size(); ++j) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

// 퍼즐 맵 초기화 함수
vector<vector<int>> initializePuzzle(int size) {
    vector<vector<int>> puzzle(size, vector<int>(size));

    int num = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) {
                puzzle[i][j] = 0; // 마지막 칸은 0 (빈 칸)
            } else {
                puzzle[i][j] = num++;
            }
        }
    }
    return puzzle;
}

int main() {
    int size;
    
    // 퍼즐 크기 선택
    cout << "퍼즐 크기를 선택하세요 (3, 4, 5): ";
    cin >> size;

    // 크기가 3, 4, 5 외의 값은 잘못된 입력으로 처리
    if (size != 3 && size != 4 && size != 5) {
        cout << "잘못된 크기입니다." << endl;
        return 1;
    }

    // 퍼즐 맵 초기화
    vector<vector<int>> puzzle = initializePuzzle(size);

    // 퍼즐 출력
    cout << "초기 퍼즐 상태:" << endl;
    printPuzzle(puzzle);

    return 0;
}
