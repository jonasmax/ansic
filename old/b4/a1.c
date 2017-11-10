#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring.h"

int main(){
    nameRing * anfang = calloc(1, sizeof(nameRing));
    if(anfang == NULL){
        printf("Kein Speicherplatz");
        return 0;
    }
    strcpy(anfang->name, "Erster");
    anfang->next = anfang;
    
    add(anfang, "Tim");
    add(anfang, "Hans");
    add(anfang, "Alfred");
    
    while(){
        delete_nth(anfang, 2);
    }
    
    show_ring(anfang);
    
    
    
    
    return 0;
}
