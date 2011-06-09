/**
@author Pankaj Trivedi
@desc Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1. 
@created June 9, 2011, 21:45 IST.
**/

#include<iostream>
#include<stack>
using namespace std;

void nextGreater(int a[], int n){
    stack<int> s;
    int curr,next;
    s.push(a[0]); /**first element into stack*/
    for(int i=1; i<n; i++){
            next = a[i]; 
            if(!s.empty()){
                 curr  = s.top();
                 s.pop();
                 while( curr < next){
                        cout<<curr<<"--->"<<next<<endl;
                        if(s.empty())
                          break;
                        curr  = s.top();
                        s.pop();
                 }
                 if(curr>next)
                  s.push(curr);
                  
            }
            s.push(next);
            
    }
     while(!s.empty()){
                    
                    curr = s.top();
                    s.pop();
                    next = -1;
                    cout<<curr<<"--->"<<next<<endl;
            }
         
}

main(){
  int arr[]= {34, 13, 21, 3,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreater(arr, n);
    getchar();
  }
