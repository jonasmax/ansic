#include <stdio.h>

int main(){
    char a = 7;
    char b = 3;
    printf("%d, ", a | b);
    printf("%d, ", a ^ b);
    printf("%d, ", ~(~a & ~b));
    printf("%d, ", a << 1);
    printf("%d, ", a >> 2);
    return 0;
}
