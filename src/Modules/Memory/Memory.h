#ifndef Memory_H
#define Memory_H

#include <stdlib.h>

    typedef struct{

        void* data;

        size_t allocted;

        size_t size;

    }DynMem;

    typedef enum{

        Full,

        OverFlow,

        Normal

    }Mem_Status_Codes;

    DynMem Mem_New(size_t size);

    void Mem_Free(DynMem* memory);

    void Mem_Expand(DynMem* memory);

#endif
