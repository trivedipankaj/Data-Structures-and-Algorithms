#include<iostream>
using namespace std;
/*
The maximum subarray problem is the task of finding the contiguous subarray 
within a one-dimensional array of numbers which has the largest sum.
*/
int solve(int a[], int n){
	int dp[n];
	dp[0] = a[0];

	for(int i=1; i<n;i++){
		dp[i] = max(dp[i-1]+a[i], a[i]);
	}
	return dp[n-1];
}


int main(){
	int a[] = { 1, 2, -3, -4, 2, 7, -2, 3 };
	int n= sizeof(a)/sizeof(a[0]);
	int res =solve(a,n);
	cout<<res<<endl;
}


