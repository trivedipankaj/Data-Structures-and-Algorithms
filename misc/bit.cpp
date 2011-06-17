#include<iostream>
using namespace std;
int no_of_bits(int a);
int bitSwap(int a, int b){
	int c = a^b;   //if the bits are different, then C is set
        return no_of_bits(c);
        
}
int no_of_bits(int a){
	int count =0; 
        while(a ){
	  a = a & (a-1);
          count++;
	}
return count;	
}

main(){
	int a,b;
        cin>>a>>b;
	cout<<bitSwap(a,b);
}
