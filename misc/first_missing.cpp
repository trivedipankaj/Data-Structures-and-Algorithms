/**
@author Pankaj Trivedi
@desc Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. 
Find the smallest number that is missing from the array
@created June 9, 2011, 21:24 IST.
**/

#include<iostream>
using namespace std;

int findMissing(int low, int high, int a[]){
    if(low> high)
       return high+1;
    if( low != a[low])
        return low;
     int mid = (low+high)/2;
     if(a[mid] > mid)
      return findMissing(low,mid,a);
     else
      return findMissing(mid+1,high,a);     
}

main(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<findMissing( 0, n-1,arr);
  getchar();
  }
