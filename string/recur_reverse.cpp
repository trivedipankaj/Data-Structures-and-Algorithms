#include<iostream>
using namespace std;

void print_reverse( char *s){
	if(*s){
	   print_reverse((s+1));
	   cout<<*s;
	}
}
main(){
	char s[70];
	cin>>s;
	print_reverse(s);
	cout<<endl;
}
