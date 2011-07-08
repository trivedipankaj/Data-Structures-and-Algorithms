/**
@author Pankaj Trivedi
@desc Write a C program that, given an array A[] of n numbers and another number x,
 determines whether or not there exist two elements in S whose sum is exactly x. 
@date 08-07-2011 21:35 IST
**/
#include<iostream>
#include<algorithm>
using namespace std;
bool map[1000];

bool is_sum(int a[], int s, int n){
           sort(a,a+n);
           int i=0,j=n-1;
           while(i<j){
                  int temp = a[i]+a[j];
                  if( temp == s) return true;
                  if( temp>s) j--;
                  else i++;                
           }
           return false;
}

bool is_sum_map(int a[],int s,int n){
     for(int i=0; i<n; i++){
             
             if(s-a[i]>=0 && map[s-a[i]])
               return true;
             else
              map[a[i]] = true;
     }
     return false;     
}
main(){
       int a[] ={4,6,1,8,12,40,15,13};
       int n = sizeof(a)/sizeof(a[0]);
       if(is_sum_map(a,20,n)){
             cout<<"Sum is found\n";
       }else{
             cout<<"Not found\n";
             }
             system("pause");
       }

