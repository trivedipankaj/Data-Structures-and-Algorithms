#include<iostream>
#include<string>
using namespace std;

int cnt=0;

/***
Swap the index of the string
*/
void swap(string &s, int i, int j){
	char t = s[i];
	s[i] = s[j];
	s[j] = t;
}

void permute(string s, int l, int r){
	/*
	The pointer for swapping has come to the end of the string
	so the swapping is done and now it is time to print the final
	string, which will result into one of the permutations
	**/
	if(r == s.length()){
		cout<<s<<endl;
		cnt++;
		return;
	}
	/**
	Start from the current pointer to the end of the string, swap the current string with rest of the 
	characters in the string and recurse.
	*/
	for(int i=r; i<s.length(); i++){
		swap(s,i,r);
		permute(s,i,r+1);
		//backtrack
		swap(s,r,i);
	}

}

int main(){
	string s="ABCDE";
	permute(s,0,0);
	cout<<"Total permutations:"<<cnt<<endl;
}