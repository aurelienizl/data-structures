/*
 * Author: Izoulet Aurélien
 * Purpose: Stack Graph implementation 
 * Language: C.
 */

#ifndef _STACK_H_ 
#define _STACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
** @brief         Linked list structure.
** @param next    Next list element.
** @param next    Prev list element.
** @param data    Represent the data stored in the node.
*/

struct list
{
    struct list *next;
    struct list *prev;
    char* data;
};

/**
** @brief         Stack structure.
** @param last    The element at the top of the stack. 
*/

struct stack
{
    struct list *last;
};

/**
** @brief         Initialise a new stack. 
** @return        A stack structure.
*/

struct stack *new_stack();

/**
** @brief         Check if a stack is empty. 
** @param stack   A stack pointer.
** @return        1 if true, 0 if false.
*/

int is_empty(struct stack *stack);

/**
** @brief         Add to the stack a new element with data. 
** @param stack   A stack pointer.
** @return        1 if true, 0 if false.
*/

void addstack(struct stack *stack, char* data);

/**
** @brief         Delete an element to the stack and return it's data.  
** @param stack   A stack pointer.
** @return        The data of the last element from the stack element. 
** @note          The data of the element needs to be freed. 
*/

char* unstack(struct stack *stack);

/**
** @brief         Free all data from a stack structure.  
** @param stack   A stack pointer.
** @return        Void.
*/

void freestack(struct stack *stack);


#endif