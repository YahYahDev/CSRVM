#ifndef Arena_H

#define Arena_H

#include "../Memory/Memory.h"

/* Arena.h
 *
 *   An arena allocator:
 *
 *     functions that start with Arena_ are used to
 *     manage the arena its self
 *
 *     functions that start with A_ are used for allocating
 *
 *     automaticly resizes the arena as more memory is required
*/




/* Defines Arena type for use,
   Actual implementation in Arena.c */
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
