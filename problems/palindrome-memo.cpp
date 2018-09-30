#include<iostream>
using namespace std;

//function to check if the string S[i...j] is a palindrome or not
bool isPalindrome(string S, int i, int j){
	while(i<=j){
		if(S[i++] != S[j--]) return false;
	}
	return true;
}

/*Returns the minimum number of cuts required for the string S[i..j]
  so that each string obtained after cuts is a palindrome. This is a
  brute force solution for finding such cuts. We will later see how
  this results into overlapping subproblems and the same subproblems
  are being computed over and over again. 
*/
int minPalindorme(string S, int i, int j){
	//the base case where i and j become equal
	
	if(i == j) return 0;
	if(isPalindrome(S,i,j)) return 0;

	int min = INT_MAX;
    /*
	The string is cut at every index between i and j and the minimum cuts
	are calculated, we pick the minimum of all of these.
    */
	for(int k=i; k<=j-1; k++){
		int cnt = 1 + minPalindorme(S,i,k) + minPalindorme(S,k+1,j);
		if( cnt < min) min =cnt;
	}
	return min;
}

int main(){
	string S="BCDABBA";
	int n = S.length();
	int res = minPalindorme(S,0,n-1);
	cout<<res;

}