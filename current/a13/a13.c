#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ring{
	char name[80];
	struct ring *next;
}ring;


struct ring * insert(struct ring *ri, char name[]){
	struct ring * newRi = NULL;
	
	if(ri == NULL){
		if((ri = malloc(sizeof(ring))) == NULL){
			printf("Nicht genug Speicher!");
		}
		strcpy(ri->name, name);
		ri->next = ri;
		return ri;
	}
	else{
		while(ri->next != ri){
			ri = ri->next;
		}
		
		if((newRi = malloc(sizeof(ring))) == NULL){
			printf("Nicht genug Speicher!");
		}
		newRi->next = ri->next;
		ri->next = newRi;
		
		strcpy(newRi->name, name);
		return newRi->next;
	}
}

void ausgabe(struct ring *ri){
	while(ri->next != ri){
		printf("%s", ri->name);
	}
	
	printf("%s", ri->name);
}

int main(){
	struct ring * ri = NULL;
	ri = insert(ri, "Hans");
	ri = insert(ri, "Peter");
	ri = insert(ri, "Gans");
	
	ausgabe(ri);
	
	return 0;
}
