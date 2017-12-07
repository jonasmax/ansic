#ifndef LIST_H
	#define LIST_H
	#define MAX_WORD_LENGTH 25
	
	typedef struct _list{
		char word[MAX_WORD_LENGTH];
        char replaceWord[MAX_WORD_LENGTH];
		struct _list * next;
	}list;
	
	typedef list * lp;
	
	lp initial(lp anfang, lp newP, char word[], char replace[]);
	lp resStorage();
    lp add_pair(lp anfang, char word[], char replace[]);
    void clearList(void);
	
#endif
