#include <stdio.h>

double heron(double x, double w, double approx){
    double w_neu = ((w+(x/w))/2);
    return x == 0 ? 0 : (w-w_neu) < approx && w != 1 ? w : heron(x, w_neu, approx);
}

double potenz_negativ(int basis, int potenz){
    double result = 0;
    for(; (-1 * potenz) > 0; potenz++){
        result = result == 0 ? basis : result * basis;
    }
    return 1.0 / result;
}

int main(void){
    int x;
    while(x != EOF){
        scanf("%d", &x);
        printf("%f \n", heron(x, 1.0, potenz_negativ(10, -7)));
    }
    return 0;
}
