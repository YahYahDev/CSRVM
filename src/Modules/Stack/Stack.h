#ifndef Stack_H

#define Stack_H

#include <stdio.h>

#include "../Memory/Memory.h"
#include "../ByteCode/ByteCode.h"



typedef enum{

    Stack_Normal = 0,

    Stack_OverFlow,

    Stack_UnderFlow,


}Stack_ERROR;


typedef struct{

    ByteCode_Data data[256];

    size_t top;

    size_t capacity;

}Stack;


Stack_ERROR Stack_Push(Stack* stack, ByteCode_Data* data);

Stack_ERROR Stack_Pop(Stack* stack);

void Stack_Peek(Stack* stack);





#endif
