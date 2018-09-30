#include<iostream>
#include <unordered_map>
 using namespace std;
 unordered_map <string,int> cache;

int minCoins(int a[], int n, int S){
	if(S <= 0 ) return 0;

	int min = INT_MAX;
	for(int i=0; i<n;i++){
		int coins = 1+ minCoins(a,n,S-a[i]);
		if( coins < min) min = coins;
	}
	return min;
}


 int main(){
	int a[] ={1,2,3};
	int S=7;
    int n = sizeof(a)/sizeof(a[0]);
	int mc = minCoins(a,n,S);
	cout<<mc<<endl;
}