#include <stdio.h>
#include <string.h>

unsigned int and(unsigned int a, unsigned int b){
    return a & b;
}

unsigned int or(unsigned int a, unsigned int b){
    return a | b;
}

unsigned int xor(unsigned int a, unsigned int b){
    return a ^ b;
}

unsigned int lshift(unsigned int a, unsigned int b){
    return a << b;
}

unsigned int rshift(unsigned int a, unsigned int b){
    return a >> b;
}

unsigned int length(char * z){
    int i = 0;
    while(z[i] != 0){
        i++;
    }
    return i;
}

int hoch(int basis,  int potenz){
    int ergebnis = 1;
    while(potenz > 1){
        ergebnis *= basis;
        potenz--;
    }
    return ergebnis;
}

unsigned int charToInt(char * zahl, unsigned int length){
    if(*zahl != 0){
        return ((*zahl-48)*hoch(10,length)) + charToInt(zahl+1, length-1);
    }
    return 0;
}

int main(int argc, char * argv[]){
    unsigned int a = charToInt(argv[1], length(argv[1]));
    unsigned int b = charToInt(argv[3], length(argv[3]));
    
    char *operand = argv[2];
    
    if(strcmp(operand, "and") == 0){
        printf("%d", and(a, b));
    }
    else if(strcmp(operand, "or") == 0){
        printf("%d", or(a, b));
    }
    else if(strcmp(operand, "xor") == 0){
        printf("%d", xor(a, b));
    }
    else if(strcmp(operand, "lshift") == 0){
        printf("%d", lshift(a, b));
    }
    else if(strcmp(operand, "rshift") == 0){
        printf("%d", rshift(a, b));
    }
    
    return 0;
}
