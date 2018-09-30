#include<iostream>

using namespace std;
/**
The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence&#8217;s 
elements are in sorted order, lowest to highest, 
and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique
*/
int solve(int a[], int n, int i, int prev){
	/**
	if there are no more elements, return 0
	*/
	if(i==n) return 0;

	/**
	Case 1: Exclude the current item from the sequence and recurse
	for the rest of the elements to find out more possibilites.
	*/
	int exc = solve(a,n,i+1, a[i]);

	/****
	In the case when it does not have prev element less than the current,
	the included length is 0
	*/
	int inc =0;

	/**
	Case 2: Include the current element in the LIS if the previous element is 
	less than the current element (that is how the longest increasing subsequence will be formed)
	*/
	if(a[i] > prev){
		inc = 1+ solve(a,n,i+1,a[i]);
	}
	/**
	Take the maximum of the two cases
	**/
	return max(inc,exc);
}

int LIS(int a[], int n){
	int dp[n];
	for (int i=0; i<n; i++) dp[i] =0;
	dp[0]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i], 1+dp[j]);
			}

		}

	}
	int m = INT_MIN;
	for(int i=0; i<n;i++){
		m = max(m,dp[i]);
	}
	return m;
}

int main(){
	int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n= sizeof(a)/sizeof(a[0]);
	int res =solve(a,n,0,INT_MIN);
	int lis = LIS(a,n);
	cout<<res<<endl;
	cout<<lis<<endl;
}
