/**
@author Pankaj Trivedi
@desc Given an array of positive integers. All numbers occur even number of times except one number which
occurs odd number of times. Find the number in O(n) time & constant space
@date 08-07-2011 22:51 IST
*/

#include<iostream>
using namespace std;

int odd_occur(int a[],int n){
    int res = a[0];
    for(int i=1; i<n;i++)
        res ^=a[i];
    return res;
}

main(){
       int a[] = {4,5,5,4,3,2,2,3,5};
       int n = sizeof(a)/sizeof(a[0]);
       cout<<odd_occur(a,n);
       system("pause");
}

