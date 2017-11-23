#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

lp initial(lp anfang, lp newP, char word[]){
	anfang = newP;
	anfang->next = NULL;
	strcpy(anfang->word, word);
	return anfang;
}

lp resStorage(){
	lp newP = calloc(1, sizeof(list));
	if(newP == NULL){
		assert(newP != NULL);
	}
	return newP;
}

lp add_last(lp anfang, char word[]){
	lp newP = resStorage();
	
	
	if(anfang == NULL){
		return initial(anfang, newP, word);
	}

	lp walker = anfang;
	while(walker->next != NULL){
		walker = walker->next;
	}
	
	walker->next = newP;
	newP->next = NULL;
	strcpy(newP->word, word);
	
	free(newP);
	free(walker);
	
	
	return anfang;
}
