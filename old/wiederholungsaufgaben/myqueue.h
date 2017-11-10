#ifndef MYQUEUE_H
    #define MYQUEUE_H

    typedef struct queue{
        struct queue * next;
        int value;
    }queue;

    extern queue *enter(queue*, int value);
    extern int is_empty(queue *);
    extern int front(queue *);
    extern queue * leave(queue *);
#endif
