#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring.h"

void show_ring(nameRing *ring){
    nameRing *temp = ring;
    
    if(temp != NULL){
        printf("%s  ", temp->name);
        temp = temp->next;
    }
    
    while(temp->name != ring->name && ring->name != NULL){
        printf("%s  ", temp->name);
        temp = temp->next;
    }
}

void add(nameRing *ring, const char *name){
    nameRing * newElem = calloc(1, sizeof(nameRing));
    if(newElem == NULL){
        printf("Kein Speicherplatz");
        return;
    }
    strcpy(newElem->name, name);
    
    nameRing *temp = ring;
    while(temp->next != ring){
        temp = temp->next;
    }
    
    temp->next = newElem;
    newElem->next = ring;
    
    return;
}

void delete_nth(nameRing *ring, int nth){
    for(int i = 1; i < nth-1; i++){
        ring = ring->next;
    }
    nameRing * zuLoeschen = ring->next;
    ring->next = ring->next->next;
    
    free(zuLoeschen);
    zuLoeschen = NULL;
}
