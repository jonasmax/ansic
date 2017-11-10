#include <stdio.h>

#include "list.h"


void costum(void * data){
    char * ausgabe = data;
    printf("%s\n", ausgabe);
} 

int main(int argc, char * argv[]){
    lz meineListe = NULL;
    
    char wort[] = "erstes";
    char wort3[] = "drittes";
    char *wort5 = "letztes";
    
    meineListe = add_first(meineListe, wort);

    meineListe = add_ith(meineListe, 1, wort3);

    meineListe = add_last(meineListe, wort5);
    
    meineListe = add_ith(meineListe, 1, wort);

    
    del_all_costum(meineListe, costum);
    meineListe = NULL;
    
    return 0;
}


