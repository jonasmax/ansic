#include <stdio.h>

double heron(double e, double x, double a)
{
    double previous = a;
    a = (a + (x/a)) / 2;
    
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

int main(int argc, char *argv[static 1]){
    double e = hoch(10, -7); // annaeherungswert
    double eingabe;
    if (argc > 1) 
    {
        sscanf(argv[1], "%lf", &eingabe);
    }else {
        scanf("%lf", &eingabe);
    }
    
    printf("%lf", heron(e, eingabe, 1));
    
    return 0;
}
