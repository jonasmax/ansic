#include <stdio.h>

// Eingabe: Basis und Exponent
// Ausgabe: Hochzahl
int hoch(int basis, int e)
{
    if(e != 0){
        int ergebnis = basis;
        for(int i = 1; i < e; i++)
        {
            ergebnis = ergebnis * basis;
        }
        return ergebnis;
    }else{
        return 1;
    }
}

// Eingabe: Natuerliche Zahl
// Ausgabe: Anzahl der Stellen im Binaersystem
int binaer_stellen(int zahl)
{
    int b_stellen = 0;
    while((zahl > (hoch(2,b_stellen)*2)-1))
    {
        b_stellen++;
    }
    return ++b_stellen;
}

// Eingabe: Natuerliche Zahl
// Ausgabe: Binaerdarstellung
void binaer_ausgabe(int zahl)
{
    int b_stellen = binaer_stellen(zahl);
    for(int i = b_stellen-1; i >= 0 ; i--)
    {
        int bit = 1 << i;
        if((zahl & bit) > 0)
        {
            putchar('1');
        }
        else{
            putchar('0');
        }
    }
    putchar('\n');
}

// Eingabe: Array
// Ausgabe: Laenge des Arrays
int len(char x[])
{
    if(x)
    {
        int i = 0;
        while(x[i] != 0)
        {
            i++;
        }
        return i;
    }else{
        return 0;
    }
}

// Eingabe: Zahl in Form eines array mit char werten
// Ausgabe: Natuerliche Zahl
int dezimal_erstellen(char argv[])
{
    int ergebnis = 0;
    int z_stellen = len(argv);
    
    int i = 0;
    while(argv[i] != 0)
    {
        int zahl = argv[i] -48;
        for(int z = 1; z < z_stellen; z++)
        {
            zahl = zahl * 10;
        }
        ergebnis += zahl;
        i++;
        z_stellen--;
    }
    return ergebnis;
}
// Eingabe: Dezimalzahl
// Ausgabe: Dezimalstellen als char
void dezimal_ausgabe(int zahl)
{
    int st = 10;
    while(zahl%st != zahl)
    {
        st = st*10;
    }
    st = st/10;
    
    while(zahl >= 1){
        putchar((zahl/st) + '0');
        zahl = zahl%st;
        st = st/10;
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{   
    int zahl = dezimal_erstellen(argv[1]);
    dezimal_ausgabe(zahl);
    binaer_ausgabe(zahl);
    
    return 0;
}
