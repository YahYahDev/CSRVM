#include "Memory.h"
/* ALLOCATION MACROS */

/*	These are to be used to swap out
 *	what ever allocator you want to use
 *
 * 	NOTE:
 * 		these will be undefined at the end of the file
 * 		and are not global scope macros
*/
#define MemAlloc(size) malloc(size)

#define MemFree(ptr) free(ptr)

#define MemResize(ptr, size) realloc(ptr, size)






Heap Heap_New(size_t size){

	/*	Initializes a heap object;
	 *
	 *	heap.data holds a pointer to
	 *	memory
	 *
	 *	heap.filled is used to keep track
	 *	of how much of the heap has been used
	 *	and where the next allocation should be
	 *	*assuming allocations are linear*
	 *
	 *	heap.capacity is used to keep track
	 *	of max size the heap can hold
	*/
	Heap heap;

	heap.data = MemAlloc(size);

	heap.capacity = size;

	heap.filled = 0;

	return heap;
}


void Heap_Free(Heap* heap){
	/*	Frees heap.data
	 *  sets .filled, .capacity to 0
	 * 	and .data to NULL
	*/
	free(heap->data);
	heap->data = NULL;
	heap->filled = 0;
	heap->capacity = 0;
}


void Heap_Resize(Heap* heap, size_t new_size){
	/*	Calls realloc() to resize the heap
	*/
	heap->data = MemResize(heap->data, new_size);

	heap->capacity = new_size;

}


void* Heap_Alloc(Heap* heap, size_t amount){
	/*	Returns a void* to a spot in the heap
	 *	for memory allocation
	 *
	 *	if the heap is full returns NULL
	*/
	if(heap->filled + amount <= heap->capacity){
		size_t old_fill = heap->filled;
		heap->filled = heap->filled + amount;
		return heap->data + old_fill;
	}else{
		return NULL;
	}
}


void Heap_Debug(Heap* heap){
	/*	Prints the heap information
	 *	for debuging purposes
	*/
	printf("Heap Data: %lu\nHeap Filled: %lu\nHeap Capacity: %lu\n", heap->data, heap->filled, heap->capacity);

}




/* UNDEFINE MACROS */
#undef  MemAlloc
#undef  MemFree
#undef  MemResize
