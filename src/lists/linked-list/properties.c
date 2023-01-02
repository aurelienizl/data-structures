#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int is_empty(struct list *list)
{
    if(list->next == NULL)
    {
        return 1;
    }
    return 0;
}

int exists(struct list *list, int value)
{
    list = list->next; // Pass the sentinel 
    while(list != NULL)
    {
        if(list->data == value)
        {
            return 1;
        }
    }
    return 0;
}

struct list *get_at(struct list *list, int index)
{
    list = list->next; // Pass the sentinel

    while(index != 0)
    {
        list = list->next;
        index --;
    }
    return list;
}

int count(struct list *list)
{
    if(list == NULL)
    {
        return -1;
    }
    return 1 + count(list->next);
}