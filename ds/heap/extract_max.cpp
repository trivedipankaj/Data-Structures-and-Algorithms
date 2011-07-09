/***
@author Pankaj Trivedi
@desc Heap Sort/ Max Heapfiy/ Build Heap
*/

#include<iostream>
using namespace std;
void print_array(int a[], int n);
void swap(int &a, int &b){
     int temp = a;
     a = b;
     b = temp;     
} 


void max_heapify(int a[], int n, int i){
         int left  = 2*i;
         int right = 2*i+1;
         int largest;
         if(left <n && a[left] > a[i])                 
                 largest = left;
         else   largest = i;
         if(right<n && a[right]>a[largest])
                 largest = right;
         if(i!=largest){
            swap(a[i],a[largest]);
            max_heapify(a,n,largest);
         }      
}
void build_heap(int a[], int n){
           int s = n/2;
           for(int j=s; j>=1; j--)
                   max_heapify(a,n,j);
               
}

int extract_max(int a[], int n){
     build_heap(a,n); /*only if heap is not already built*/
     int max = a[1];
     a[1]   = a[n-1];
     max_heapify(a,n-1,1);
     return max;    
}

void print_array(int a[], int n){
       for(int i=0; i<n; i++)
          cout<<a[i]<<" ";
          cout<<endl;     
}

main(){
       int a[] ={0,34,56,36,32,90,78,43};
       int n = sizeof(a)/sizeof(a[0]);
       //max_heapify(a,n-1,1);
       //heapsort(a,n-1);
       cout<<extract_max(a,n); cout<<endl;
       print_array(a,n); 
       system("pause");
       }

