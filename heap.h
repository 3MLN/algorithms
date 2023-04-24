#ifndef AL_HEAP_H
#include "memory_trick.h"
#include <stdlib.h>
#define AL_HEAP_H
//Override this macro to set a custom type for the heap
#define ITEM void*
// Get LEFT child from a given index root
#define LEFT(i) ((2*i)+1)
// Get RIGHT child from a given index root
#define RIGHT(i) ((2*i)+2)
// Get PARENT from a given index child
#define PARENT(i) ((i-1)/2)
// Get priority of a given ITEM
#define PRIORITY()
// Wrap ITEM object with a priority field
typedef struct wrap_s{
    ITEM item;
    int p; //priority of item
} W_ITEM;
typedef struct heap_s{
    W_ITEM* V;
    int size;
} *Heap;
//Initialize the heap structure with a given maxSize for the array
Heap heap_init(int maxSize);
//Add to the end of the heap a new given Item
void heap_append(Heap h,ITEM Item,int pr);
//Display all the items contained in the heap, needs a user-declared 
//function to print correctly the data of the items.
//Returns 1 in case of error, 0 if terminated fine.
int heap_display(Heap h, void (*print_item)(ITEM));
//Heapify function given a index to start on array
void heapify(Heap h,int index);
//Apply heapify on every leaf of the heap starting from the last one
void heap_build(Heap h);
//Ascending sort of the heap
void heap_sort(Heap h);
// heap_delete()
// heap_peek()
void heap_free(Heap h,void (*free_item)(ITEM));
#endif