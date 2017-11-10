#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

lz add_first(lz anfang, void *newData){
    lz newZeiger = malloc(sizeof(list));
    if(newZeiger == NULL){
        printf("Kein freier Speicherplatz");
        return 0;
    }

    if(anfang == NULL){
        anfang = newZeiger;
        anfang->data = newData;
        anfang->next = NULL;
        anfang->previous = NULL;
        return anfang;
    }else{
        anfang->previous = newZeiger;
        newZeiger->next = anfang;
        newZeiger->data = newData;
        return newZeiger;
    }
}

lz add_ith(lz anfang, int i, void *newData){
    if(anfang == NULL || i == 1){
        anfang = add_first(anfang, newData);
        return anfang;
    }
    
    lz walker = anfang;
    while(walker->next != NULL && i > 1){
        walker = walker->next;
        i--;
    }
    
    if(i > 1){
        printf("Stelle nicht in Liste");
        return 0;
    }else{
        lz newP = malloc(sizeof(list));
        if(newP == NULL){
            printf("Kein freier Speicherplatz");
            return 0;
        }
        newP->next = walker;
        newP->previous = walker->previous;
        walker->previous->next = newP;
        walker->previous = newP;
        newP->data = newData;
    }
    return anfang;
}

lz add_last(lz anfang, void *newData){
    lz new = malloc(sizeof(list));
    if(new == NULL){
        printf("Kein freier Speicherplatz");
        return 0;
    }
    
    lz walker = anfang;
    while(walker->next != NULL){
        walker = walker->next;
    }
    
    walker->next = new;
    new->next = NULL;
    new->previous = walker;
    new->data = newData;
    return anfang;
}

lz del_first(lz anfang){
    lz temp = anfang;
    anfang = anfang->next;
    free(temp);
    return anfang;
}

lz del_ith(lz anfang, int i){
    if(anfang == NULL || i == 1){
        anfang = del_first(anfang);
        return anfang;
    }
    
    lz walker = anfang;
    while(walker->next != NULL && i > 1){
        walker = walker->next;
        i--;
    }
    
    if(i > 1){
        printf("Stelle nicht in Liste");
        return 0;
    }else{
        if(walker->next == NULL){
            anfang = del_last(anfang);
        }else{
            walker->previous->next =  walker->next;
            walker->next->previous = walker->previous;
            free(walker);
        }
    }
    return anfang;
}

lz del_last(lz anfang){
    lz walker = anfang;
    while(walker->next != NULL){
        walker = walker->next; 
    }
    walker->previous->next = NULL;
    free(walker);
    return anfang;
}

void del_all(lz anfang){
    lz temp = NULL;
    while(anfang->next != NULL){
        temp = anfang;
        anfang  = anfang->next;
        free(temp);
    }
    free(anfang);
}

void del_all_costum(lz anfang, void (*costum)(void *)){
    lz temp = NULL;
    while(anfang->next != NULL){
        temp = anfang;
        costum(temp->data);
        anfang  = anfang->next;
        free(temp);
    }
    costum(anfang->data);
    free(anfang);
}
