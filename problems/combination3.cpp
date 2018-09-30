/****
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:

For example, given candidate set 10,2,7,6,1,5 and target 8, Assume that there are no duplicates in the input.
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void combinations(int a[],int n, int target,  vector<int> v){
	/**
	Base Case: when the target is met, print the list
	*/
	if(target ==0){
		print(v);
		return;
	}
	if(target < 0 || n<=0){
		return;
	}
	/**
	Don't include the item in the list and recurse for the reamining 
	elements.
	*/
	combinations(a,n-1,target, v);
	/*
	Include the item in the list and recurse for the remaining 
	elements.
	*/
	v.push_back(a[n-1]);
	combinations(a,n-1,target-a[n-1],v);
	v.pop_back(); //backtrack
	
}


int main(){
	int a[] ={10,1,2,7,6,5};
	int n=sizeof(a)/sizeof(a[0]);
	vector<int> v;
	int target =8;
	combinations(a,n,target,v);

}