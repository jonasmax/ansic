#include <stdio.h>


int main(){
    int summe = 0;
   
    printf("char: %d \n", sizeof(char));
    printf("short: %d\n", sizeof(short));
    printf("int: %d\n", sizeof(int));
    printf("unsigned int: %d\n", sizeof(unsigned));
    printf("int*: %d\n", sizeof(int*));
    printf("char*: %d\n", sizeof(char*));
    printf("long: %d\n", sizeof(long));
    printf("long long: %d\n", sizeof(long long));
    printf("float: %d\n", sizeof(float));
    printf("double: %d\n", sizeof(double));
    printf("long double: %d\n\n", sizeof(long double));
    
    
    summe = sizeof(char) + sizeof(short) + sizeof(int) + sizeof(unsigned int) + 
    sizeof(int*) + sizeof(char*) + sizeof(long) + sizeof(long long) + 
    sizeof(float) + sizeof(double) + sizeof(long double);
    printf("Summe: %d\n", summe);
    return 0;
}
