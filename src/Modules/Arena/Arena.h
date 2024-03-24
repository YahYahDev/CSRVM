#ifndef Arena_H

#define Arena_H

#include "../Memory/Memory.h"

/*	Arena.h
 *
 *	a simple bumb allocator arena
 *	with low overhead
 *
 *
 *	any function that has Arena_ is used
 *	to manage the actual arena so
 *	Arena_Free(&arena); would destroy the arena
 *	entirly not just reset it
*/





typedef struct Arena Arena;



/* Arena_Init(size) initalizes an arena to size */
Arena* Arena_Init(size_t size);

/* Arena_free frees the entire arena */
void Arena_Free(Arena* arena);

/* Arena_Expand attempts to expand arena limmits */
void Arena_Expand(Arena* arena, size_t size);

/* A_alloc() allocates some memory from the arena */
void* A_alloc(Arena* arena, size_t size);

/* A_free frees all alocation to the arena */
void A_free(Arena* arena);


#endif
