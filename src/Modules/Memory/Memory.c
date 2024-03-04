#include "Memory.h"


DynMemory AllocMemory(size_t Size){

    /* AllocMemory(size_t Amount)

        if alloc is successful then Mem.size = Amount
            Otherwise Mem.size = 1 for errors

    */

    DynMemory Mem;

    Mem.data = malloc(Size);

    Mem.size = Size;

    return Mem;
}


int ReallocMemory(DynMemory* Memory){

    /*  Reallocates a DynMemory with 50% more space

        if realloc() fails then we return 1
            otherwise we return 0.

    */
    void* old = Memory->data;

    Memory->data = realloc(Memory->data, (size_t)Memory->size * 1.5);

    if(Memory->data == old){
        return 1;
    }else{

        Memory->size = (size_t) Memory->size * 1.5;

    return 0;
    }
}


int FreeMemory(DynMemory* Memory){

    /*  Frees DynMemory

        If Memory->data is not NULL free Memor->data
            And return 0
        else
            return 1

    */
    if(Memory->data != NULL){

        free(Memory->data);

        Memory->data = NULL;

        Memory->size = 0;

        return 0;
    }else{

        return 1;
    }

}


