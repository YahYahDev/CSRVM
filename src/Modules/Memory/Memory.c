#include "Memory.h"
#include <stdlib.h>


//  TODO:
//
//      1): Make a SubAllocator for memory so we minimize
//          the amount of calls to the Os for memory
//
//      2): Make Arenas that you can get from the pool of memory
//
//

//  Macros for seting allocators for furure changes

#define Alloc_New malloc
#define Alloc_Free free
#define Alloc_Expand realloc


//Allocates a new DynMem object for memory
DynMem Mem_New(size_t size){

    DynMem memory = {

        .data = Alloc_New(size),

        .size = size,

        .allocted = 0
    };

    return memory;

}


//Frees a DynMem object from memory
void Mem_Free(DynMem* memory){

    if(memory->data != NULL){

        Alloc_Free(memory->data);

        memory->data = NULL;

        memory->allocted = 0;

        memory->size = 0;

    }
}


//Reallocates more memory to DynMem object
void Mem_Expand(DynMem* memory){

    memory->data = Alloc_Expand(memory->data, (size_t)memory->size * 1.5);
    if(memory->data != NULL){
        memory->size = (size_t) memory->size * 1.5;
    }else{
        memory->size = 0;
        memory->allocted = 0;
    }
}


//Checks status of DynMem to see whats going on

Mem_Status_Codes
