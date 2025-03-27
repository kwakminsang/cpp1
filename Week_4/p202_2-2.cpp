#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

using namespace std;

void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
    