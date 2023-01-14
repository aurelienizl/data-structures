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
** @brief                    Node structure.
** @param depth              Represent the eccentricity of the node from the center.
** @param mark               Mark vector, the id of the node.
** @param data               Node data.
** @param adjacencyList      Adjacency graph_node list.
** @param adjacencyListSize  Number of nodes in the adjency list. 
*/

struct graph_node
{
    int depth;
    int mark;
    char *data;
    struct graph_node **adjacencyList;
    size_t adjacencyListSize;
};

/**
** @brief               Represent a full graph.
** @param node          Represent the head.
** @param id            Represent the id. 
*/

struct graph
{
    struct graph_node *head;
    int id; 
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

void destroy_graph(struct graph *head);

/**
** @brief               Create a new graph node.
** @param rank          Represent the eccentricity of the node from the center (the first is 0 by default).
** @return              A new graph node.
*/

struct graph_node *new_node(int depth, char* data);

/**
** @brief               Create a new graph.
** @param rank          Represent the graph id.
** @return              A new graph.
*/

struct graph *new_graph(int id);

/**
** @brief               Create a new node origin to the adjacency list of the node target.
** @param target        Represent the node a node that will receive the node to add.  
** @param origin        Represent the node to add.
** @return              Return true if the node is successfully added, otherwise false.
*/

void add_to_adjacencyList(struct graph_node *target, struct graph_node *origin);


#endif