#include "Arena.h"
#include <stdio.h>
/* TODO:
 *
 *  1): add a way to accese the last node in the linked list
 *      without traversing the whole list
 *
 *
 */

typedef struct Arena{

	// memory used to store data
	void* data;

	// ptr is used to index the data
	size_t ptr;
	// capacity is used to see what max capacity is
	size_t capacity;


	// these are used to store where the next node is for storage
	Arena* next_node;

	Arena* head_node;

	Arena* last_node;

}Arena;




/* returns an Arena handle to use.
 *
 */
Arena* Arena_Init(size_t chunk_size){

	// initalize the memory for the arena
	Arena* arena = (Arena*)_LibMemAlloc(sizeof(Arena));

	// get memory for storing object in the arena
	arena->data = _LibMemAlloc(chunk_size);

	arena->capacity = chunk_size;

	arena->ptr = 0;

	arena->head_node = NULL;

	arena->next_node = NULL;

	arena->last_node = arena;

	return arena;
}


/* used to add a arena to the list of arenas
 * for allocations
 */
void Add_Arena(Arena* arena){

	Arena* new_arena = _LibMemAlloc(sizeof(Arena));
	new_arena->capacity = arena->capacity;

	new_arena->ptr = 0;

	new_arena->data = _LibMemAlloc(new_arena->capacity);
	new_arena->next_node = NULL;

	new_arena->head_node = arena->last_node;

	new_arena->last_node = NULL;

	/* Set the old tail arena's next node to the new arena
	 */
	arena->last_node->next_node = new_arena;
	/* Set the tail node to be the new arena
	 */
	arena->last_node = new_arena;

}

/* searches all arenas for a first fit to size
 */
void* Handle_Full_Arena(Arena* arena, size_t amount){
	/* TODO: Note this might loop for ever
	 * if Add_Arena() fails every time
	 */
	for(Arena* node = arena; node->next_node != NULL; node = node->next_node){
		/* checks for if allocation will fit then allocates
		 */
		if(node->ptr + amount <= node->capacity){
			node->ptr = node->ptr + amount;
			return node->data + node->ptr - amount; // return allocation pointer;
		}
	}
	return NULL; // failed at allocating???
}

/* used to clean up any linked arenas allocated
 *
 * returns the amount of arenas cleaned out
 */
size_t Arena_CleanUp(Arena* arena){

	if(arena->last_node == arena) return 0;

	size_t i = 0;
	Arena* node = arena;
	for(Arena* node = arena->last_node->head_node; node->head_node != NULL; node = node->head_node){
		/* iterates through every node backwards to the head
		 *
		 *   frees next node in the list and NULL's it
		 */
		_LibMemFree(node->next_node->data);
		node->next_node->data = NULL;

		_LibMemFree(node->next_node);
		node->next_node = NULL;

		i++;
	}

	/* Frees the last node that was missed in the loop
	 * and sets node->last to the arena for future allocations
	 */
	_LibMemFree(node->next_node->data);
	node->next_node->data = NULL;


	_LibMemFree(node->next_node);
	node->next_node = NULL;


	node->last_node = node;

	i++;
	/* returns i so that you can know how many arenas where free'd
	 * for resizing the base arena when free'd
	 */
	return i;
}


/* used to resize the chunk for the memory
 */
void Arena_Expand(Arena* arena, size_t chunk_size){
	arena->data = _LibMemRealloc(arena->data, chunk_size);

	if(arena->data == NULL) exit(1);
}


/* used to free the arena aka destroy it
 */
void* Arena_Free(Arena* arena){
	Arena_CleanUp(arena);
	if(arena->data == NULL || arena == NULL)
	_LibMemFree(arena->data);
	arena->data = NULL;
	_LibMemFree(arena);
	arena = NULL;
}




void* A_alloc(Arena* arena, size_t amount){

	size_t mem = 0;
	if(arena->ptr + amount <= arena->capacity){
		RETRY:

		mem = arena->ptr;
		arena->ptr = arena->ptr + amount;

		return arena->data + mem;

	}else if(amount > arena->capacity){
		/* Handle Over Allocation */
		Add_Arena(arena);
		Arena_Expand(arena->last_node, amount);
		perror("Failed to Allocate: Memory Chunk Too Small For Allocation");
		return arena->last_node->data;
	}else{
		/* Handle Chain Allocation */
		Retry_Chain:;

		void* data = Handle_Full_Arena(arena, amount);

		if(data != NULL){
			return data;
		}else{
			Add_Arena(arena);
			goto Retry_Chain;
		}

	}
	return NULL;
}

/* deletes all data in the data
 *
 *   resizes arena size based on
 *   how many arenas allocated before
 *   freeing.
 */
void A_free(Arena* arena){

	size_t regions = Arena_CleanUp(arena);

	Arena_Expand(arena, arena->capacity * (size_t) regions * 0.75);

	arena->ptr = 0;

}
