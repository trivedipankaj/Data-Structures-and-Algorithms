#include<iostream>
using namespace std;
int partition(int a[], int l, int r);

void swap(int &a, int &b){
     int temp = a;
     a     = b;
     b     = temp;
}

void quick_sort(int a[], int l, int r){
     if(l<r){
             int q = partition(a,l,r);
             quick_sort(a,l,q-1);
             quick_sort(a,q+1,r);        
     }     

}

int partition(int a[], int l, int r){
        int p = a[r];
        int i=l-1; 
        for(int j=l; j<=r-1;j++){
                if(a[j] <=p){
                        i++;
                        swap(a[i],a[j]);      
                }
        }
        swap(a[i+1],a[r]);
        return i+1;
}

void print_array(int a[], int n){
       for(int i=0; i<n; i++){
               cout<<a[i]<<" ";        
       }
       cout<<endl;         
}
main(){
       int a[] = {454,2,3,12,9,54,34};
       int n = sizeof(a)/sizeof(a[0]);
        //partition(a,0,n-1);
        quick_sort(a,0,n-1);
        print_array(a,n);
        system("pause");
       }
 

