#ifndef Memory_H
#define Memory_H

#include <stdlib.h>




#define _LibMemAlloc(size) malloc(size);


#define _LibMemFree(ptr) free(ptr);


#define _LibMemRealloc(ptr, size) realloc(ptr, size);




typedef struct{

	void* data;

	size_t capacity;

}_Mem_Chunk;



#endif
