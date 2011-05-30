#include<iostream>
using namespace std;

int fbsearch(int a[], int low, int high,int n){
       int mid = (low+high)/2;
        if(low>high)
          return -1;
	if(a[mid] == n && (mid ==0 || n > a[mid-1]))
          return mid;
        else if( a[mid] < n)
	  return fbsearch(a,mid+1,high,n);
         else
          return fbsearch(a,low,mid-1,n);
         
          
} 

int lbsearch(int a[], int low, int high, int n){
	 int mid = (low+high)/2;
         if(low > high){
		return -1;
	 }
         if(	(a[mid] == n)  && ( mid ==n || n < a[mid+1]))
              return mid;
         else if( a[mid] > n)
             return lbsearch(a,low,mid-1,n);
         else 
             return lbsearch(a,mid+1,high,n);
      
}

main(){
	int a[] = {2,5,6,7,9,11,34};
        int low=0, high,n;
        int f,l;
        n=12;
        high = (sizeof(a)/sizeof(int))-1;
	f = fbsearch(a,low,high,n);
        l = lbsearch(a,low,high,n);
        if(f == -1){
		cout<<f;
	}else{
		cout<<(l-f+1);
	}
}
