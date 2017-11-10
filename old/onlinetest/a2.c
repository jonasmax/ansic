#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zeichenloeschen(char * zeichenkette, char * trennzeichen){
    char * trennung;
    trennung = strtok(zeichenkette, trennzeichen);
    
    while(trennung != NULL){
        printf("%s", trennung);
        trennung = strtok(NULL, trennzeichen);
    }
    printf("\n");
}

void str_del_lowervowels(char * zeichenkette){
    zeichenloeschen(zeichenkette, "aeiou");
}

void str_del_uppervowels(char * zeichenkette){
    zeichenloeschen(zeichenkette, "AEIOU");
}

void str_del_vowels(char * zeichenkette){
    zeichenloeschen(zeichenkette, "AEIOUaeiou");
}




int main(int argc, char * argv[]){
    char text[] = "bababa";
    char text2[] = "AeIxoU";
    char text3[] = "AeIxoU";

    str_del_lowervowels(text);
    str_del_vowels(text2);
    str_del_uppervowels(text3);
    return 0;
}
