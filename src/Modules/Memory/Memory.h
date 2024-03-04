#ifndef Memory_H
#define Memory_H

#include <stdlib.h>

    typedef struct{

        void* data;

        size_t allocted;

        size_t size;

    }DynMem;


    typedef enum{

        Mem_Full,

        Mem_OverFlow,

        Mem_Normal

    }Mem_Status_Code;


    /*  Returns a new memory object
     *
    */
    DynMem Mem_New(size_t size);


    /*  Frees a memory object
     *
    */
    void Mem_Free(DynMem* memory);


    /*  Reallocs memory
     *
     *  memory.size = memory.size * 1.5
     *
     *  if Mem_Expand fails it sets
     *
     *  memory = {
     *
     *      .data = NULL,
     *
     *      .size = 0,
     *
     *      .amount = 0
     *  }
    */
    void Mem_Expand(DynMem* memory);


    /*
     *
    */
    Mem_Status_Code Mem_Status(DynMem* memory);


#endif
