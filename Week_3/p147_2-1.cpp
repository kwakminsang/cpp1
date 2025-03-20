#include <stdio.h>

int reverse(int num) {
int rev = 0;
while (num > 0) {
rev = rev * 10 + num % 10;
num /= 10;
}
return rev;
}

int main() {
int num;
printf(" : ");
scanf("%d", &num);

int reversed = reverse(num);
printf( %d\n", reversed);

return 0;

}

