/**
@author Pankaj Trivedi
@desc Given an array arr[], find the maximum j – i such that arr[j] > arr[i].
@created June 8, 2011, 21:24 IST.
**/
#include<iostream>
using namespace std;


int max(int a, int b){
    return a > b ? a :b;    
}
int min(int a, int b){
    return a > b ? b : a;
}

void printArr(int a[], int n){
     for(int i=0; i<n; i++)
        cout<<a[i]<<" "; 
        cout<<endl;    
}
int maxDistance(int a[],int n){
      int lmin[n],rmax[n];
      lmin[0]             = a[0];
      rmax[n-1]           = a[n-1]; 
      for(int i=1; i<n;i++){
              lmin[i] = min(a[i],lmin[i-1]);        
      }
      for(int i=n-2; i>=0; i--){
              rmax[i] = max(a[i],rmax[i+1]);
      } 
       
      int i=0,j=0,maxDiff=-1;
      while( i< n && j < n){
             if(lmin[i] < rmax[j]){
                       maxDiff = max(maxDiff, j-i);
                       j++;           
             }else{
                   i++;
             }     
      }
      return maxDiff; 
     
}

main(){
       int a[] = {34,8,10,3,2,80,30,33,1};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<maxDistance(a,n);
       system("pause");
       }
