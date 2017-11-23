#ifndef LIST_H
	#define LIST_H
	#define MAX_WORD_LENGTH 80
	
	typedef struct _list{
		char word[MAX_WORD_LENGTH];
		struct _list * next;
	}list;
	
	typedef list * lp;
	
	lp initial(lp anfang, lp newP, char word[]);
	lp resStorage();
	lp add_last(lp li, char word[]);
	
#endif
