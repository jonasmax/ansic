#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRUCTS 10
#define MAX_SPLITS 20
#define MAX_SPLIT_LENGTH 10

struct data{
    int anzahl;
    char *str[MAX_SPLIT_LENGTH];
};

struct data *split(char *str, char *delim){
    struct data *neu;

    neu = calloc(1, sizeof(struct data));
    if(neu == NULL){
        printf("Kein freier Platz");
        return 0;
    }
    
    char *temp;
    
    temp = strtok(str, delim);
    if(temp != 0){
        (*neu).str[0] = calloc(10,sizeof(char));
        strcpy((*neu).str[0], temp);
        (*neu).anzahl++;
    }

    int i = 1;
    while(temp != NULL){
        temp = strtok(NULL, delim);
        if(temp != NULL){
            (*neu).str[i] = calloc(10,sizeof(char));
            strcpy((*neu).str[i], temp);
            (*neu).anzahl++;
        }
        i++;
    }
    return neu;
}

void clear(struct data * n){
    int x = 0;
    while((*n).str[x] != 0){
        free((*n).str[x]);
        (*n).str[x] = NULL;
        x++;
    }
}

void ausgabe(struct data *splits){
    printf("Anzahl: %d | ", (*splits).anzahl);
    int x = 0;
    while((*splits).str[x] != 0){
        printf("String %d: %s | ", x+1, (*splits).str[x]);
        x++;
    }
    printf("\n");
}

int main(int argc, char * argv[]){
    struct data *splits[MAX_STRUCTS];

    for(int i = 2; i < argc; i++){
        splits[i-2] = calloc(1, sizeof(struct data));
        if(splits[i-2] == NULL){
            return 0;
        }
        splits[i-2] = split(argv[i] ,argv[1]);
    }
    
    for(int i = 0; i < argc-2; i++){
        ausgabe(splits[i]);
        clear(splits[i]);
        free(splits[i]);
        splits[i] = NULL;
    }
    return 0;
}
