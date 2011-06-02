#include<iostream>
#define NO_OF_CHARS 256
#define bool int

using namespace std;

char *remove_duplicate( char *str){
	int reg_ind =0; int ori_ind =0;
        bool hash[NO_OF_CHARS] = {0};
	char temp;
	while( *(str+reg_ind) ){
		temp = *(str + reg_ind);
		if(hash[temp] == 0){
                	hash[temp] = 1;
			*(str+ori_ind) = temp;
                        ori_ind++;
		}
		reg_ind++;
	}
	*(str+ori_ind) = '\0';
 return str;
}

main(){
	
        char str[] = "madam";
        printf("%s", remove_duplicate(str));
        cout<<endl;	
}
