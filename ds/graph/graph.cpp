/***
@author Pankaj Trivedi
@desc Adjacency List Implementation of Graph ADT.
@date 12-07-2011 01:10 IST.
*****/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 100

struct node{
	int data;
	node *next;
};

struct graph{
	node* vertex[SIZE];
	int verticies;
	int edges;
	bool directed;
};

graph* newGraph(bool directed){
	graph *g = new graph;
	for(int i=0; i<SIZE; i++) g->vertex[i] = NULL;
	g->verticies =0;
	g->edges     = 0;
	g->directed  = directed;
	return g;
}
node *newNode(int data){
	node *nn = new node;
	nn->data = data;
	nn->next = NULL;
	return nn;
}

int num_verticies(graph *g){
	return g->verticies;
}
int num_edges(graph *g){
	return g->edges;
}

void insertNode(graph *&g, int u){
	if(g->vertex[u] ==NULL){
	   g->vertex[u] = newNode(u);
	   g->verticies++;
	}
}

bool isEdge(graph *&g,int u, int v){
     if(g->vertex[u] == NULL || g->vertex[v] ==NULL) return false;
     node *t = g->vertex[u];
     if(t->next !=NULL) t = t->next;
     else return false;	
     while(t!=NULL){
	if(t->data == v) return true;
	  t = t->next;
     }
     return false;		
}

void insertEdge(graph *&g, int u, int v){
	if(u>=0 && v>=0 && u<SIZE && v<SIZE){
	    if(!isEdge(g,u,v) && (g->directed || u!=v )){	
		insertNode(g,u); 
		insertNode(g,v);
		node *temp = g->vertex[u];
		while(temp->next !=NULL) {
			temp = temp->next;
		}
		temp->next =newNode(v);
		if(!g->directed){
			node *t   = g->vertex[v];
			while(t->next !=NULL) t = t->next;
			t->next   = newNode(u);
		}
		g->edges++;
	 }
       }
}

void removeEdge(graph *&g, int u, int v){
	if(isEdge(g,u,v)){
	     node *t = g->vertex[u];
	     node *prev = t;
	     if(t->next!=NULL) t=t->next; 
	     else return;	
	     while(t->data !=v){
	         prev = t; 
		 t = t->next;
	     }
              prev->next = t->next;
	      free(t);
	     if(!g->directed){
		removeEdge(g,v,u);	
	     }
	}
}


node *getAdjacent(graph *g,int u){
	return g->vertex[u]->next;
}

void print_graph( graph *g){
	int i=0,j=0; int s = g->verticies; 
	while( i<SIZE && j<s){
	    if(g->vertex[i] !=NULL){
	        
		node *t = g->vertex[i];
	         	
		while(t!=NULL){
		   cout<<t->data<<" "; t = t->next;	
		}
		i++;j++; cout<<endl;
	    }else
		i++;
	}
}
main(){
	graph *g= newGraph(false);
	insertEdge(g,1,2);
	insertEdge(g,1,5);
	insertEdge(g,2,5);
	insertEdge(g,2,3);
	insertEdge(g,2,4);
	insertEdge(g,3,4);
	insertEdge(g,5,4);
	removeEdge(g,5,4);
        cout<<isEdge(g,2,1); cout<<endl;
	print_graph(g);	
}
