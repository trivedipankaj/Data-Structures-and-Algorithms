#include<iostream>
using namespace std;
#define M 4
#define N 4
/**
Given a M x N matrix where each cell have non-negative cost associated with it, 
count number of paths to reach last cell (M-1, N-1) of the matrix from its first 
cell (0, 0) such that path has given cost. We can only move one unit right or down from any cell. i.e. from cell (i, j), we can move to (i, j+1) or (i+1, j)
*/

int numWays(int a[][N], int m, int n, int cost){
	/***
	Base Case: If the cost is going out of bound, 
	means we did not find any exact match
	from this branch of recursion and there 
	is no way from this return 0
	*/
	if(cost < 0) return 0;
	/**
	Base Case: If we are down to the first cell,
	check we found an exact match with the cost,
	return one way if we did, else no way from this 
	branch
	*/
	if(m==0 && n==0){
		return a[0][0] - cost == 0;
	}
	int n1=0; int n2=0;
	/****
	Go left and up and recurse for
	the rest of the cost
	*/
	if(m-1>=0 && n>=0) n1 = numWays(a,m-1,n,cost-a[m][n]);
	if(m>=0 && n-1>=0) n2 = numWays(a,m,n-1,cost-a[m][n]);
	return n1+n2;
}

int main(){
    int a[M][N] = {{4,7,1,6},
					{5,7,3,9},
					{3,2,1,2},
					{7,1,6,3}};
    int cost = 25;
    int res = numWays(a,M-1,N-1,cost);
    cout<<res<<endl;
	return 0;
}