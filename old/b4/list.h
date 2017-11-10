#ifndef LIST_H
    #define LIST_H

    typedef struct _list{
        void *data;
        struct _list *next;
        struct _list *previous;
    }list;

    typedef list * lz;

    lz add_first(lz list, void *data);
    lz add_ith(lz list, int i, void *data);
    lz add_last(lz list, void *data);
    
    lz del_first(lz list);
    lz del_ith(lz list, int i);
    lz del_last(lz list);
    void del_all(lz anfang);
    void del_all_costum(lz anfang, void (*costum)(void *));
#endif
