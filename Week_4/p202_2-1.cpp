#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

using namespace std;
void randomMap(int map[5][5]) {
    srand(time(0)); // 랜덤 시드 설정
    for (int i = 0; i < 5; i++) {
         for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 0 또는 1 생성
         }
    }
 }