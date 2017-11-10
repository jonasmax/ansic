#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

int is_empty(queue *q){
    return q == NULL;
}

queue *enter(queue* q, int value){
    queue * nZeiger = malloc(sizeof(queue));
    nZeiger->value = value;
    nZeiger->next = NULL;
    
    if(nZeiger == NULL){
        printf("Kein freier Speicherplatz");
        return 0;
    }
    
    if(is_empty(q)){
        return nZeiger;
    }
    
    queue * laeufer = q;
    while(laeufer->next != NULL){
        laeufer = laeufer->next;
    }
    
    laeufer->next = nZeiger;
    return q;
}

int front(queue * q){
    if(is_empty(q)){
        printf("Liste ist leer");
        return -1;
    }
    return q->value;
}

queue * leave(queue * q){
    if (is_empty(q)){
        printf("Liste ist leer");
        return NULL;
    }
    queue * temp = q->next;
    free(q);
    return temp;
}

void alleWeg(queue * q){
    while(q != NULL){
        queue * temp = q;
        q = q->next;
        free(temp);
    }
}

int main(int argc, char * argv[]){
    queue * q = NULL;
    q = enter(q, 1);
    q = enter(q, 2);
    q = enter(q, 3);
    q = enter(q, 4);
    
    q = leave(q);
    
    queue * temp = q;
    while(temp != NULL){
        printf("%d \n", temp->value);
        temp = temp->next;
    }
    
    printf("\n");

    q = leave(q);
    q = leave(q);
    

    temp = q;
    while(temp != NULL){
        printf("%d \n", temp->value);
        temp = temp->next;
    }
    

    q = leave(q);
    
    return 0;
}
