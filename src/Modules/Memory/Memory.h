#include <stdlib.h>


typedef struct{

    void* data;

    size_t size;


}DynMemory;


/*

*/
DynMemory AllocMemory(size_t Size);

int ReallocMemory(DynMemory* Memory);

int FreeMemory(DynMemory* Memory);

#define Alloc(Name, Size, Type) \
        DynMemory Name = AllocMemory(Size * sizeof(Type)); \
        if(Name.data == NULL){ \
            return 1; \
        } \

