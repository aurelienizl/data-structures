#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>

void print_list(struct list *list)
{
    printf("[%i] ", list->data);
    list = list->next;
    while(list != NULL)
    {
        printf(" %i ", list->data);
        list = list->next;
    }
    printf("\n");
}

void initList(struct list *list)
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        add_end(list,new_element(rand() % 10));
    }
  
}

int main()
{
    struct list *list = new_list();
    initList(list);
    printf("Current list : \n");
    print_list(list);

    remove_at(list, 1);

    printf("Modified list : \n");
    print_list(list);

}

