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
		if(strcmp(word, illegalWords->word) == NULL){
			return 1;
		}
		illegalWords = illegalWords->next;
	}
	
	return 0;
}

int main(int argc, char *argv[]){
	// LISTE: VERBOTENE WOERTER
	lp illegalWords = NULL;
	int i = 1;
	while(argv[i] != 0){
		illegalWords = add_last(illegalWords, argv[i]);
		i++;
	}
	
	// LISTE: ZU PRUEFENDER SATZ
	lp sentence = NULL;
	char word[MAX_WORD_LENGTH] = {0};
	while(scanf("%s", word) != EOF){
		sentence = add_last(sentence, word);
	}
	
	
	// PRUEFE
	while(sentence != NULL){
		if(is_illegal(sentence->word, illegalWords)){
			printf("%s ", sterne(sentence->word));
		}else{
			printf("%s ", sentence->word);
		}
		
		sentence = sentence->next;
	}
	printf("\n");
	
	free(illegalWords);
	free(sentence);
	
	return 0;
}
