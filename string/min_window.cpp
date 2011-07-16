#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
#define DEBUG 1
int map[256]={0};
int visited[256]={0};

string find_min_window(string s, string t){
	  int tl = t.length();
	  int sl = s.length();
	  for(int i=0; i<tl;i++)
		map[t[i]]++;	
	  int begin=0,cnt=0,min=INT_MAX,minBegin=0,minEnd;
	  for(int i=0; i<sl; i++){
	        if(map[s[i]] == 0) continue; //skip the characters that are not in t
		visited[s[i]]++;
		if(visited[s[i]] <= map[s[i]]) cnt++;
		if(cnt ==tl){
		    while(map[s[begin]] ==0 || visited[s[begin]] > map[s[begin]]){
			  if(visited[s[begin]] > map[s[begin]])
				visited[s[begin]]--;
			  begin++;
		    }
		    int wl = i-begin+1;
		    if(wl < min){
			min = wl;
			minBegin = begin;
			minEnd   = i;
		    }		
		}	
	  }
	  if(DEBUG) cout<<"begin="<<minBegin<<" min is="<<min<<endl;
	  if(min!=INT_MAX)
	  	return s.substr(minBegin,min);
	  else return "";
	 
}

main(){
      string s,t; while(getline(cin,s) && getline(cin,t) && s!="END"){
	   string res = find_min_window(s,t);
	   if(res!=""){
	       cout<<res<<endl;	
	   }else{
		cout<<"No such window exist!"<<endl;
	  }
	
      }
	

}
