#include<iostream>
using namespace std;

int knapsack(int w[], int v[], int W, int n){
	/**
	Base Case: Negative capacity, return the minimum possible value
	**/
	if(W < 0) return INT_MIN;
	/**
	Base Case: There are no more elements or the Weight becomes zero, no value is added in this case
	*/
	if(n<0 || W==0) return 0;

	/**
	Include the current item in the knapsack and recurse for the remaining elements
	The total value after including this item will be the value of this item + the value 
	of remaining items.
	**/
	int include = v[n] + knapsack(w,v,W-w[n],n-1);

	/**
	Exclude the current item and recurse for the remaining items so that this case can
	branch out into many other possibilities. The value after excluding this item will not change
	**/ 
	int exclude = knapsack(w,v,W,n-1);

	return max(include,exclude);
}

int main(){
	int v[] ={20,5,10,40,15,25};
	int w[] ={1,2,3,8,7,4};
	int W=10;
	int n= sizeof(w)/sizeof(w[0]);
	int res = knapsack(w,v,W,n-1);
	cout<<res<<endl;

}