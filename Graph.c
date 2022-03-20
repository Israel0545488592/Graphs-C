#pragma once

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>



void init_graph (graph* g, int init_size){

	int factor;
	init_size > 100 ? factor = (int)(init_size / 100) +1 : (factor = 1); //definig hash factor
	g -> hash = factor;

	g -> vertecies = (snake*) malloc(sizeof(snake) * factor);	//node[100][factor]
	
	for (int i = 0; i < factor; i++) {
		
		g -> vertecies[i] = *create_snake(100);
	}

	g -> edges = (snake**) malloc(sizeof(snake*) * factor);	//edge[100][factor][factor]

	for (int i = 0; i < factor; i++) {

		g -> edges[i] = (snake*) malloc(sizeof(snake) * factor);

		for (int j = 0; j < factor; j++) {

			g -> edges[i][j] = *create_snake(100);
		}
	}
}


void addNode (graph* g, int id){

	node *n = createNode(id);
	if (! n){ return;}

	addToSnake(&(g -> vertecies[id %(g -> hash)]), n);
}

void addEdge (graph* g, edge* e){

	addToSnake(&(g -> edges[(e -> src -> id) % (g -> hash)][(e -> dst -> id) % (g -> hash)]), e);
}