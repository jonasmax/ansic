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


void saveForbiddenWords(lp knowledge, FILE *fp){
	if(!knowledge){
		fputs("\n", fp);
	} else {
		fprintf(fp, "%s=%s\n", knowledge->word, knowledge->replaceWord);
		saveForbiddenWords(knowledge->next, fp);
	}
}


int save(lp knowledge, char *filename){
	FILE *fp;
	int erfolg;
	
	fp = fopen(filename, "w");
	if(!fp){
		perror("Fehler beim Oeffnen der Tierbank");
		return 0;
	}
	
	saveForbiddenWords(knowledge, fp);
	erfolg = !ferror(fp);
	fclose(fp);
	return erfolg;
}

lp loadForbiddenWords(FILE *fp, lp knowledge){
	char keyPair[(MAX_WORD_LENGTH *2) + 1] = {0};
	char keyPairFiltered[(MAX_WORD_LENGTH *2)] = {0};
	fgets(keyPair, (MAX_WORD_LENGTH *2) + 1, fp);
	sscanf(keyPair, "%[^\n]", keyPairFiltered);
	
	if(keyPair[0] != '\n'){
		knowledge = splitKeyPair(keyPairFiltered, knowledge);
		loadForbiddenWords(fp, knowledge);
	}

	return knowledge;
}

lp load(char *filename){
	FILE * fp;
	lp knowledge = NULL;
	fp = fopen(filename, "r");
	if(!fp){
		perror("Fehler beim oeffnen");
		return NULL;
	}
	knowledge = loadForbiddenWords(fp, knowledge);
	fclose(fp);
	return knowledge;
}


int main(int argc, char *argv[]){
	// LISTE: VERBOTENE WOERTER
	lp keyPair = NULL;
	int i = 1;
	while(argv[i] != 0){
		keyPair = splitKeyPair(argv[i], keyPair);		
		i++;
	}
	
	if(keyPair == NULL){
		keyPair = load("forbidden.dat");
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
	
	
	// SPEICHERN VON VERBOTENEN WOERTERN
    save(keyPair, "forbidden.dat");
    
    
    freeList(keyPair);
    freeList(sentence);

	
	return 0;
}
