#ifndef Memory_H
#define Memory_H

#include <stdlib.h>




/* Macros for internal memory allocator allocations */
#define _LibMemAlloc(size) malloc(size);


#define _LibMemFree(ptr) free(ptr);


#define _LibMemRealloc(ptr, size) realloc(ptr, size);




/* Macros for external api allocations */
#define M_alloc(size) malloc(size);


#define M_free(ptr) free(ptr);


#define M_realloc(ptr, size) realloc(ptr, size);




#endif
