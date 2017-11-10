#include <stdio.h>

int wieviele_selben(char *zeichenkette){
    char zeichen = zeichenkette[0];
    int i = 1;
    while(zeichenkette[i] == zeichen){
        i++;
    }
    return i-1;
}

int feldlaenge_kompriemiert(char *zeichenkette){
    int laenge = 0;
    int x = 0;
    
    while(zeichenkette[x] != 0){
        if(zeichenkette[x+1] == zeichenkette[x]){
            x = x + wieviele_selben(&zeichenkette[x]);
            laenge++;
        }
        x++;
        laenge++;
    }
    return laenge +1;
}


char * kompriemiert(char *zeichenkette){
    int laenge = feldlaenge_kompriemiert(zeichenkette);
    char *neu = malloc(laenge*sizeof(char));
    if(neu == 0){
        printf("Kein freier Speicher");
        return 0;
    }
    
    int haeufigkeit = 0;
    int x = 0;
    int n = 0;
    
    while(zeichenkette[x] != 0){
        neu[n] = zeichenkette[x];
        if(zeichenkette[x+1] == zeichenkette[x]){
            haeufigkeit = wieviele_selben(&zeichenkette[x]);
            n++;
            neu[n] = haeufigkeit;
            n++;
            x = (haeufigkeit+1) + x;
        }else{
            x++;
            n++;
        }
    }
    neu[laenge-1] = 0;
    return neu;
}



int main(int argc, char *argv[]){
    char *neu = kompriemiert(argv[1]);
    printf("%s", neu);
    free(neu);
    neu = NULL;
    //printf("%d", feldlaenge_kompriemiert(argv[1]));
    //printf("%s \n", komprimier(argv[1]));
    return 0;
}
