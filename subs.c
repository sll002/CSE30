/*
 * subroutines for omit program
 * one subroutine for each state of the DFA
 */
#include <stdio.h>
#include "omit.h"
#define SLASH 47
#define STAR 42
#define DQUOTE 34 
#define SQUOTE 39
#define SPACE 32
#define NEWLINE 10


enum typestate 
OUT_COMMENTst(int c)
{
    
    //check for slash, dquote, squote
    if(c==SLASH){
        //look for either star of second slash
        int next = getchar();
       
        if(next == STAR){
            putchar(SPACE);
            //lineStart=lineCount;
            return IN_COMMENT;
        }
        else if(next == SLASH){
            return LINE_COMMENT;
        }
        else{
            putchar(c);
            if(next != 0 && next != EOF){
                putchar(next);
            }
            
            return OUT_COMMENT;
        }
    }
    if(c==DQUOTE){
        putchar(c);
        return IN_DSTRING;
    }
    if(c==SQUOTE){
        putchar(c);
        return IN_SSTRING;
    }
   
    else{
        putchar(c);
        return OUT_COMMENT;
    }
}


enum typestate 
IN_COMMENTst(int c)
{   
    //in comment, looking for star
    
    if(c==NEWLINE){
           
        putchar(c);
    }
    if(c == STAR){
        
        int next = getchar();
        
        if(next == SLASH){   
            return OUT_COMMENT;
        }
        if(next==NEWLINE){
            putchar(next);
        }
    }
    
    return IN_COMMENT;
}

enum typestate 
IN_DSTRINGst(int c)
{
    if(c==DQUOTE){
        putchar(c);
        return OUT_COMMENT;
    }
    putchar(c);
    return IN_DSTRING;
}

enum typestate 
IN_SSTRINGst(int c)
{
    if(c==SQUOTE){
        putchar(c);
        return OUT_COMMENT;
    }
    putchar(c);
    return IN_SSTRING;
}

enum typestate
LINE_COMMENTst(int c){

    //int next = getchar();
    if(c==NEWLINE){
        putchar(SPACE);
        putchar(NEWLINE);
        return OUT_COMMENT;
    }
    return LINE_COMMENT;
}