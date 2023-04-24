#ifndef MEM_TRICK_H
#define MEM_TRICK_H
//Allocate memory for a new ptr object
#define NEW(obj) malloc(sizeof(*obj))
//Dinamically allocate a new array of any given type
#define NEW_VECT(msize,obj) malloc(msize*sizeof(*obj))
#endif