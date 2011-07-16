#include<iostream>
using namespace std;

int rotated_bs(int a[],int start,int end, int k){
	 if(start < end){
	   int mid = (start+end)/2;
	   if(a[mid] ==k) return mid;
	   if(a[start] <= a[mid]){
		if(a[mid] > k && k>=a[start])
		  return rotated_bs(a,start,mid-1,k);
		else
	         return rotated_bs(a,mid+1,end,k);
	   }else{
		if(a[mid] >k && k>=a[start])
		  return rotated_bs(a,mid+1,end,k);
	        else
		  return rotated_bs(a,start,mid-1,k);
	  }
	 }
	return -1;
}

main(){
	int a[] ={4,5,6,7,0,1,2,3};
	int n = sizeof(a)/sizeof(a[0]);
 	int k; 
	while(cin>>k && k!=-1){
		cout<<rotated_bs(a,0,n-1,k)<<endl;
	}
}
