#include <stdio.h>
// Array Reihenfolge ist wichtig fuer folgende Funktionen
static char roemisch[13][3] = { {'I'},{'I','V'},{'V'},{'I','X'},{'X'},{'X','L'},{'L'},{'X','C'},{'C'},{'C','D'},{'D'},{'C','M'},{'M'} };
static int roemisch_value[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

void dezimal_in_roemisch(int zahl)
{
    for(int i = 13; i >= 0; i--){
        if(zahl >= roemisch_value[i]){
            printf("%s", roemisch[i]);
            zahl -= roemisch_value[i];
            if(zahl > 0){
				i = 13;
			}
        }
    }
}

int roemisch_index(char eingabe){
    for(int x = 0; x < 13; x++){
        // Suche einstellige Zeichen in roemisch
        if(eingabe == roemisch[x][0] && roemisch[x][1] == 0){
            return x;
        }
    }
    return -1;
}

// Ist das naechste Zeichen der Eingabe groeßer als das aktuelle?
int naechstes_groesser(char eingabe[], int eingabeIndex, int werteIndex){
    if(eingabe[eingabeIndex+1] != 0 && roemisch_value[werteIndex] != 0){
        char buchstabe = eingabe[eingabeIndex+1];
        for(; werteIndex++ < 13; werteIndex++){
            if(buchstabe == roemisch[werteIndex][1]){
                return 1;
            }
        }
    }
    return 0;
}


void roemisch_in_dezimal(char eingabe[]){
    int i = 0;
    int ergebnis = 0;
    while(eingabe[i] != 0){
        // Aktuelle roemische Index-Stelle
        int roemischIndex = roemisch_index(eingabe[i]);
        
        if(naechstes_groesser(eingabe, i, roemischIndex)){
            ergebnis -= roemisch_value[roemischIndex];
        }else{
            ergebnis += roemisch_value[roemischIndex];
        }
        
        i++;
    }
    printf("%d", ergebnis);
}

int main(){
    printf("1 - Roemisch in Dezimal \n");
    printf("2 - Dezimal in Roemisch \n");
    int auswahl = 0;
    scanf("%d", &auswahl);
    
    if(auswahl == 1){
        printf("Roemische Zahl eingeben: ");
        char number[10];
        scanf("%s", number);
        roemisch_in_dezimal(number);
    }else if(auswahl == 2){
        printf("Dezimalzahl eingeben: ");
        int number = 0;
        scanf("%d", &number);
        dezimal_in_roemisch(number);
    }
    
    return 0;
}
