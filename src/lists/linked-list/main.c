#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>

void print_list(struct list *list)
{
    if(list == NULL)
    {
        printf("[NULL]");
        return;
    }
    printf("[%i] ", list->data);
    list = list->next;
    while(list != NULL)
    {
        if(list->next != NULL)
        {
            printf(" [%i]->[%i] ", list->data, list->next->data);
        }
        else
        {
            printf(" [%i] ", list->data);
        }
        list = list->next;
    }
    printf(" [NULL] \n");
}

void initList(struct list *list, int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        add_to(list,new_element(rand() % 100));
        list = list->next;
    }
  
}

int main()
{
    
}

