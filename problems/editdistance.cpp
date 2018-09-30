#include<iostream>
#include<string>
using namespace std;
/**
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1  into
‘str2 .
1. Insert 2. Remove 3. Replace
All of the above operations are of equal cost.
*/
int editd(string x, string y, int m, int n){
	/**
	End of any of the strings will result into the cost equals 
	to insertion of remaining characters in the other string.
	*/
	if(m==0 || n==0) return m+n;
	/**
	If the current characters are same, then no cost is
	required and hence recurse for the remaining strings
	*/
	if(x[m-1] == y[n-1]){
		return editd(x,y,m-1,n-1);
	}
	/*
	If current characters are not same, consider all three
   operations on current character of first string, recursively 
    compute minimum cost for all three operations and take // minimum of three values.	
	*/
	return 1+ min(min(editd(x,y,m-1,n-1), 
					editd(x,y,m,n-1)), 
					editd(x,y,m-1,n) );
}

int main(){
	string x,y;
	x = "sunday";
	y= "saturday";
	int res = editd(x,y,x.length(), y.length());
	cout<<res<<endl;
}