#ifndef Heap_H

#define Heap_H

#include "Memory.h"




typedef struct{

	void* data;


	/*	Heap.chunks is used to store information
	 *	about memory allocations
	 *
	 *	with every allocation a chunk is added to it
	 *	if a chunk is ever freed its values get added to
	 *	Heap.free to be reclaimed for future use.
	*/
	_Mem_Chunk* chunks;

	/*	Heap.free is used to store location
	 *	of free memory avalable for allocation.
	*/
	_Mem_Chunk* free;

	size_t capacity;

	size_t allocated;

	size_t maxitems;

	size_t items;

}Heap;




/* Heap managment functions */
Heap Heap_Init(size_t size);


void Heap_Free(Heap* heap);


void Heap_Resize(Heap* heap, size_t size);


void Heap_DeFrag(Heap* heap);



/* Allocation functions */
void* H_alloc(Heap* heap, size_t amount);


void H_free(Heap* heap, void* ptr);


void* H_realloc(Heap* heap, void* ptr, size_t amount);

#endif
