#ifndef LIST_H
	#define LIST_H
	
	typedef struct _list{
		void * data;
		struct _list * next;
		struct _list * previous;
	}list;
	
	typedef list * nodep;
	
	
	nodep insertAt(nodep lst, int pos, void *data);
	nodep deleteAt(nodep lst, int pos);
	nodep copyList(nodep lst);
	void deleteList(nodep lst);
	
#endif
