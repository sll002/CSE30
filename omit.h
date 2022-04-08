/* 
 * the next two lines are the header guards
 */
#ifndef _OMIT_H
#define _OMIT_H
/*
 * header file for omit
 * type definition (enum) for DFA states
 * function prototypes
 */
enum typestate {OUT_COMMENT, IN_COMMENT, IN_DSTRING, IN_SSTRING, LINE_COMMENT, END};
int lineCount;
int lineStart;

//function prototypes
enum typestate OUT_COMMENTst(int);
enum typestate IN_COMMENTst(int);
enum typestate IN_DSTRINGst(int);
enum typestate IN_SSTRINGst(int);
enum typestate LINE_COMMENTst(int);
#endif