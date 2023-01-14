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
    if (node != NULL)
    {
        free(node->data);
        {
            if (node->adjacencyList != NULL)
            {
                free(node->adjacencyList);
            }
        }
        free(node);
    }
}

/**
** @brief               Extention of : destroy_graph.
** @details             Recursively delete all nodes from the graph.
** @param node          Represent the head node.
** @return              Void.
*/

void destroy_graph_ext(struct graph_node *head)
{
    if (head != NULL)
    {
        for (size_t i = 0; i < head->adjacencyListSize; i++)
        {
            struct graph_node *tmp = head->adjacencyList[i];
            destroy_graph_ext(tmp);
        }
        destroy_node(head);
    }
}

/**
** @brief               Free all node on a graph.
** @param node          Represent the head node.
** @return              Void.
*/

void destroy_graph(struct graph *head)
{
    struct graph_node *current = head->head;
    destroy_graph_ext(current);
    free(head);
}

/**
** @brief               Free node memory.
** @param node          Represent the node.
** @return              Void.
*/

struct graph_node *new_node(int rank, char *data)
{
    struct graph_node *new_node = malloc(sizeof(struct graph_node));

    if (new_node == NULL)
    {
        errx(1, "new_node: malloc error");
    }

    new_node->depth = rank;
    new_node->data = data;
    new_node->adjacencyList = NULL;
    new_node->adjacencyListSize = 0;
    new_node->mark = 0;

    return new_node;
}

/**
** @brief               Create a new graph.
** @param rank          Represent the graph id.
** @return              A new graph.
*/

struct graph *new_graph(int id)
{
    struct graph *new = malloc(sizeof(struct graph));
    if (new == NULL)
    {
        errx(1, "new_graph: malloc error");
    }

    new->head = NULL;
    new->id = id;

    return new;
}

/**
** @brief               Create a new node origin to the adjacency list of the node target.
** @param target        Represent the node a node that will receive the node to add.
** @param origin        Represent the node to add.
** @return              Return true if the node is successfully added, otherwise false.
*/

void add_to_adjacencyList(struct graph_node *target, struct graph_node *origin)
{
    if (target->adjacencyList == NULL)
    {
        target->adjacencyList = malloc(sizeof(struct graph_node));
        if (target->adjacencyList == NULL)
        {
            errx(1, "add_to_adjacencyList: unable to allocate memory");
        }
        target->adjacencyList[target->adjacencyListSize] = origin;
        target->adjacencyListSize = 1;
        origin->depth = target->depth + 1;
    }
    else
    {
        struct graph_node **tmp = realloc(target->adjacencyList, sizeof(struct graph_node) * (target->adjacencyListSize + 1));
        if (target->adjacencyList == NULL)
        {
            errx(1, "add_to_adjacencyList: unable to reallocate memory");
        }
        target->adjacencyList = tmp;
        target->adjacencyList[target->adjacencyListSize] = origin;
        target->adjacencyListSize++;
        origin->depth = target->depth + 1;
    }
}
