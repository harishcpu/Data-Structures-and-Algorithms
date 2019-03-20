#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

#define TRUE 0
#define FALSE 1

#define SUCCESS 0
#define FAILURE 1

#define MAXLEN 25

void infix_postfix_eval(char ch);
int push(int data);
int pop(void);
int mypow(int base, int pow);

int verify_expr(char *buf);
int isPostfix(char *buf);
int isPrefix(char *buf);

int isoperator(char c);
int isoperand(char c);


#endif
