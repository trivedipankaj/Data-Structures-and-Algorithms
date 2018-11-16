#include<iostream>
using namespace std;
#define N 5
#define M 5

int cache[M][N];
/**
Memoized version recursive solution for calculating minimum cost for reaching to topmost point from (0,0)
*/
int minCost(int a[][N], int m, int n){

	if(m< 0 || n <0){ 
		return INT_MAX;
	}
	if(m==0 && n==0) {
		cache[m][n] =a[0][0];
		return cache[m][n];
	}

	if(cache[m][n] != -1){
		return cache[m][n];
	}

	int cost = min(minCost(a,m-1,n), minCost(a,m,n-1)) + a[m][n];
	cache[m][n] = cost;
	return cost;
}

void print(){
	for(int i=0; i<M;i++){
		for(int j=0; j<N; j++){
			cout<<cache[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	memset(cache, -1, sizeof(cache[0][0]) * M * N);

	int a[M][N] = {
		{4,7,8,6,4},
		{6,7,3,9,2},
		{3,8,1,2,4},
		{7,1,7,3,7},
		{2,9,8,9,3},
	};
	int res = minCost(a,M-1, N-1);
	cout<<res<<endl;
	print();
}