#include<iostream>
using namespace std;
#define M 5
#define N 5
/**

Given a N x N matrix where each cell has distinct value in the 1 to N * N. Find the longest sequence formed by adjacent 
numbers in the matrix such that for each number, the number on the adjacent neighbor is +1 its value.
Just find the length of such a sequence
*/
int longestSeq(int a[][N], int m, int n){
	if(m >=M || m < 0 ) return 0;
	if (n>=N || n<0 ) return 0;
	int result=1;
	if(m>0 && a[m][n]  == a[m-1][n] +1){
			result =  1 + longestSeq(a,m-1,n);
	}
	if(n>0 && a[m][n] == a[m][n-1] +1 ){
		result = max(result, 1+longestSeq(a,m,n-1));
	}
	if(m+1 < M && a[m][n] == a[m+1][n]+1){
		result = max(result, 1 + longestSeq(a,m+1,n));
	}
	if(n+1 < N && a[m][n] == a[m][n+1]+1){
		result = max(result,1+longestSeq(a,m,n+1));
	}
	return result;
}


int main(){
	int a[M][N] = {{10,14,12,14,15},
					{14,11,12,13,16},
					{10,11,12,13,17},
					{10,11,12,13,14},
					{10,11,12,144,14},
				};


	int res = longestSeq(a,M-1,N-1);
	int m =INT_MIN;
	for(int i=0; i<M; i++){
		for(int j=0; j< N; j++){
			 m = max(m, longestSeq(a,i,j));	
		}
	}
	cout<<m<<endl;
}