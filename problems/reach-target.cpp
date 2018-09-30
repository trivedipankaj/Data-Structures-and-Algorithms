#include<iostream>
#include<list>
using namespace std;

/**
Write a program to count number of ways to calculate a target number from elements of specified 
array by using only addition and subtraction operator. 
The use of any other operator is forbidden. For example, 
consider the array { 5, 3, -6, 2 }. The number of ways to reach a target of 6 using only + and - operators is 4.
*/
int countWays(int a[], int n, int target){
	/**
	Base Case: The target is reached so we have found one way
	*/
	if(target ==0) return 1;
	/**
	Base case: No elements left
	*/
	if(n < 0) return 0;
	/**
	Exclude this item from the result set and recurse for the
	rest of the array items, this will fetch some ways from 
	further branching
	*/
	int exclude = countWays(a,n-1,target);
	/**
	Include this item as part of result and hence try adding and subtracting
	this item in the target
	*/
	int include = countWays(a,n-1,target-a[n]) + countWays(a,n-1,target+a[n]);
	return include+exclude;
}

void printList(list<pair<int,char>> const& list){
	for(auto i: list){
		cout<<"("<<i.second<<")"<<i.first<<" ";
	}
	cout<<endl;
}

void printWays(int a[], int n, int sum, int target, list<pair<int,char>> &list){
	/*
	Base Case: Reached to the destination, now print the content 
	of the list which is the path to reach here.
	**/
	if(sum == target){
		printList(list);
		return;
	}
	if(n < 0){ return ;}

	/**
	Exclude this element so that it can result into further
	branching.
	*/
	printWays(a,n-1,sum,target,list);

	/**
	Add this decision to go with the addition into the list
	which will reflect into the final path list.
	Then recurse with the addition 
	*/
	list.push_back({a[n],'+'});
	printWays(a,n-1,sum + a[n], target, list);
	list.pop_back(); //backtrack

	/**
	Add this decision to go with the subtraction into the list
	which will reflect into the final path list.
	Then recurse with the subtraction 
	*/
	list.push_back({a[n],'-'});
	printWays(a,n-1, sum-a[n], target, list);
	list.pop_back(); //backtrack
}


int main(){
	int a[] ={5,3,-6,2};
	int n = sizeof(a)/sizeof(a[0]);
	int target =6;
	int res = countWays(a,n,target);
	cout<<res<<endl;
	list<pair<int,char>> list;
	printWays(a,n,0,6,list);

}