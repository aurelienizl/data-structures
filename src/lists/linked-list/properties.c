#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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