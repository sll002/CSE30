/*
 * Programming assignment 1 
 *
 * remove c comments from a source file and write to stdout
 * comments are replaced with a single space
 * handle single and double quoted sequences
 * comments and quoted sequences can span multiple lines
 *
 * error handling:
 *     prints starting line for unterminated comments or quote sequences
 */

#include <stdio.h>
#include <stdlib.h>
#include "omit.h"
#define NEWLINE 10
#define SLASH 47
#define STAR 42
#define DQUOTE 34 
#define SQUOTE 39
#define SPACE 32
#define NEWLINE 10


int
main(void)
{
    
    enum typestate state = OUT_COMMENT; //starting state
    int commentStart = 0;
    int c;
    while((c = getchar()) != EOF){
        
        switch(state){
            case OUT_COMMENT:
                
                state = OUT_COMMENTst(c);
                
                break;
            
            case IN_COMMENT:
                
                if(!commentStart){
                    lineStart=lineCount+1;
                    commentStart = 1;
                }
                state = IN_COMMENTst(c);
                break;

            case IN_DSTRING:
                state = IN_DSTRINGst(c);
                break;

            case IN_SSTRING:
                state = IN_SSTRINGst(c);
                break;

            case LINE_COMMENT:
                state = LINE_COMMENTst(c);
                break;

            case END:
                return 0;
        }
        if(c==NEWLINE){
            lineCount++;
        }
    }
    switch(state){
        case IN_SSTRING:
            fprintf(stderr,"Error: line \%i: unterminated quote(\')\n",lineCount);
            break;
        case IN_DSTRING:
            fprintf(stderr,"Error: line \%i: unterminated quote(\")\n",lineCount);
            break;

        case IN_COMMENT:
            fprintf(stderr,"Error: line \%i: unterminated comment\n",lineStart);
            break;
        
        default:
            break;
    }

    
    return 0;
}