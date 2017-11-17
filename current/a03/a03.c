#include <stdio.h>

void raus(count, rom){
    while(count){
        printf("%c", rom);
        count--;
    }
}

int dezInRom(int dez){
    int rest = 0;
    int count = 0;
    
    if(dez >= 100){
        rest = dez % 100;
        count = dez / 100;
        raus(count, 'C');
    }
    else if(dez >= 50){
        rest = dez % 50;
        count = dez / 50;
        raus(count, 'L');
    }
    else if(dez >= 10){
        rest = dez % 10;
        count = dez / 10;
        raus(count, 'X');
    }
    else if(dez >= 5){
        rest = dez % 5;
        count = dez / 5;
        raus(count, 'V');
    }
    else if(dez >= 1){
        rest = dez % 1;
        count = dez / 1;
        raus(count, 'I');
    }
    else if(dez == 0){
        printf("\n");
        return 0;
    }
    return dezInRom(rest);
}

int main(int argc, char **argv){
    int dez = 0;
    scanf("%d", &dez);
    dezInRom(dez);
    return 0;
}
