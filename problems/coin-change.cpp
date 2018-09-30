#include<iostream>
#include <unordered_map>
 using namespace std;
 unordered_map <string,int> cache;

/*
Coin Change Problem: Given an unlimited supply of coins of given denominations, 
find the total number of distinct ways to get a desired change
TOP DOWN recursive solution. 
*/
int countWays(int a[], int n, int S){
	//if total is 0, there is one way, solution is 
	// found so you can stop and return 1
	if(S == 0) return 1;
	/*
	if the total becomes negative or there are no more 
	elements left, then there is no solution
	*/
	if(n<0 || S <0) return 0;
	/*
	for every element, either the element is the part of solution
	or it is not the part of solution. The answer is addition of 
	both types.
	Case 1: Include the element in the solution and recurse for rest of the total
	with the same number of elements.

	Case 2: Exclude the element and recurse with the same total with that element excluded.
	*/
	return countWays(a,n,S-a[n]) + countWays(a,n-1,S);
}
/*
 Memoized solution
*/
int countWaysMemo(int a[], int n, int S){
	//if total is 0, there is one way, solution is 
	// found so you can stop and return 1
	if(S == 0) return 1;
	/*
	if the total becomes negative or there are no more 
	elements left, then there is no solution
	*/
	if(n<0 || S <0) return 0;

	//create a key for the subproblem so that the result of subproblem can be stored
	string key= to_string(n)+ "|" + to_string(S);

	/*
	if the result is not found in the cache, calculate it.
	and save it for future reference.
	*/
	if(cache.find(key) == cache.end()){
		 cache[key] = countWays(a,n,S-a[n]) + countWays(a,n-1,S);
	}
	/*
	return the solution of the current subproblem
	*/
	return cache[key];
}

void print(int a[], int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

/*
Bottom up approach
*/
int countWaysBU(int a[],int n, int S){
	int dp[S+1];
	for(int i=0; i<=S;i++) dp[i]=0;
	dp[0]=1;
	/*
	Every coin indicates one stage of bottom up approach.
	we go one coin at a time and construct the table with 
	number of coins for each value [1....S]
	*/
	for(int i=0; i<n;i++){
		for(int j=a[i]; j<=S;j++){
			dp[j] += dp[j-a[i]];
		}
	}
	return dp[S];
}



int main(){
	int a[] ={1,2,3};
	int S=4;
	int n = sizeof(a)/sizeof(a[0]);
	
	int res = countWays(a,n-1,S);
	cout<<res<<endl;
	int mres = countWaysMemo(a,n-1,S);
	cout<<mres<<endl;
	int bu = countWaysBU(a,n,S);
	cout<<bu<<endl;
}
