#include <stdio.h>
#include <stdlib.h>

void fuelleQuadrat(int **quadrat, int laenge){
    int indexX = (laenge / 2);
    int indexY = (laenge / 2);
    int counter = 1;
    
    quadrat[indexY][indexX] = counter++;
    
    while(counter != ((laenge * laenge)+1)){
        
        indexY = (indexY +1) % (laenge);
        indexX = (indexX + (laenge-1)) % (laenge);
        
        if(quadrat[indexY][indexX] == 0){
            quadrat[indexY][indexX] = counter;
        }
        else{
            indexY = (indexY+1) % (laenge);
            indexX = (indexX+1) % (laenge);
            quadrat[indexY][indexX] = counter;
        }
        
        counter++;
    }
}

void ausgabe(int **quadrat, int laenge){
    int index = 0;
    printf("\n");
    while(index < laenge){
        int index2 = 0;
        while(index2 < laenge){
            if(quadrat[index][index2] < 10){
                printf("0%d | ", quadrat[index][index2]);
            }else{
                printf("%d | ", quadrat[index][index2]);
            }
            
            index2++;
        }
        printf("\n");
        index++;
    }
}

int main(void){
    int **quadrat;
    int eingabe = 0;
    int spalte;
    
    printf("Ungerade zahl nicht groesser 9 eingeben: ");
    scanf("%d", &eingabe);
    
    /* Speicher fuer Zeile */
    if((quadrat = calloc(eingabe, sizeof(int))) == 0){
        printf("Speicherplatz nicht ausreichend!");
    }
    
    /* Speicher fuer Spalte der i-ten Zeile */
    spalte = eingabe-1;
    while(spalte >= 0){
        if((quadrat[spalte] = calloc(eingabe, sizeof(int))) == 0){
            printf("Speicherplatz nicht ausreichend!");
        }
        spalte--;
    }

    fuelleQuadrat(quadrat, eingabe);
    ausgabe(quadrat, eingabe);
    
    return 0;
}
