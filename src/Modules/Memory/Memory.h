#ifndef Memory_H
#define Memory_H

#include <stdlib.h>
#include <stdio.h>


/*	README
 *
 *	if you need malloc like behavior use the Heap.
 *
 *	if you need to allocate somthing on a per loop cycle
 *	basis you might want to use an arena, they are faster
 *	and more memory effiecient in some cases.
 *
*/




/*	Heap Allocator
 *
 *	A allocator similar to malloc
 *
*/

typedef struct{

	void* data;

	size_t size;

}_Mem_Blocks;


typedef struct{

	void* data;

	size_t filled;

	size_t capacity;


	/* Tracks how many memory allocations */
	size_t allocations;
	/* Holds the values of "Free" blocks */
	_Mem_Blocks* blocks;

}Heap;


Heap Heap_New(size_t size);


void Heap_Free(Heap* heap);


void Heap_Resize(Heap* heap, size_t new_size);


void* Heap_Alloc(Heap* heap, size_t amount);


void Heap_Debug(Heap* heap);




/*	Arena Allocator
 *
 *	Basicly a bump allocator
 *	that can be reset easy
*/
typedef struct{

	void* data;

	size_t filled;

	size_t capacity;

}Arena;


Arena Arena_New(size_t size);


void Arena_Free(Arena* arena);


void Arena_Resize(Arena* arena, size_t new_size);


void* Arena_Alloc(Arena* arena, size_t amount);


void Arena_Clean(Arena* arena);


#endif
