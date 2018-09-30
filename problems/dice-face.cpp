#include<iostream>
using namespace std;
/*
Calculate the numer of ways to achieve a desired sum by using n throws of a dice with k faces.
*/
int ways(int k, int n, int sum){
	/**
	if there are no throws left, if sum is also zero then there is ONE way and 
	if the sum is NON ZERO there is no way to achieve that.
	*/
	if(n==0) return sum == 0;

	/*
	The desired sum can never be reached in such 
	configurations
	*/
	if(sum <0 || k * n < sum || n> sum){
		return 0;
	}
	int res=0;
	/**
	Recurse for all the possible solutions.
	*/
	for(int i=1; i<=k; i++){
		res += ways(k,n-1,sum-i);
	}
	return res;
}


int main(){
	int n=2; int k=6; int sum=10;
	int res = ways(k,n,sum);
	cout<<res<<endl;

}