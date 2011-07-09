/***
@author Pankaj Trivedi
@desc searching for an element in pivoted sorted array
@date 09-07-2011 12:49 IST
*/

#include<iostream>
using namespace std;
int find_pivot(int a[], int n, int start, int end);

int binary_search(int a[], int n, int k, int start, int end){
          if( start<=end){
              int mid = (start+end)/2;
               if( a[mid] ==k) return mid;
               if(a[mid] > k )  return binary_search(a,n,k,start,mid-1);
               else return binary_search(a,n,k,mid+1,end);                 
          }
          return -1;   
}
int find_pivot(int a[], int n, int start, int end){
            if(start <=end){
                     int mid = (start+end)/2;
                     if(a[mid] > a[mid+1]) return mid;
                     if(a[start] > a[mid]) return find_pivot(a,n,start,mid-1);
                     else return find_pivot(a,n,mid+1,end);
             }
             return -1;           
}
int pivoted_bs(int a[], int n, int k){
                int p = find_pivot(a,n,0,n-1);
                if(a[p] ==k) return p;
                if(a[0] <= k) return binary_search(a,n,k,0,p-1);
                else return binary_search(a,n,k,p+1,n-1);       
}

main(){
       int a[] = {56,78,90,123,456,678,1,2,3,4};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<pivoted_bs(a,n,4);
       //cout<<find_pivot(a,n,0,n-1);
       system("pause");
       }

