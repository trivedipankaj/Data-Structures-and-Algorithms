/****
@author Pankaj Trivedi
@desc print all duplicate characters
**/

#include<iostream>
#include<string>
using namespace std;
int map[26] ={0};
main(){
     string s; char m; cin>>s;
     int l = s.length();
     for(int i=0; i<l;i++){
	map[s[i]-'a']++;
     } 
     int max=0;	
     for(int i=0; i<l; i++){
	     if(map[s[i]-'a'] > 1) {
	        cout<<s[i]<<" "; map[s[i]-'a']=0;
	    }
     }
	cout<<endl;
}
