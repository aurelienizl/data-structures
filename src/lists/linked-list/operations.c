#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *new_list()
{
    struct list *head = NULL;
    head = malloc(sizeof(struct list));
    head->next = NULL;
    head->data = -1;
    return head;
}

struct list *new_element(int data)
{
    struct list *head = NULL;
    head = malloc(sizeof(struct list));
    head->next = NULL;
    head->data = data;
    return head;
}

void remove_element(struct list *list)
{
    free(list);
}

void add_top(struct list *list, struct list *element)
{
    if(list->next == NULL) // Pass the sentinel
    {
        list->next = element;
        return;
    }
    element->next = list->next;
    list->next = element;
}

void add_end(struct list *list, struct list *element)
{
    while(list->next != NULL) // Pass the sentinel
    {
        list = list->next;
    }
    list->next = element;
}

void swap(struct list *element1, struct list *element2)
{
    int tmp = element1->data;
    element1->data = element2->data;
    element2->data = tmp;
}

void sort(struct list *list)
{
    int size = count(list);
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(get_at(list,i)->data > get_at(list,j)->data)
            {
                swap(get_at(list,i), get_at(list,j));
            }
        }
    }
}

void sort_reverse(struct list *list)
{
    int size = count(list);
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(get_at(list,i)->data < get_at(list,j)->data)
            {
                swap(get_at(list,i), get_at(list,j));
            }
        }
    }
}

void remove_at(struct list *list, int index)
{
    struct list *tmp = list;
    list = list->next;

    while(index > 0 && list != NULL)
    {
        tmp = list;
        list = list->next;
        index --;
    }
    if(index != 0 || list == NULL)
    {
        return;
    }
    tmp->next = list->next;
    remove_element(list);
}