/**
@author Pankaj Trivedi
@desc A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).
function which takes an array and emits the majority element (if it exists), otherwise prints 
*/

#include<iostream>
using namespace std;

int majority_element(int a[], int n){
           int e =a[0]; int cnt=1;
           for(int i=1; i<n;i++){
                  if(a[i] == e){
                          cnt++;
                  }else{
                        cnt--;
                        if(cnt ==0){
                               e=a[i];
                               cnt=1;
                        }
                                 
                  }         
           }
           /**the element with majority is e*/
          cnt =0;
          for(int i=0; i<n; i++){
                 if(a[i] ==e) cnt++; 
          } 
          if(cnt >=n/2)
             return e;
          else
             return -1; 
                    
}

main(){
       int a[] = {3,4,2,2,6,2,2,3,2,2};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<majority_element(a,n);
       system("pause");
       }

