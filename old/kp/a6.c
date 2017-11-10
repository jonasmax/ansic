#include <stdio.h>

double heron(double e, double x, double a)
{
    double previous = a;
    a = (a + (x/a)) / 2;
    
    double test = previous/a;
    if((previous-a) >= e || (previous-a) < 0)
    {
        return heron(e, x, a);
    }
    return a;
}

double hoch(double basis, double exponent)
{
    if(exponent < 0)
    {
        exponent = exponent * (-1);
    }
    
    double ergebnis = basis;
    for(int i = 1; i <= exponent; i++)
    {
        ergebnis = ergebnis * basis;
    }
    return 1/ergebnis;
}

int main(void){
    double e = hoch(10, -7); // annaeherungswert
    double eingabe;
    scanf("%lf", &eingabe);
    printf("%lf", heron(e, eingabe, 1));
    
    return 0;
}
