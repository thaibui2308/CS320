/*Name : Thai Bui
 * Class: CS320-01
 * Date: 9/19/21
 * File: stackd.h -- type definitions, symbolic constants,
 * and function prototypes for dynamic linked list implementation
 * of stack ADT.
 */

#ifndef STACKD_H
#define STACKD_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {FALSE, TRUE} boolean_t;
typedef int el_t;  /* type varies with application */

typedef struct node node_t;
typedef node_t* stack;

struct node {
    el_t el;
    struct node* next;
};

/* Function prototypes for the stack operations */

stack     MakeNode(el_t);
void      InitStack(stack*);
boolean_t StackIsEmpty(stack*);
boolean_t StackIsEmpty(stack*);
void      Push(stack*, el_t);
void      Pop(stack*, el_t*);
void      PrintStackUp(stack);
void      PrintStack(stack);

#endif
