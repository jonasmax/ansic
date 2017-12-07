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
		struct ring * walker = ri;
		while(walker->next != ri){
			walker = walker->next;
		}
		
		if((newRi = malloc(sizeof(ring))) == NULL){
			printf("Nicht genug Speicher!");
		}
		
		walker->next = newRi;
		newRi->next = ri;
		
		strcpy(newRi->name, name);
		return ri;
	}
}

struct ring * abzaehlen(struct ring * ptr, int i) {
	struct ring * temp;
	int count = 1;
	while(count < (i-1)) {
		ptr = ptr->next;
		count++;
	}
	temp = ptr->next;
	ptr->next = ptr->next->next;
	
	free(temp);
	
	return ptr->next;
}

void ausgabe(struct ring *ri){
	struct ring * walker = ri;
	while(walker->next != ri){
		printf("%s", walker->name);
		walker = walker->next;
	}
	printf("%s", walker->name);
}

int main(int argc, char *argv[]){
	struct ring * ri = NULL;
	ri = insert(ri, "Robert");
	ri = insert(ri, "Michael");
	ri = insert(ri, "Susanne");
	ri = insert(ri, "Wolfgang");
	ri = insert(ri, "Florian");
	ri = insert(ri, "Jonas");
	ri = insert(ri, "Nicole");
	ri = insert(ri, "Marco");
	ri = insert(ri, "Annabelle");
	
	
	while(ri->next != ri){
		ri = abzaehlen(ri, argc-1);
	}
	
	ausgabe(ri);
	return 0;
}
