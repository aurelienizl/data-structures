/*
 * Author: Izoulet Aurélien
 * Purpose: Oriented Graph implementation 
 * Language: C.
 */
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
        list = list->next;
    }
    return 0;
}

int is_sorted(struct list *list)
{
    list = list->next;
    if(list == NULL)
    {
        return 1;
    }

    while(list->next != NULL)
    {
        if(list->data > (list->next)->data)
        {
            return 0;
        }
        list = list->next;
    }

    return 1;
}

int count(struct list *list)
{
    if(list == NULL)
    {
        return -1;
    }
    return 1 + count(list->next);
}