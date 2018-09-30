#include<iostream>
using namespace std;
/**
Simple recursive idea is to try cutting the rod for every
length and recurse it for smaller rod
**/

int cutRod(int price[], int n){
	//this is the base case, if there is no length, there is no price
	if(n == 0) return 0;

	int mx = INT_MIN;
	/*
	Partition the rod one by one for every interation and calculate the price
	for each combination and take the maximum price
	*/
	for(int i=1; i<=n;i++){
		
		int cost = price[i-1] + cutRod(price, n-i);
		if( cost > mx) mx =cost;
	}
	return mx;
}

int main(){
	int length[] ={};
	int price[] ={1,5,8,9,10,17,17,20};
	int n = 4;
	int cost = cutRod(price,n);
	cout<<cost<<endl;

}