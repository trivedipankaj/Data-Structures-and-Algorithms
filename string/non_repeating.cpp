/****
@author Pankaj Trivedi
@desc the first non-repeating character
**/

#include<iostream>
#include<string>
using namespace std;
int map[26] ={0};
main(){
     string s; cin>>s;
     int l = s.length();
     for(int i=0; i<l;i++){
	map[s[i]-'a']++;
     } 	
     for(int i=0; i<l; i++){
	if(map[s[i]-'a'] ==1){
	   cout<<s[i]<<endl; break;
	}
    }
}
