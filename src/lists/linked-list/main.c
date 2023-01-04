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

    struct list *empty = new_list();
    struct list *alone = new_list();
    struct list *random = new_list();

    initList(empty, 0);
    initList(alone, 1);
    initList(random, 10);

    printf("---BEFORE---\n");


    printf("Empty list : \n");
    print_list(empty);
    printf("Alone list : \n");
    print_list(alone);
    printf("Random list : \n");
    print_list(random);

    struct list *element1 = new_element(32);
    struct list *element2 = new_element(-12);
    struct list *element3 = new_element(0);
    struct list *element4 = new_element(32);
    struct list *element5 = new_element(-12);
    struct list *element6 = new_element(0);

    // TEST HERE 

    add_top(random,element1);
    insert_before(random, element1, element2);


    // TEST HERE 


    printf("---AFTER---\n");

    printf("Empty list : \n");
    print_list(empty);
    printf("Alone list : \n");
    print_list(alone);
    printf("Random list : \n");
    print_list(random);
}

