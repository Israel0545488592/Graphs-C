#pragma once

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>



void init_graph (graph* g, int init_size){

	int factor;
	init_size > 100 ? factor = (int)(init_size / 100) +1 : (factor = 1); //definig hash factor


	init_snake(&(g -> vertecies), factor);	//vertecies -> (node[100])[factor]
	
	for (int i = 0; i < factor; i++) {
		
		snake* sources = (snake*)malloc(sizeof(snake));
		init_snake(sources, factor);
		g -> vertecies.arr[i] = sources;
	}

	init_snake(&(g -> edges), factor);	//edges -> ((edge[100])[factor])[factor]

	for (int i = 0; i < factor; i++) {

		snake* sources = (snake*) malloc(sizeof(snake));
		init_snake(sources, factor);
		g -> edges.arr[i] = sources;

		for (int j = 0; j < factor; j++) {

			snake* destinations = (snake*) malloc(sizeof(snake));
			init_snake(destinations, 100);
			sources -> arr[j] = destinations;
		}
	}
}