/*
 * Author: Izoulet Aurélien
 * Purpose: Linked list implementation 
 * Language: C.
 */
#include "list.h"

char *random_string_gen(size_t length)
{

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // could be const
    char *randomString;

    if (length)
    {
        randomString = malloc(length + 1);
        if (randomString)
        {
            int l = (int)(sizeof(charset) - 1);
            int key;
            for (size_t n = 0; n < length; n++)
            {
                key = rand() % l;
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
             return randomString;
        }
    }
    return random_string_gen(10);
}

/**
** @brief         Print the data of all nodes in the standard output. 
** @param list    A list pointer, the head.
** @return        Void
*/

void print_list(struct list *list)
{
    if(list == NULL)
    {
        printf("[NULL]");
        return;
    }
    printf("[%s] ",(char*) list->data);
    list = list->next;
    while(list != NULL)
    {
        if(list->next != NULL)
        {
            printf(" [%s]->[%s] ",(char*) list->data,(char*) list->next->data);
        }
        else
        {
            printf(" [%s] ", (char*) list->data);
        }
        list = list->next;
    }
    printf(" [NULL] \n");
}

/**
** @brief         Add n element with random data to the list
** @param list    The node to add elements 
** @param n       The number of nodes to add 
** @return        Void
*/

void initList(struct list *list, int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        add_to(list,new_element(random_string_gen(rand() % 10)));
        list = list->next;
    }
  
}

int main()
{

    printf("\n\n");

    struct list *list = new_list();
    initList(list, 10);

    struct list *elt1 = new_element(random_string_gen(10));
    printf("Element 1 : %s\n", (char*) elt1->data);
    add_end(list,elt1);
    
   

    print_list(list);
    printf("%s\n", (char*) get_at(list, 0)->data);

    remove_list(list);
    printf("\n\n");

}

