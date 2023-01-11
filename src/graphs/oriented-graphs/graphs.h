/*
 * Author: Izoulet Aurélien.
 * Purpose: Oriented Graph implementation.
 * Language: C.
 */
#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stdlib.h>
#include <stdio.h>
#include <err.h>

/**
** @brief         Node structure.
** @param rank    Represent the eccentricity of the node from the center.
** @param marked  Mark vector.
** @param data    Node data.
** @param linked  Adjacency linked list.
*/

struct graph_node
{
    int rank;
    int marked;
    char *data;
    struct graph_node **adjacencyList;
    size_t adjacencyListSize;
};

/**
** @brief               Free node memory.
** @param node          Represent the node.
** @return              Void.
*/

void destroy_node(struct graph_node *node);

/**
** @brief               Free all node on a graph.
** @param node          Represent the head node.
** @return              Void.
*/

void destroy_graph(struct graph_node *head);

/**
** @brief               Create a new graph node.
** @param rank          Represent the eccentricity of the node from the center (the first is 0 by default).
** @return              A new graph node.
*/

struct graph_node *new_node(int rank, char* data);



#endif