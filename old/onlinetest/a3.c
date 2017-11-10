#include <stdio.h>

double potenz(double a, double n){
    double ergebnis = a;
    for(int i = 1; i < n; i++){
        ergebnis *= a;
    }
    return ergebnis;
}

double betrag(double zahl){
    if(zahl < 0){
        zahl = -zahl;
    }
    return zahl;
}

double nroot(double n, double x, double eps){
    double a_i = x;
    double a_iPlus1 = 0;
    double temp;
    do{
        a_iPlus1 = a_i - ((potenz(a_i, n) - x) / (n * potenz(a_i, n-1)));
        temp = a_i;
        a_i = a_iPlus1;
    }while(betrag(a_iPlus1 - temp) > eps);
    
    return a_i;
}


int main(){
    printf("%f", nroot(2, 2, 0.001));
    return 0;
}
