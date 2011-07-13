#include<iostream>
#include<string.h>
using namespace std;
int map[256] ={0};
main(){
	char s[50],m[50]; 
	cin>>s>>m;
	int sl  = strlen(s);  int ml =strlen(m);
	for(int i=0; i<ml;i++){
	   map[m[i]]++;
	}
        int act_i=0; int new_i=0;
        while(*(s+act_i)){
		char t = *(s+act_i);
		if(map[t] ==0){
		   *(s+new_i) = *(s+act_i); 
		     new_i++;
		}
		act_i++;
	}
	*(s+new_i) = '\0';
        cout<<s<<endl;
}
