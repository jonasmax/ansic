#include <stdio.h>
#include <stdlib.h>

void rot13(char letter){
    
    if(letter >= 'A' && letter <= 'Z'){
        if(letter > 'M'){
            printf("%c", 'A' + (13 - ('Z' - letter)));
        }
        else{
            printf("%c", letter + 13);
        }
    }else if(letter >= 'a' && letter <= 'z'){
        if(letter > 'm'){
            printf("%c", 'a' + (13 - ('z' - letter)));
        }
        else{
            printf("%c", letter + 13);
        }
    }else{
        putchar(letter);
    }
}

int main(int argc, char **argv){
    FILE *input;
    int letter;
    
    if(argv[1]){
        input = fopen(argv[1], "r");
        while((letter = getc(input)) != EOF){
            rot13(letter);
        }
    }else{
        while((letter = getchar()) != EOF){
            rot13(letter);
        }
    }
    return 0;
}
