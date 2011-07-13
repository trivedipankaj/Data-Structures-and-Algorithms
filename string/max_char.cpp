/****
@author Pankaj Trivedi
@desc the character of the maximum number of characters
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
	     if(map[s[i]-'a'] > max) {
		max = map[s[i]-'a'];
		m = s[i];
	     }
     }
    cout<<"character is="<<m<<" and number="<<max<<endl;
}
