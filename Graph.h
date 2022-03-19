#pragma once

#include "DataStrucrures.h"

/* 
	The basis effecient graph implementation
	The graph would have 2 snakes (see DataStrucrures.h),
	one for nodes second for edges
	the snakes would acctually point to other snakes
	to divide the graphs elements by some factor k
	that depends on the size of the graph (meaning it can change)
	the node/edge search algorithm will use k to 'hash' their
	way to the destinations (root[src % k][dst % k])

	this is'nt a full implementation yet!
	this the basis for more specific uses like:
	diracted-wieghted-graphs, flow-networks, ext...
*/

typedef struct graph {

	snake vertecies;
	snake edges;
	int hash;

}graph;


void init_graph (graph*, int);

void dismental_graph (); //free

void addNode(int);
void removeNode(int);
void addEdge(edge*);  //each implementation would define 'connect'
void removeEdge(int, int);
