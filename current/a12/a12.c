#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char findIndex(char **table, char letter){
    int row = 0;
    int col = 0;
    while(row <= 5){
        while(table[row][col] != '\0'){
            if(table[row][col] == toupper(letter)){
                return row + 49;
            }
            col++;
        }
        col = 0;
        row++;
    }
    return 0 + 48;
}

char *soundex(const char s[], char res[]){
    char *table[] = {"BFPV\0", "CGJKQSXZ\0", "DT\0", "L\0", "MN\0", "R\0"};
    int resI = 1;
    char tableI;

    res[0] = toupper(s++[0]);
    while(*s != 0){
        tableI = findIndex(table, *s);
        if(tableI != '0' && res[resI-1] != tableI){
            res[resI++] = tableI;
        }
        s++;
    }
    while(resI <= 5){
        res[resI] = '0';
        resI++;
    }
    res[++resI] = '\0';
    return res;
}


int main(int argc, char **argv){
    char *s = calloc(100, sizeof(char));
    char *res = calloc(7, sizeof(char));
    scanf("%s", s);

    printf("\n%s", soundex(s, res));

    free(s);
    free(res);
    return 0;
}