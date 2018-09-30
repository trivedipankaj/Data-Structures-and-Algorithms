#include<iostream>
using namespace std;
#define V 4

/**
Check if it is safe to color the current node with the given color
check for the adjacent nodes to see if any node has the same color
*/
bool isSafe(int g[][V], int v, int colors[],int color){
	for(int i=0; i<V;i++){
		if(g[v][i] ==1 && colors[i] == color){
			return false;
		}
	}
return true;
}
/*
Print color of each node
*/
void print(int g[][V],int colors[]){
	for(int i=0; i<V;i++){
		cout<<colors[i]<<" ";
	}
	cout<<endl;
}
/**

*/
bool solve(int g[][V], int m, int colors[], int v){
	//all the nodes are traversed, if we reach here, there is definitely 
	// a solution, print the colors here
	if(v == V){
		print(g,colors);
		return true;
	}
	/**
	Try all the colors
	*/
	for(int i=1;i <= m ;i++){
		if(isSafe(g,v,colors,i)){
		colors[v] = i;
		if(solve(g,m,colors,v+1)) return true;
		colors[v] = 0; //backtrack
	 }
   }
	return false;
}

int main(){
	int colors[]= {};
	int g[V][V] =  {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m=3;
	for(int i=0; i<V;i++) colors[i] = 0;
	solve(g,m,colors,0);
	return 0;
}