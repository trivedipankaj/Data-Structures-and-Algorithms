#include<iostream>
using namespace std;
int getMax(int a[],int n);
int getMin(int a[],int n);

bool isConsecutive(int a[],int n){
	int min,max;
        int v[n];
        if(n<0){
		return false;
	}
        min   = getMin(a,n);
        max   = getMax(a,n);
        if( max - min +1 == n){
		for(int i=0; i< n; i++){
			v[i]  = 0;
		}
                for(int j=0; j<n; j++){
			if(v[a[j] - min] == 1)
				return false;
			v[a[j] - min] = 1;
		}
         return true;
	}
return false;
}
	

int getMax(int a[], int n){
	int max=a[0];
        for(int i=0; i< n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
 return max;
}
int getMin(int a[], int n){
        int min = a[0];
        for(int i=0; i< n; i++){
                if(a[i] <  min){
                        min = a[i];
                }
        }
 return min;
}

main(){
  int a[] = {1,2,3,4,5,0,-1};
  int n=7;
 if(!isConsecutive(a,n)){
	cout<<"It retruns false!";
 }else{
	cout<<"It retruns true!";
	}	
}
