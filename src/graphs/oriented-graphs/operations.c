/*
 * Author: Izoulet Aurélien
 * Purpose: Oriented Graph implementation 
 * Language: C.
 */
#include "graphs.h"

/**
** @brief               Free node memory.
** @param node          Represent the node.
** @return              Void.
*/

void destroy_node(struct graph_node *node)
{
    free(node->data);
    for(size_t i = 0; node->adjacencyList[i] != NULL; i++)
    {
        free(node->adjacencyList[i]);
    }
    free(node);
}

/**
** @brief               Free node memory.
** @param node          Represent the node.
** @return              Void.
*/

struct graph_node *new_node(int rank, char* data)
{
    struct graph_node *new_node = malloc(sizeof(struct graph_node));

    if(new_node == NULL)
    {
        errx(1, "new_node: malloc error");
    }

    new_node->rank = rank;
    new_node->data = data;
    new_node->adjacencyList = NULL;
    new_node->adjacencyListSize = 0;
    new_node->marked = 0;

    return new_node;
}