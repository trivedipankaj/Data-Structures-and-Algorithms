#include<iostream>
using namespace std;
#define N 9

/*
Check if the number to be placed in present in the current row
*/
bool checkRow(int a[][N], int c, int num){
	for(int i=0; i<N;i++)
		if(a[i][c] == num) return true;
	return false;
}
/*
check if the number to be placed is present in the current column
*/
bool checkCol(int a[][N], int r, int num){
	for(int i=0; i<N;i++)
		if(a[r][i] == num) return true;
	return false;
}
/*
check if the number to be placed is present in the current box
*/
bool checkBox(int a[][N], int r, int c, int num){
	int x = (r/3) * 3;
	int y = (c/3) * 3;
	for(int i=x; i<x+3; i++){
		for(int j=y; j<y+3; j++){
			if(a[i][j] == num) return true;
		}
	}
	return false;
}
/*
If there are any unassinged numbers, set such a number to row and col
so that the numbers from 1...N can be tried upon that
*/
bool findUnAssigned(int a[][N], int &row, int &col){
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++){
			if(a[i][j] == 0) {
				row = i; col =j;
				return true;
			}
		}
	}
	return false;
}
/*
 Returns true if it is safe to place the number on the block depending on the contraints
 for row, column and the box
**/
bool isSafe(int a[][N], int r, int c, int num){
	return !checkRow(a,c,num) && !checkCol(a,r,num) && !checkBox(a,r,c,num);
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

bool solve(int a[][N]){
	int row, col;
	/*
	Base Case: Print the solution if there are no more unassinged cells
	*/
	if(!findUnAssigned(a,row,col)){
		print(a);
		return true;
	}
	/**
	Try all the numebers from 1..N on the current cell and
	recurse for the reamining. 
	*/
	for(int i=1; i<=N; i++){
		if(isSafe(a,row,col,i)){
			//place the number on the current cell
			a[row][col] = i;
			//since we have found a solution, just stop, don't try for another solution
			if(solve(a)) return true;
			a[row][col] =0; //backtrack
		}
	}
	return false; //triggers backtracking, because attempt to find a solution has failed, new combination will be tried by backtracking
}

int main(){
	int a[N][N] = {{3, 0, 0, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
      solve(a);


}