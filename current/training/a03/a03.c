#include <stdio.h>

#define A_LEN 5

void printAlpha(int anzahl, char alpha){
    int i;
    for(i=0; i<anzahl; i++){
        printf("%c", alpha);
    }
}

void roem(int zahl){
    char alpha[A_LEN] = {'C', 'L', 'X', 'V', 'I'};
    int value[A_LEN] = {100, 50, 10, 5, 1};
    int i, anzahl;
    
    for(i=0; i < A_LEN; i++){
        if((anzahl = zahl / value[i])){
            printAlpha(anzahl, alpha[i]);
            zahl = zahl % value[i];
        }
    }
    
}
    
int main(){
    int zahl;
    scanf("%d", &zahl);
    roem(zahl);
    return 0;
}
