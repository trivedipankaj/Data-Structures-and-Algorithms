#include<string>
#include<iostream>
using namespace std;
/**
Given three strings A, B and C. Write a function that checks 
whether C is an interleaving of A and B. C is said to be interleaving 
A and B, if it contains all characters of A and B and order of all 
characters in individual strings is preserved.
**/
bool interleaved(string x, string y, string s){
	/**
	If X , Y and S all are empty, the strings are interleaved
	*/
	if(!x.length() && !y.length() && !s.length()){
		return true;
	}
	/**
	If S is empty and X and Y are not, then the strings don't interleaved.
	*/
	if(!s.length()){
		return false;
	}
	/**
	if the string x is not empty and the first character of x matches with the first
	character of the string s, then recurse for the rest of the string x and s
	**/
	bool a = (x.length() && x[0] ==s[0] && interleaved(x.substr(1),y,s.substr(1)));

	/**
	if the string y is not empty and the first character of y matches with the first
	character of the string s, then recurse for the rest of the string y and s
	**/
	bool b = (y.length() && y[0] ==s[0] && interleaved(x,y.substr(1),s.substr(1)));
	/**
	if any of the two satisy the it is interleaving
	*/
	return a || b;
}

int main(){
	string x="ABC";
	string y="DEF";
	string s="ABXDCEF";
	if(interleaved(x,y,s)){
		cout<<"Interleaved!"<<endl;
	}else{
		cout<<"Not Interleaved!"<<endl;
	}
}