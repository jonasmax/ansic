#include <stdio.h>
#include <stdlib.h>

union ueberlagerung {
    int a[2];
    double zahl;
};

void writeIntBin(int zahl){
    int index = 31;
    int bitmask;
    
    while(index >= 0){
        bitmask = 1 << (index);

        if((zahl & bitmask) > 0){
            putchar('1');
        }else{
            putchar('0');
        }
        
        index--;
    }
}


int main(void) {

    union ueberlagerung test;
    
    sscanf("3.14", "%lf", &test.zahl);
    
    /* Int binaer ausgeben */
    writeIntBin(test.a[0]);
    writeIntBin(test.a[1]);
    
    putchar('\n');
    
    return 0;
}
