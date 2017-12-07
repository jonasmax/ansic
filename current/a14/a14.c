#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void printList(nodep lst){
	while(lst != NULL){
		printf("%s", lst->data);
		lst = lst->next;
	}
}

int main(void){
	nodep test = NULL;
	
	char * name1 = "A";
	char * name2 = "B";
	char * name3 = "C";
	char * name4 = "D";
	
	test = insertAt(test, 0, name1);
	test = insertAt(test, 0, name2);
	test = insertAt(test, 1, name3);
	test = insertAt(test, 2, name4);
	
	//test = deleteAt(test, 3);
	
	
	nodep copy = copyList(test);
	printList(copy);
	
	deleteList(test);
	deleteList(copy);
	
	return 0;
}
