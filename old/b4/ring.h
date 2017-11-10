#ifndef RING_H
#define RING_H

enum { SMAXLEN=80 };

typedef struct _ring {
    struct _ring *next;
    char name[SMAXLEN];
}nameRing;

void show_ring(nameRing *ring);
void add(nameRing *ring, const char *name);
void delete_nth(nameRing *ring, int n);
void delete_ring(nameRing *ring);
#endif
