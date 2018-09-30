#include<iostream>
#include<vector>
using namespace std;

/******
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

void print(vector<int> v){
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void combinations(int a[],int n, int target, int pos,  vector<int> v){
	if(target ==0){
		print(v);
		return;
	}
	if(target < 0){
		return;
	}
	/**
	Since the repeatation of the elements is allowed
	*/
	for(int i=pos; i<n;i++){
		v.push_back(a[i]);
		combinations(a,n, target-a[i],i,v);
		v.pop_back();
	}
}


int main(){
	int a[] ={2,3,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	vector<int> v;
	int target =7;
	combinations(a,n,target,0,v);

}
