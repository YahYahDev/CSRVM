#ifndef Instructions_H

#define Instructions_H

#include <stdint.h>

typedef enum{

    CodeAdd = 1,
    // Add Instruction
    CodeSub = 2,
    // Subtract Instruction
    CodeMul = 3,
    //  Multiply Instruction
    CodeDiv = 4,
    //  Divide Instruction
    CodeRem = 5,
    //  Remainer Instruction, also known as modulus or "%" in C
    CodeStackPush = 6,
    //  Push Value to Stack Instruction
    CodeStackPull = 7,
    //  Pull Value from Stack Instruction
    CodeSetRegi = 8
    //  Set Register Instruction

}Command;


typedef enum{


    TypePointer = -4,

    TypeNil = -2,

    TypeNull = -1,

    TypeBool = 0,

    TypeInt8 = 1,

    TypeInt16 = 2,

    TypeInt32 = 3,

    TypeInt64 = 4,

    TypeUInt8 = 5,

    TypeUInt16 = 6,

    TypeUInt32 = 7,

    TypeUInt64 = 8,

    TypeFloat16 = 9,

    TypeFloat32 = 10,

    TypeFloat64 = 11,

}Type;

typedef struct{

    Type type;

    Command command;

    void* data[1];

}Instrustion;



#endif

