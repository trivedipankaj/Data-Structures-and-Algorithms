#include<iostream>
using namespace std;
#define N 8
/***
Print the arrangement of queens on the NXN board
*/
void print(int a[][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(a[i][j] ==1){
				cout<<"Q ";
			}else{
				cout<<". ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
/**
Check if the placing a queen at row, col on the board is safe
i.e. no queens are attacking at this position
*/
bool isSafe(int a[][N], int row, int col){
	/*
	check for all the columns for the given row,
	as the queens can not be in the same column
	*/
	for(int i=0; i<N;i++){
		if(a[row][i] ==1) return false;
	}
	/**
	check for all the rows for given column as the
	queens can not be in the same row
	*/
	for(int i=0; i<N;i++){
		if(a[i][col] ==1) return false;
	}
	/***
	check for the queens along the diagonals as the queens 
	can not be in the diagonal 
	*/

	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			if(abs(row-i) == abs(col-j) && a[i][j] ==1){
				return false;
			}
		}
	}
	return true;
}

void nqueens(int a[][N], int row){
		/***
		if we are done inspecting all the rows by finding safe columns for each row
		then we are done placing queens at the right places, if we reach here there 
		is a solution, so print the solution.
		*/
		if(row == N){
			print(a);
			return;
		}

		/***
		Try for all the columns for the current row, if there is safe place for queen to 
		be placed at a column, then place the queen there and recurse for the rest of the rows.
		This will print all the solutions of the NQUEENS as we are not stopping by finding a solution
		*/
		for(int i=0; i<N; i++){
			if(isSafe(a,row,i)){
				
				//place the queen at this location as it is safe 
				a[row][i] = 1;

				nqueens(a,row+1);
				//backtrack, in case this does not fetch into result, this location can be tried again by 
				//some other branch of recursion
				a[row][i] =0;
			}
		}

}

int main(){
	int a[N][N];
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			a[i][j] =0;
		}
	}
	//print(a);
	nqueens(a,0);

}
