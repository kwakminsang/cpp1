#include <iostream>

int main() {
    for (int i = 5; i >= 1; i--) { 
        for (int j = 5; j >= i; j--) {
            std::cout << j;
        }
        std::cout << std::endl; 
    }
    return 0;
}
