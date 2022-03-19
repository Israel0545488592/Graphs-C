#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "DataStrucrures.h"


void init_snake (snake* snk, int init_size) {

	snk -> arr = (void**) malloc(sizeof(void*) * init_size);
	if (! snk -> arr) { return NULL;}

	snk -> prev = init_size;
	snk -> curr = init_size;
	snk -> itr = 0;

	return snk;
}


void addToSnake(snake* snk, void* data){

	if (snk -> curr == snk -> prev) { //realloc if needed
		
		snk -> arr = realloc(snk -> arr, (int) ((snk -> curr) * 1.3));

		if (! snk -> arr){
			 return;
		}
		else{
			snk -> curr = (int)((snk->curr) * 1.3);
		}
	}

	snk -> itr++;					//appending if all gone well
	snk -> arr[snk -> itr] = data;
}