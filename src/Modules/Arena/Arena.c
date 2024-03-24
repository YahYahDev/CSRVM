#include "Arena.h"

/*	TODO:
 *
 *		1): Implement chained arenas
 *			that automaticly deallocate
 *			when your done with them
 *
 *
*/


typedef struct Arena{

	void* data;

	size_t capacity;

	size_t filled;

	size_t amount;

	/* points to next node */
	struct Arena* next;

	/* points to mother node */
	struct Arena* header;


}Arena;


/* Arena_Init()
 *
 *	Initializes the values of the arena
 *	??kinda like a constructor??
 */
Arena* Arena_Init(size_t size){
	Arena* arena = _LibMemAlloc(sizeof(Arena));

	arena->capacity = size;
	arena->filled = 0;
	arena->amount = 0;

	arena->next = NULL;
	arena->header = NULL;

	arena->data = _LibMemAlloc(size);


	return arena;
}


/*	Arena_Expand(Arena*, size_t);
 *
 *	Expands the capacity of an arena
 *
 *	If reallocation fails it will exit with code 1
 *
 *	??kinda like realloc??
*/
void Arena_Expand(Arena* arena, size_t size){

	arena->capacity = size;
	arena->data = _LibMemRealloc(arena->data, size);

	if(arena->data == NULL) exit(1);
}


/*	Arena_Free()
 *
 *	Frees/Nulls out any thing related to the arena
 *
 *	??kinda like a deconstructor??
*/
void Arena_Free(Arena* arena){
	arena->capacity = 0;
	arena->filled = 0;

	/* Implement free all arenas linked */

	_LibMemFree(arena->data);
	arena->data = NULL;


}




void* A_alloc(Arena* arena, size_t size){
	/* checks if allocation would excede arena size
	 * if it doesnt then it returns adress to the
	 * memory and increases filled for the next allocation
	 *
	 * if it fails it returns NULL
	*/

	if(arena->filled + size <= arena->capacity){
		/* Checks first arena if it has space then
		 * allocates from it if able
		*/
		size_t location = arena->filled;
		arena->filled = arena->filled + size;
		return arena->data + location;
	}else{
		/* Returns NULL for failing */
		return NULL;
	}

	/* TODO: add loging to arena allocation fails */
}


void A_free(Arena* arena){
	arena->filled = 0;
	/* Implement free all arenas linked */

	/* Implement expand arena based on how many linked arenas destroyed */

}
