#include <stdio.h>

void binaerRechner(int zahl, char binaer[33])
{
    for(int i = 0; i < 32; i++)
    {
        int bit = 2147483648 >> i;
        if((zahl & bit) != 0)
        {
            binaer[i] = '1';
        }
        else{
            binaer[i] = '0';
        }
    }
    binaer[32] = '\0';
}

void dezimal(int zahl){
    
}

int main()
{   
    // stdin - Standardeingabe einlesen
    int zahl;
    scanf("%d", &zahl);
    
    // Dezimal in Binaer
    char binaer[32];
    binaerRechner(zahl, binaer);
    printf("%s\n", binaer);
    
    return 0;
}
