#pragma once


/* The basic data structure to implement a dinamic graph */


typedef struct node {

	int id;
	int state;	//extra data for search algorithms

}node;

node* createNode (int);


typedef struct edge {

	node* src;
	node* dst;
	void* data;  //extra flexable data for different uses	

}edge;


typedef struct snake {	//A growable polimorphic array

	int prev;	 //previus size
	int curr;	 //current size to know when to grow
	int itr;	 //iterator to know where to add 
	void** arr;	 //the actuall data

}snake;


snake* create_snake (int);

void addToSnake (snake*, void*);