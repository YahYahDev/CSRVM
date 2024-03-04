#ifndef Memory_H
#define Memory_H

#include <stdlib.h>
#include <assert.h>


/*  DynAlloc(Type, Name, Size)
 *
 *  makes a DynMem object called Mem_Name
 *
 *  makes a handle to the memory on the object
 *  called Name
 *
 *  if the allocation fails exit(1)
*/
#define DynNew(Type, Name, Size) \
    DynMem Mem_##Name = Mem_New(sizeof(Type) * 5);\
    Type* Name = (Type*)Mem_##Name->data;\
    if(Mem_##Name.data == NULL) exit(1);\


/*  DynAlloc(Name)
 *
 *  Runs the Mem_Expand() on the MEM_Name object
 *
 *  if it fails to resize then it will exit(1)
*/
#define DynAlloc(Name) \
    Mem_Expand(Mem_##Name); \
    if(Mem_##Name.data == NULL) exit(1);/


/*  DynFree(Name)
 *
 *  Runs Mem_Free(Mem_Name);
*/
#define DynFree(Name) \
        Mem_Free(Mem_##Name);\




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


    /*  Returns any status codes on memory
     *
     *  Can be
     *
     *      Mem_Normal
     *
     *      Mem_Full
     *
     *      Mem_OverFlow
    */
    Mem_Status_Code Mem_Status(DynMem* memory);


#endif
