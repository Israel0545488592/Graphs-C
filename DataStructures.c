#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "DataStrucrures.h"


snake* create_snake (int init_size){

	snake* snk = (snake*) malloc(sizeof(snake));
	if (! snk){ return NULL;}

	snk -> arr = (void**) malloc(sizeof(void*) * init_size);
	if (! snk -> arr){ return NULL;}

	snk -> prev = 0;
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

	snk -> itr++;				//appending if all gone well
	snk -> arr[snk -> itr] = data;
	snk -> prev++;
}