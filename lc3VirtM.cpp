//=================================================
//File:        lc3VirtM.cpp
//Author:      James Ortiz
//Description: An LC-3 Virtual Machine
//implemented in C++11.
//Compile:
//=================================================

#include<iostream>
#include<stdlib>
#include<stdint.h>
#include<string>
#include<signal>
#include<unistd.h>
#include<fcnt1.h>


#include<sys/time.h>
#include<sys/types.h>
#include<sys/termios.h>
#include<sys/mman.h>


#define UINT16_MAX 65536

uint16_t memory[UINT16_MAX];


//Registers:
enum
  {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,    //Program Counter
    R_COND,  //condition (COND) register
    R_COUNT 
  };

//Store registers into array:
uint16_t reg[R_COUNT];


//Enum of operations in LR-3:
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};




