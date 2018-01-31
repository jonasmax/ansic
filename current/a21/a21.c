#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTORSIZE 26

typedef struct _ele{
    char codezeichen;
    int anzahl;
}ele;

typedef ele * elePtr;


void fuelle(char zeichen, elePtr vector[]){    
    
    int i = 0;
    
    while((i < VECTORSIZE)){
        if(zeichen == vector[i]->codezeichen){
            vector[i]->anzahl += 1;
            break;
        }
        i++;
    }
}

int vergleich(const void * p1, const void * p2){
    int anzahl1 = (*((elePtr *) p1))->anzahl;
    int anzahl2 = (*((elePtr *) p2))->anzahl;
    int codezeichen1 = ((elePtr)(*(int*)p2))->codezeichen;
    int codezeichen2 = ((elePtr)(*(int*)p2))->codezeichen;
    int ergebnis;
    
    if(anzahl1 > anzahl2){
        ergebnis = -1;
    }
    else if(anzahl1 < anzahl2){
        ergebnis = 1;
    }
    else if(codezeichen1 < codezeichen2){
        ergebnis = 1;
    }
    else{
        ergebnis = -1;
    }
    
    return ergebnis;
}

void ausgabeKlartext(char zeichen, elePtr gearA[], char gearB[]){
    int i;
    char ausgabe = ' ';
    
    for(i = 0; i < VECTORSIZE; i++){
        if(zeichen == gearA[i]->codezeichen){
            ausgabe = gearB[i];
        }
    }
    
    if((ausgabe == ' ') & zeichen){
        ausgabe = zeichen;
    }
    
    putchar(ausgabe);
}


int main(int argc, char *argv[]){
    FILE * datei;
    char temp;
    int i;
    elePtr verschDetail[VECTORSIZE] = {0};
    char rangfolge[VECTORSIZE] = {
        'e','n','i','a','s','t','r','u','h',
        'd','l','c','m', 'o','g','k','w','b',
        'z','f','v','p','j','x','y','q'};
    
    /* Vektor speicher anlegen */
    int vectorIndex;
    for(vectorIndex=0; vectorIndex < VECTORSIZE; vectorIndex++){
        verschDetail[vectorIndex] = calloc(1, sizeof(ele));
        if(verschDetail[vectorIndex] == NULL){
            printf("Speichermangel");
        }
        verschDetail[vectorIndex]->codezeichen = rangfolge[vectorIndex];
    }
    
    /*Verschluesselte Datei öffnen*/
    if(argc < 1){
        return EXIT_FAILURE;
    }else{
        datei = fopen(argv[1], "r");
        if(datei == NULL){
            return EXIT_FAILURE;
        }
    }
    
    /*Verschluesselte Datei lesen und Informationen speichern*/
    while(fscanf(datei, "%c", &temp) != EOF){
        fuelle(temp, verschDetail);
    }
    
    qsort(verschDetail, VECTORSIZE, sizeof(elePtr), vergleich);
    
    /*Verschluesselte Datei lesen und klartext ausgeben*/
    fseek(datei, 0L, SEEK_SET);
    while(fscanf(datei, "%c", &temp) != EOF){
        ausgabeKlartext(temp, verschDetail, rangfolge);
    }
    
    
    /* Speicher freigeben */
    for(i = 0; i < VECTORSIZE; i++){
        free(verschDetail[i]);
    }
    fclose(datei);
    
    return 0;
}
