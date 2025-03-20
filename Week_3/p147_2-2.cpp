#include <stdio.h>

int reverse(int); 

int main() {
int num;
printf("정수를 입력하세요: ");
scanf("%d", &num);

int reversed = reverse(num);
printf("역순 숫자: %d\n", reversed);

return 0;
}

int reverse(int num) { 
int rev = 0;
while (num > 0) {
rev = rev * 10 + num % 10;
num /= 10;
}
return rev;
}