#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char * decrypt(char word[], lp keyPair){
	while(keyPair != NULL){
		if(strcmp(word, keyPair->word) == 0){
			return keyPair->replaceWord;
		}
		keyPair = keyPair->next;
	}
	
	return word;
}

void freeList(lp lst){
    lp temp = NULL;
    while(lst != NULL){
        temp = lst;
        lst = lst->next;
        free(temp);
    }
}

lp splitKeyPair(char words[], lp ptr) {
	char delimiter[] = "=";
	char *delimiterPtr;

	delimiterPtr = strtok(words, delimiter);
	char *a = delimiterPtr;
	
	delimiterPtr = strtok(NULL, delimiter);
	char *b = delimiterPtr;
	
	return add_pair(ptr, a, b);
}


int main(int argc, char *argv[]){
	// LISTE: VERBOTENE WOERTER
	lp keyPair = NULL;
	int i = 1;
	while(argv[i] != 0){
		keyPair = splitKeyPair(argv[i], keyPair);		
		i++;
	}

	
	// LISTE: ZU PRUEFENDER SATZ
	lp sentence = NULL;
	char word[MAX_WORD_LENGTH] = {0};
	while(scanf("%s", word) != EOF){
		sentence = add_pair(sentence, word, "");
	}
	
	
	// PRUEFE
    lp walker = sentence;
	while(walker != NULL){
		printf("%s ", decrypt(walker->word, keyPair));
		walker = walker->next;
	}
	printf("\n");
	
    
    
    freeList(keyPair);
    freeList(sentence);

	
	return 0;
}
