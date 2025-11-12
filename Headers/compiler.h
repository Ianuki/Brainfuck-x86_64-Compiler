/*

    The BR compiler optimizes consecutive repeated operations
    

*/ 

#ifndef _COMPILER_
#define _COMPILER_

#include "asm_builder.h"

/* GAS */
#define GAS_INCREMENT_POINTER "\tadd rbx, %d \n" 
#define GAS_DECREMENT_POINTER "\tsub rbx, %d \n" 
#define GAS_INCREMENT_REGISTER "\tadd byte ptr [rbx], %d \n" 
#define GAS_DECREMENT_REGISTER "\tsub byte ptr [rbx], %d \n" 
#define GAS_OPEN_JEZ "\tloop%d: \n"
#define GAS_COMP_JEZ "\tcmp byte ptr [rbx], 0 \n\tjnefe loop%d \n"
#define GAS_PUTB "\tcall putb \n"

asm_builder compile(char *);

#endif 