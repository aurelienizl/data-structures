#ifndef _LIST_H_ 
#define _LIST_H_

struct list
{
    struct list *next;
    int data;
};

// Initialize the sentinel of an empty list.
void new_list(struct list *list);

// ----PROPERTIES---- //

// Return true if the list is empty.
// Otherwise, return false.
int is_empty(struct list *list);

// Return true if the first element that contains 'value' is found.
// Otherwise, return false. 
int exists(struct list *list, int value);

// Return true if the list is sorted.
// Otherwise, return false.
int is_sorted(struct list *list);

// ----OPERATIONS---- //

// Swap two element in the list if they exists. 
// Otherwise, do nothing. 
void swap(struct list *list, struct list *element1, struct list *element2);



#endif

