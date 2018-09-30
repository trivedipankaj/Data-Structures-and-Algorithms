#include<iostream>
using namespace std;
/**
A string is K-Palindrome if it becomes a palindrome on removing at most k 
characters from it. Write an algorithm to check if a given string is K-Palindrome or not.
*/

int minPalindrome(string x, int m, string y, int n){
	if(m==0|| n==0) return m+n;
	if(x[m-1]  == y[n-1]) return minPalindrome(x,m-1,y,n-1);
	return 1+ min(minPalindrome(x,m-1,y,n), minPalindrome(x,m,y,n-1));
}

int main()
{
	
}