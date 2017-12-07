#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

nodep insertAt(nodep lst, int pos, void *data){
	nodep middle = calloc(1, sizeof(list));
	if(middle == NULL){
		printf("Speichermangel!");
	}
	
	if(lst == NULL){
		middle->data = data;
		middle->next = NULL;
		middle->previous = NULL;
		return middle;
	}
	
	nodep right = lst;
	int i = 0;
	while(right->next != NULL && i < pos) {
		right = right->next;
		i++;
	}
	
	nodep left = right->previous;
	
	if(pos == 0){
		middle->data = data;
		middle->previous = left;
		middle->next = right;
		right->previous = middle;
		return middle;
		
	}else if(pos == -1){
		
		while(right->next != NULL){
			right = right->next;
		}
		middle->data = data;
		middle->previous = right;
		middle->next = right->next;
		right->next = middle;
		return lst;
		
	}else{
		middle->data = data;
		middle->previous = left;
		middle->next = right;
		left->next = middle;
		right->previous = middle;
		return lst;
	}
}

nodep deleteAt(nodep lst, int pos) {
	nodep middle = lst;
	
	int posWalker = 0;
	while(middle->next != NULL && posWalker < pos) {
		middle = middle->next;
		posWalker++;
	}
	
	nodep left = middle->previous;
	nodep right = middle->next;
	
	if(left == NULL){
		free(middle);
		return right;
	}
	
	if(right == NULL) {
		left->next = right;
		free(middle);
		return lst;
	}
	
	left->next = right;
	right->previous = left;
	free(middle);
	
	return lst;
}

nodep copyList(nodep lst) {
	nodep ptr = calloc(1, sizeof(list));
	if(ptr == NULL){
		printf("Speichermangel");
	}
	
	nodep anfang = ptr;
	

	while(lst->next != NULL) {
		ptr->data = lst->data;
		ptr->next = lst->next;
		ptr->previous = lst->previous;
		
		lst = lst->next;
		
		ptr = calloc(1, sizeof(list));
		if(ptr == NULL){
			printf("Speichermangel");
		}
	}
	
	return anfang;
}

void deleteList(nodep lst) {
	nodep temp = NULL;
	while(lst->next != NULL) {
		temp = lst;
		lst = lst->next;
		free(lst);
	}
	free(lst);
}
