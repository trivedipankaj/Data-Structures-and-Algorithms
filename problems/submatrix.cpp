#include<iostream>
using namespace std;
#define M 6
#define N 5

int ma = INT_MIN;
/**
Find size of largest square sub-matrix of 1’s present in given binary matrix 
The size of largest square sub-matrix ending at a cell a[i][j] will be 1 plus minimum among largest square sub-matrix ending at a[i][j-1], a[i-1][j] and a[i-1][j-1]. 
The result will be the maximum of all square sub-matrix ending at a[i][j]for all possible values of i and j.
*/

int findMax(int a[M][N], int m, int n){
	if(m ==0 || n ==0) return a[m][n];

	//for [m-1,n]
	int top = findMax(a,m-1,n);
	// for [m,n-1]
	int left = findMax(a,m,n-1);
	int top_left = findMax(a,m-1,n-1);
	int size =0;

	/**
	if the current element is 1, 
	then only it will add the length of submatrix, otherwise size=0 will be returned
	for this subproblem
	*/
	if(a[m][n] ==1){
		 size = 1 + min(min(top,left),top_left);
	}
	ma = max(ma,size);

	return size;
}

int main(){
	int a[M][N] = {{0, 1, 1, 0, 1},  
                   {1, 1, 0, 1, 0},  
                   {0, 1, 1, 1, 0}, 
                   {1, 1, 1, 1, 0}, 
                   {1, 1, 1, 1, 1}, 
                   {0, 0, 0, 0, 0}
      }; 
      findMax(a,M,N);
      cout<<ma<<endl;
}