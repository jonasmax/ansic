#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char * sterne(char word[]){
	int i = 0;
	while(word[i] != 0){
		if(i > 1){
			word[i] = '*';
		}
		i++;
	}
	return word;
}

int is_illegal(char word[], lp illegalWords){
	while(illegalWords != NULL){
		if(strcmp(word, illegalWords->word) == 0){
			return 1;
		}
		illegalWords = illegalWords->next;
	}
	
	return 0;
}

void freeList(lp lst){
    lp temp = NULL;
    while(lst != NULL){
        temp = lst;
        lst = lst->next;
        free(temp);
    }
}

int main(int argc, char *argv[]){
	// LISTE: VERBOTENE WOERTER
	lp illegalWords = NULL;
	int i = 1;
	while(argv[i] != 0){
		illegalWords = add_word(illegalWords, argv[i]);
		i++;
	}
	
	// LISTE: ZU PRUEFENDER SATZ
	lp sentence = NULL;
	char word[MAX_WORD_LENGTH] = {0};
	while(scanf("%s", word) != EOF){
		sentence = add_word(sentence, word);
	}
	
	
	// PRUEFE
    lp walker = sentence;
	while(walker != NULL){
		if(is_illegal(walker->word, illegalWords)){
			printf("%s ", sterne(walker->word));
		}else{
			printf("%s ", walker->word);
		}
		
		walker = walker->next;
	}
	printf("\n");
	
    
    
    freeList(illegalWords);
    freeList(sentence);

	
	return 0;
}
