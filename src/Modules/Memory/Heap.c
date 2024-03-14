#include "Heap.h"




Heap Heap_Init(size_t size){
	/*	Heap_Init()
	 *
	 *	Initalizes a Heap for memory allocation
	 *
	*/
	Heap heap = {
		.allocated = 0,
		.capacity = size,
	};

	heap.data = _LibMemAlloc(size);

	heap.chunks = NULL;

	return heap;

}


void Heap_Free(Heap* heap){

	_LibMemFree(heap->data);
	heap->data = NULL;
	heap->allocated = 0;
	heap->capacity = 0;

}


void Heap_Resize(Heap* heap, size_t size){
	/*	Resizes Heap.data to a new size,
	 *	uses _LibMemRealloc() macro to resize
	*/
}


void Heap_DeFrag(Heap* heap){
	/*	Defragments the Heap.free and Heap.chunks
	 *	so that all active memory is continues,
	 *
	 *	this will help reduce the need to allocate
	 *	more memory than needed though the operation
	 *	is costly
	*/
}




void* H_Alloc(Heap* heap, size_t amount){
	/*	Allocates some memory from the heap
	 *	very similar usage to malloc()
	*/
	if(heap->allocated + amount <= heap->capacity){
		/* do allocation stuff here */
	}else{
		/* attempt to reallocate Heap.data
		 * if we fail at reallocation return NULL
		*/
	}
}


void H_free(Heap* heap, void* ptr){
	/*	Frees memory allocation from H_alloc()
	 *
	*/
}


void* H_realloc(Heap* heap, void* ptr, size_t amount){


}
