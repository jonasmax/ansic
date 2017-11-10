#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *translate(char *text, char *textLanguage, char *otherLanguage){
    int index = 0;
    char *anfang = text;
    while(*text != 0){
        while(textLanguage[index] != *text){
            index++;
        }
        *text = otherLanguage[index];
        index = 0;
        text++;
    }
    return anfang;
}

int main(int count, char *argv[]){
    // Variablen deklarieren und speicher organisieren
    char *language1 = calloc(27, sizeof(char));
    char *language2 = calloc(27, sizeof(char));
    char *text = calloc(100, sizeof(char));

    // Variablen initialisieren WARUM GEHT DAS NICHT MIT FREE()?
    //language1 = "abcdefghijklmnopqrstuvf";
    //language2 = "irjmnzltacogdeksvbphxqyuw";
    char *language1Alp = "abcdefghijklmnopqrstuvf";
    char *language2Alp = "irjmnzltacogdeksvbphxqyuw";
    int i = 0;
    while(i <= 27){
        language1[i] = language1Alp[i];
        language2[i] = language2Alp[i];
        i++;
    }

    /* 
    GIBT ES EINE COOLE VARIANTE UM EOF der Eingabe hinzuzufügen?
    Wenn ja dann in translate anstatt 0 -> EOF 
    */
    scanf("%s", text);

    // Optionen
    if(strcmp(argv[1], "encrypt") == 0){
        printf("%s", translate(text, language1, language2));
    }else if(strcmp(argv[1], "decrypt") == 0){
        printf("%s", translate(text, language2, language1));
    }

    free(text);
    free(language1);
    free(language2);

    return 0;
}