#ifndef ByteCode_H

#define ByteCode_H

/*  ByteCode types
 *
 *      Used to describe types of values in bytecode
 *
 *  TODO:
 *
 *      1): Add floats
 *
 *      2): Add chars
*/
typedef enum{

    Type_Int8,

    Type_Int16,

    Type_Int32,

    Type_Int64,

    Type_UInt8,

    Type_UInt16,

    Type_UInt32,

    Type_UInt64,


}Code_Type;


typedef enum{

    /*  Stack Commands
     *
    */
    Command_Stack_Push,

    Command_Stack_Pop,


    /*  Register Commands
     *
    */
    Command_Register_Push,

    Command_Register_Pop,


    /*  Arithmatic Commands
     *
    */
    Command_Add,

    Command_Sub,

    Command_Mul,

    Command_Div,

    Command_Mod,


    /*  Logic Commands
     *
    */
    Command_Compare,


}Code_Command;

typedef struct{

    Code_Type type;

    Code_Command instrustion;

    void* data[];


}Code_Instruction;


#endif
