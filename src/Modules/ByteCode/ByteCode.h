#ifndef ByteCode_H

#define ByteCode_H

#include <stdint.h>


#define ByteCode_Case(Code)


/*  ByteCode_Inst
 *
 *      ByteCode instructions for the VM
 *
 *      (X): Math
 *
 *      (X): Stack
 *
 *
*/

typedef enum : int_fast8_t{

    /*  Math Operations
     *
    */

    Inst_Add,

    Inst_Sub,

    Inst_Mul,

    Inst_Div,

    Inst_Mod,


    /*  Stack Operations
     *
    */

    Inst_StackPush,

    Inst_StackPop,

    /*  Register Opterations
     *
    */

    Inst_RegiPush,

    Inst_RegiPop,


}ByteCode_Inst;

/*  ByteCode_Type
 *
 *      (X): Int8 - Int64
 *
 *      (): uInt8 - uInt64
 *
 *      (): Float8 - Float64
 *
 *      (): Char
*/
typedef enum : int_fast8_t{

    Type_Nil,

    Type_Bool,

    Type_Int8,

    Type_Int16,

    Type_Int32,

    Type_Int64,

}ByteCode_Type;


/*  ByteCode Chunk
 *
 *      Used to store execution instructions
 *
 *      Will be used in the instruction stack
*/
typedef struct{


    ByteCode_Type type;

    ByteCode_Inst instruction;


}ByteCode_Chunk;


/*  ByteCode_Data
 *
 *      Used to store data in the data stack
 *
*/
typedef struct{

    ByteCode_Type type;

    void* data;

}ByteCode_Data;

#endif
