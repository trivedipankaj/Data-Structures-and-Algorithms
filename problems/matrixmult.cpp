#include<iostream>
using namespace std;
/*
Given an array a[] which represents the chain of matrices such that the ith matrix Ai is of dimension a[i-1] x a[i]. 
We need to write a function minMatrix() that should return the minimum number of multiplications needed to multiply the chain.
**/

/**
 The index i and j represent the place of brackets in the chain
 if there are n matrices, n-1 paranthesis will be there.
*/
int minMatrix(int a[], int i, int j){
	/**
	if i and j are same, then it indicates only one matrix
	and hence the cost of multiplication is zero
	**/
	if(i-j >=0){
		return 0;
	}
	int m = INT_MAX;
	/**
	Try all the places recursively and find the minimum cost
	out of all possible places
	*/
	for(int k=i; k<j; k++){
		
		/*
		the cost of multiplying the matrix A[1..i] A[i...k], which 
		will be calculated recursively. This results into i x k matrix
		*/
		int cost = minMatrix(a,i,k);
		/*
		the cost of multiplying the matrix A[k+1] A[j], which 
		will be calculated recursively. This results into k x j matrix
		*/
		cost += minMatrix(a,k+1,j);

		/**
		the cost of multiplying (i x k) and (k x j) matricies
		*/
		cost += a[i-1]*a[k]*a[j];
		
		if(cost < m) m = cost;
	}
	return m;
}

int main(){
	int a[] ={10,30,5,60};
	int n=sizeof(a)/sizeof(a[0]);
	int res=minMatrix(a,1,n-1);
	cout<<res<<endl;
}