#include<iostream>
using namespace std;
#define N 8

/***
The X,Y coordinates of the knight's next moves on the board
**/

int xMoves[] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMoves[] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 

/**
The possible safe positions for the placement of knight.
The coordinates should not lie beyond the board and the next
position should have not been visited
*/
bool isSafe(int a[][N], int r, int c){
	if(r >= 0 && r <N && c >=0 && c < N && a[r][c] == -1 ) return true;
	return false;
}

void print(int a[][N]){
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
/*
The recursive backtracking method to knight's tour
*/
bool tour(int a[][N], int r, int c, int moves ){
	/***
	if the knight has visited all the blocks of the board, if 
	we reach here, there is definitely a solution
	**/
	if(moves == N*N){
		print(a);
		return true;
	}
	
	/**
	There are maximum 8 possible ways for the knight to move from 
	a parituclar position on the board. Place the knight at the current location
	and recurse for all the possible positions
	*/
	for(int i=0; i<8;i++){

		if(isSafe(a,r,c)){
			a[r][c] = moves; //visit and place the move number
			if(tour(a,r+xMoves[i],c+yMoves[i],moves+1)){
				return true;
			}
			a[r][c] = -1; //backtrack
		}
	}

return false;
}


int main(){
	int a[N][N];
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			a[i][j] = -1;
		}
	}
	tour(a,0,0,0);
}
