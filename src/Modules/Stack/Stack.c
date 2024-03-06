#include "Stack.h"


Stack_ERROR Stack_Push(Stack* stack, ByteCode_Data* data){


    /*  ERROR CHECK
     *
     *  if the stack has room allocate to it and return Stack_Normal
     *
     *  if the stack is full return Stack_OverFlow
     *
    */
    printf("Push Data: %d\n", *(int*)data->data);
    if(stack->top++ >= stack->capacity){

        stack->data[stack->top] = *data;

        stack->top++;

        return Stack_Normal;
    }else{
        return Stack_OverFlow;
    }
}

Stack_ERROR Stack_Pop(Stack* stack){


    /*  ERROR CHECK
     *
     *  if stack.top < 0 then return Stack_UnderFlow
     *
     *  otherwise decrease stack.top by one
     *
    */
    if((int64_t)stack->top-- < 0){
        return Stack_UnderFlow;
    }else {
        stack->top--;
        return Stack_Normal;
    }

}

void Stack_Peek(Stack* stack){

    printf("Top Of The Stack: %p\n", stack->data[stack->top].data);

}
