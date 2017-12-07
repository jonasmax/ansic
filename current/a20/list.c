#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

lp lst = NULL;

lp initial(lp anfang, lp newP, char word[], char replace[]){
	anfang = newP;
	anfang->next = NULL;
	strcpy(anfang->word, word);
	strcpy(newP->replaceWord, replace);
	return anfang;
}

lp resStorage(){
	lp newP = calloc(1, sizeof(list));
    assert(newP != NULL);
	return newP;
}

lp add_pair(lp anfang, char word[], char replace[]){
	lp newP = resStorage();
	
	
	if(anfang == NULL){
		return initial(anfang, newP, word, replace);
	}

	lp walker = anfang;
	while(walker->next != NULL){
		walker = walker->next;
	}
	
	walker->next = newP;
	newP->next = NULL;
	strcpy(newP->word, word);
    strcpy(newP->replaceWord, replace);
	
	
	return anfang;
}

void clearList(void){
    lp temp = NULL;
    while(lst != NULL){
        temp = lst;
        lst = lst->next;
        free(temp);
    }
    lst = NULL;
}
