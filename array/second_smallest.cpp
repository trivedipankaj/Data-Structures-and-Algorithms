/***
@author Pankaj Trivedi
@desc finding the second smallest in an array
*/

#include<iostream>
using namespace std;

int minimum(int a, int b){
    return a<b?a:b;    
}
int second_smallest(int a[],  int n){
       int  min =a[0]; int smin = a[0];
       for(int i=1; i<n; i++){
                min  = minimum(min,a[i]);
                if(a[i]>min && a[i]<smin){
                            smin = a[i];            
                }
       }
       return smin;    
}
main(){
       int a[] = {13,34,56,78,31,22,32,42,56,12};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<second_smallest(a,n);
       system("pause");

       }

