#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void superSet(int a[], int n, vector<int> v){
	/**
	Base Case: If there are no more element in the list
	then print the list
	DONT forget to return from the base case
	*/
	if(n <=0){
		print(v);
		return;
	}
	/*
	consider the current element into the set and
	recurse for the remaining elements
	*/
	v.push_back(a[n-1]);
	superSet(a,n-1, v);

	/**
	Don't consider the current element and recurse for the
	remaining elements
	*/
	v.pop_back();
	superSet(a,n-1,v);

}

int main(){
	int a[] ={1,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	vector<int> v;
	superSet(a,n,v);

}



