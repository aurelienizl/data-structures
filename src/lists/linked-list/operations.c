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

void add_to(struct list *element, struct list *node)
{
    element->next = node;
}

void swap(struct list *element1, struct list *element2)
{
    int tmp = element1->data;
    element1->data = element2->data;
    element2->data = tmp;
}

void sort(struct list *list)
{
    if(list->next == NULL)
    {
        return;
    }
    if(list->next->next == NULL)
    {
        return;
    }

    struct list *i = list->next;
    struct list *j = list->next->next;
    while(i != NULL)
    {
        j = i->next;
        while(j != NULL)
        {
            if(i->data>j->data)
            {
                swap(i,j);
            }
            j = j->next;
        }
        i = i->next;
    }
}

void sort_reverse(struct list *list)
{
    if(list->next == NULL)
    {
        return;
    }
    if(list->next->next == NULL)
    {
        return;
    }

    struct list *i = list->next;
    struct list *j = list->next->next;
    while(i != NULL)
    {
        j = i->next;
        while(j != NULL)
        {
            if(i->data<j->data)
            {
                swap(i,j);
            }
            j = j->next;
        }
        i = i->next;
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

void remove_last(struct list *list)
{
    struct list *curr = list->next;
    struct list *before = list;

    if(curr == NULL)
    {
        return;
    }

    while(curr->next != NULL)
    {
        curr = curr->next;
        before = before->next;
    }

    before->next = NULL;
    remove_element(curr);
}

void remove_first(struct list *list)
{
    struct list *sentinel = list;
    struct list *first = sentinel->next;

    if(first == NULL)
    {
        return;
    }

    sentinel->next = first->next;
    remove_element(first);
}

void remove_list(struct list** head) {
    struct list *current = *head;
    struct list *tmp;

    while(current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *head = NULL;
}

void clear(struct list **list)
{
    struct list *current = (*list)->next;
    struct list *tmp;

    while(current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    (*list)->next = NULL;
}

void insert_at(struct list *list, struct list *node, int index)
{
    struct list *current = list->next;
    struct list *before = list;

    while(current != NULL && index > 0) // 
    {
        current = current->next;
        before = before->next;
        index--;
    }

    if(index > 0) // Index out of range
    {
        return;
    }

    if(current == NULL) // Insertion at the end of the list
    {
        before->next = node;
        return;
    }

    before->next = node; // Insertion between two nodes
    node->next = current;
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