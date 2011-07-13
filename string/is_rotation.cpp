#include<iostream>
#include<string>
using namespace std;
main(){
      string s1,s2;
      cin>>s1>>s2;
      s1 = s1+s1;
      int found = s1.find(s2);
      if(found){
	 cout<<"Rotation at the position :"<<found<<endl;
      }else{
      	cout<<"not found!"<<endl;
      }			
}
