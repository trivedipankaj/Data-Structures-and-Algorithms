#include<iostream>
#include<string>
using namespace std;
/**
Recursive solution to LCS problem
*/
int lcs(string x, string y, int m, int n){
	/*
	Base Case: If any of the strings is reached to end, there will be no
	more addition in LCS length.
	*/
	if(m >= x.length() || n >= y.length()){
		return 0;
	}
	/**
	Case 1: if the current characters are same, increment the length and 
	recurse for the reamining strings
	*/
	if(x[m] == y[n]){
		return 1 + lcs(x,y,m+1,n+1);
	}else{
		/**
		Case 2: If the current characters are different, take the maximum of 
		remaining two strings
		*/
		return max(lcs(x,y,m,n+1), lcs(x,y,m+1,n));
	}

}

int main(){
	string x,y;
	x = "XMJYAUZ";
	y = "MZJAWXU";
	int res = lcs(x,y,0,0);
	cout<<res<<endl;
}