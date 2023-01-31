/*
 * Author: Izoulet Aurélien
 * Purpose: Oriented Graph implementation 
 * Language: C.
 */

#include "stack.h"

struct stack *new_stack()
{
    struct stack *stack = malloc(sizeof(struct stack));
    stack->last = NULL;
    return stack;
}

void addstack(struct stack *stack, char* data)
{
    struct list *top = stack->last;
    if(top == NULL)
    {
        top = malloc(sizeof(struct list));
        top->data = malloc(sizeof(char) * (strlen(data) + 1));
        top->data = data;
        top->next = NULL;
        top->prev = NULL;
        stack->last = top;
    }
    else
    {
        struct list *new = malloc(sizeof(struct list));
        new->data = malloc(sizeof(char) * (strlen(data) + 1));
        new->data = data;
        new->prev = top;
        new->next = NULL;
        stack->last = new;
    }
}

char* unstack(struct stack *stack)
{
    struct list *last = stack->last;
    if(last == NULL)
    {
        return NULL;
    }
    else
    {
        char *data = last->data;
        size_t size = strlen(data);
        char *new_space = malloc(sizeof(char) * (size + 1));
        strncpy(new_space, data, size);
        new_space[size - 1] = '\0';
        stack->last = stack->last->prev;
        free(last->data);
        free(last);
        return new_space;
    }
}

void freestack(struct stack *stack)
{
    struct list *top = stack->last;
    while(top != NULL)
    {
        struct list *tmp = top->prev;
        free(top->data);
        free(top);
        top = tmp;
    }
    free(stack);
}
