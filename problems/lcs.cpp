#include<iostream>
#include<string>
using namespace std;

int lcs(string x, string y, int m, int n){
	if(m >= x.length() || n >= y.length()){
		return 0;
	}
	if(x[m] == y[n]){
		return 1 + lcs(x,y,m+1,n+1);
	}else{
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