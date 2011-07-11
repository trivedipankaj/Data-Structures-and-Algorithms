/**
@author Pankaj Trivedi
@desc Adacency Matrix implementation of Graph ADT. A little buggy though ;) 
     number of verticies are not caculated, TODO
@date 12-07-2011 02:08 IST
***/

#include<iostream>
using namespace std;
#define SIZE 10
typedef bool DT;
struct graph{
	DT v[SIZE][SIZE];
	int verticies;
	int edges;
	bool directed;
};

graph *newGraph(bool directed){
	graph *g = new graph;
	for(int i=0; i<SIZE; i++)
             for(int j=0; j<SIZE; j++) 
		  g->v[i][j] = 0;
        g->verticies =0;
	g->edges     = 0;
	g->directed  = directed;
	return g;
}

int num_verticies(graph *g){
	return g->verticies;
} 

int num_edges(graph *g){
	return g->edges;
}

bool isDirected(graph *g){
	return g->directed;
}

bool isEdge(graph *g, int u, int v){
	return g->v[u][v];
}

void insertEdge(graph *&g, int u, int v){
	if(!isEdge(g,u,v)){
	g->v[u][v] = 1;
        if(!g->directed)
          g->v[v][u] =1;
	 g->edges++;
	}
}

void removeEdge(graph *&g, int u, int v){
	if(isEdge(g,u,v)){
	g->v[u][v] =0;
	if(!g->directed)
          g->v[v][u]=0;
	g->edges--;
	}
}
void print_graph(graph *g){
	for(int i=0; i<SIZE; i++){
		cout<<i<<" : ";
		for(int j=0; j<SIZE; j++){
			if(g->v[i][j]!=0)
			   cout<<j<<" ";	
		}
		cout<<endl;
	}
}
main(){
        graph *g = newGraph(false);
         insertEdge(g,1,2);
	 insertEdge(g,1,5);
	insertEdge(g,2,5);
	insertEdge(g,2,3);
	insertEdge(g,2,4);
	insertEdge(g,3,4);
	insertEdge(g,5,4);
	//removeEdge(g,5,4);
	print_graph(g);
}
