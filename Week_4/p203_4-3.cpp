#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

struct Move {
    string direction; // 'up', 'down', 'left', 'right'
    int x, y;         // 이동한 칸의 위치 (빈 칸의 위치)
};

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

// 퍼즐을 섞는 함수
void shufflePuzzle(vector<vector<int>>& puzzle) {
    int size = puzzle.size();
    for (int i = 0; i < 100; ++i) {
        int x = 0, y = 0;
        // 빈 칸 위치 찾기
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; ++c) {
                if (puzzle[r][c] == 0) {
                    x = r;
                    y = c;
                    break;
                }
            }
        }
        
        // 빈 칸 주변으로 이동
        int direction = rand() % 4;
        if (direction == 0 && x > 0) swap(puzzle[x][y], puzzle[x-1][y]); // 위
        else if (direction == 1 && x < size - 1) swap(puzzle[x][y], puzzle[x+1][y]); // 아래
        else if (direction == 2 && y > 0) swap(puzzle[x][y], puzzle[x][y-1]); // 왼쪽
        else if (direction == 3 && y < size - 1) swap(puzzle[x][y], puzzle[x][y+1]); // 오른쪽
    }
}

// 이동 함수 (빈 칸 위치와 이동 방향에 따라 퍼즐을 움직이는 함수)
bool movePuzzle(vector<vector<int>>& puzzle, string direction, int& x, int& y) {
    int size = puzzle.size();
    if (direction == "up" && x > 0) {
        swap(puzzle[x][y], puzzle[x-1][y]);
        x--;
        return true;
    } else if (direction == "down" && x < size - 1) {
        swap(puzzle[x][y], puzzle[x+1][y]);
        x++;
        return true;
    } else if (direction == "left" && y > 0) {
        swap(puzzle[x][y], puzzle[x][y-1]);
        y--;
        return true;
    } else if (direction == "right" && y < size - 1) {
        swap(puzzle[x][y], puzzle[x][y+1]);
        y++;
        return true;
    }
    return false; // 유효하지 않은 방향
}

// 게임 상태 저장 함수
void saveGame(const vector<vector<int>>& puzzle, int moveCount, system_clock::time_point startTime, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }

    // 현재 시간을 구하기
    auto now = system_clock::now();
    auto duration = duration_cast<seconds>(now - startTime).count();

    // 게임 상태 저장
    outFile << "퍼즐 크기: " << puzzle.size() << endl;
    outFile << "이동 횟수: " << moveCount << endl;
    outFile << "게임 시작 시간: " << duration << "초" << endl;

    // 퍼즐 상태 저장
    outFile << "퍼즐 상태:" << endl;
    for (size_t i = 0; i < puzzle.size(); ++i) {
        for (size_t j = 0; j < puzzle[i].size(); ++j) {
            outFile << puzzle[i][j] << " ";
        }
        outFile << endl;
    }

    outFile.close();
    cout << "게임 상태가 파일에 저장되었습니다." << endl;
}

// 게임 상태 로드 함수
vector<vector<int>> loadGame(const string& filename, int& moveCount, system_clock::time_point& startTime) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return {};
    }

    string line;
    int size;
    inFile >> line >> size; // "퍼즐 크기" 읽기
    inFile >> line >> moveCount; // "이동 횟수" 읽기
    inFile >> line >> startTime; // "게임 시작 시간" 읽기

    vector<vector<int>> puzzle(size, vector<int>(size));
    inFile.ignore(); // 남은 개행 문자 처리
    inFile >> line; // "퍼즐 상태:" 읽기

    // 퍼즐 상태 로드
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> puzzle[i][j];
        }
    }

    inFile.close();
    return puzzle;
}

// 리플레이 기능
void replayMoves(const vector<Move>& moves) {
    cout << "\n리플레이 시작!" << endl;
    for (const auto& move : moves) {
        cout << "방향: " << move.direction << " (빈 칸 위치: " << move.x << ", " << move.y << ")" << endl;
    }
    cout << "리플레이 종료!" << endl;
}

int main() {
    int size;
    cout << "퍼즐 크기를 선택하세요 (3, 4, 5): ";
    cin >> size;

    if (size != 3 && size != 4 && size != 5) {
        cout << "잘못된 크기입니다." << endl;
        return 1;
    }

    vector<vector<int>> puzzle = initializePuzzle(size);
    vector<vector<int>> originalPuzzle = puzzle; // 초기 퍼즐 상태 저장
    shufflePuzzle(puzzle); // 퍼즐 섞기

    cout << "섞인 퍼즐 상태:" << endl;
    printPuzzle(puzzle);

    int x = size - 1, y = size - 1; // 빈 칸 위치 (초기 값은 맨 마지막 칸)
    vector<Move> moves; // 움직임 기록
    int moveCount = 0; // 이동 횟수
    auto startTime = system_clock::now(); // 게임 시작 시간

    string direction;
    while (true) {
        cout << "\n움직일 방향을 입력하세요 (up, down, left, right, exit, save): ";
        cin >> direction;

        if (direction == "exit") {
            break; // 게임 종료
        }

        if (direction == "save") {
            saveGame(puzzle, moveCount, startTime, "game_save.txt");
            continue; // 게임 상태를 저장하고 계속 진행
        }

        if (movePuzzle(puzzle, direction, x, y)) {
            moveCount++;
            // 움직임 저장
            moves.push_back(Move{direction, x, y});
            cout << "현재 퍼즐 상태:" << endl;
            printPuzzle(puzzle);
        } else {
            cout << "잘못된 방향입니다." << endl;
        }
    }

    // 리플레이 기능
    replayMoves(moves);

    return 0;
}
