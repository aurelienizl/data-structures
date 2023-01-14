/*
 * Author: Izoulet Aurélien
 * Purpose: Oriented Graph implementation
 * Language: C.
 */
#include "graphs.h"

char *random_string_gen(size_t length)
{

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!"; // could be const
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
        }
    }

    return randomString;
}

void print_graph_ext(struct graph_node *head)
{
    if (head != NULL)
    {
        for (size_t i = 0; i < head->adjacencyListSize; i++)
        {
            print_graph_ext((head->adjacencyList)[i]);
        }
        printf("-------------------------\n");
        printf("Data : %s\n", head->data);
        printf("Depth: %i\n", head->depth);
        printf("Mark : %i\n", head->mark);
        printf("Connx: %li\n", head->adjacencyListSize);
    }
}

void print_graph(struct graph *graph)
{
    struct graph_node *current = graph->head;
    print_graph_ext(current);
}

int main()
{
    //Hello World !
}