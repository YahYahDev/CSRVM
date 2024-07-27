#ifndef Instructions_H
#define Instructions_H

#include <stdint.h>

/* Byte_Inst Aka Bye Instruction
 *
 *   enum to define what instructions their are
 */
typedef enum Byte_Inst: uint8_t{
	/* if a instruction = 0 then it unimplemented */
	UNIMPLEMENTED = 0,


}Byte_Inst;


/* Byte_Op Aka Byte Operation
 *
 *   struct used to store instructions
 *   and operands
 */
typedef struct Byte_Op{

	Byte_Inst instruction;



}Byte_Op;



#endif
