#include<iostream>
using namespace std;

void my_union( int a[], int b[], int n, int m){
	int i=0,j=0,prev;
        while( i<n && j<m ){
	    if(a[i] < b[j])
                cout<<a[i++]<<" ";
	    else if(a[i] > b[j])
                cout<<b[j++]<<" ";
            else{
		if(a[i] != prev)
			cout<<a[i]<<" ";
		prev = a[i];
                i++;j++;
		} 
               		
	}
while(i<n){
	cout<<a[i++]<<" ";
}
while(j<m){
	cout<<b[j++]<<" ";
}

}

void my_intersect(int a[], int b[], int n, int m){
	int i=0; int j=0,prev;
	while(i<n && j<m){
	if(a[i] < b[j])
		i++;
        if(a[i] > b[j])
                j++;  
	if(a[i] == b[j]){
		if(a[i] != prev)
			cout<<a[i]<<" ";
		prev = a[i];	
                i++;j++;
	  }	
	}

}

main(){
	int a[] = {2,2,2,5,8};
        int b[] = {1,2,2,2,3,4,5,6,7,8};
        
        int n = sizeof(a) / sizeof(int);
        int m = sizeof(b) /sizeof(int);
        cout<<"union is=";
        my_union(a,b,n,m);
       cout<<endl<<"intersection is=";
        my_intersect(a,b,n,m);
 	cout<<endl;

}
