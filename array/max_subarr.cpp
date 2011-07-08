/**
@author Pankaj Trivedi
@desc maximum subarray problem , Kadane's algorithm, if all numbers are negative it will return 0
@date 08-07-2011 22:51 IST
*/

#include<iostream>
using namespace std;

int max(int a, int b){
    return (a>b?a:b);    
}
 
int max_subarray(int a[], int n){
      int max_at_i=0; int max_now=0;
      for(int i=0; i<n;i++){
              max_at_i    = max(0,max_at_i+a[i]);  /*if the sum <0 better start from here again*/
              max_now     = max(max_now,max_at_i);        
      }
      return max_now;
}

main(){
       int a[] = {2, 1, -3, 4, -1, 2, 1, -5, 4};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<max_subarray(a,n);
       system("pause");
}

