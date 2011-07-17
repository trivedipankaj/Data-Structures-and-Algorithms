#include<iostream>
using namespace std;

struct listnode{
	int data;
	listnode* next;
};

listnode* newNode(int data){
	listnode *nn = new listnode;
	nn->data     = data;
	nn->next     = NULL;
	return nn;
}


listnode *sorted_insert(listnode *head, int data){
	if(head ==NULL) return newNode(data);
	if(head){
		listnode *h = head;
		listnode *p = newNode(data);
	   if(data < h->data){
		p->next     = h;
		return p;
	   }
	   while(h->next && h->next->data < data){
		  h = h->next;
	   }
	   listnode *t = h->next;
	   h->next  = p;
	   p->next     = t;
	   return head;		
 }
}

listnode * merge_sorted(listnode *head, listnode *a, listnode *b){
	listnode *temp;     
	while(a->next && b->next){
	    if(a->data > b->data){
		if(head ==NULL) {head = newNode(b->data);
				temp = head;
				b = b->next;	
			}
		else{ head->next = newNode(b->data); 
		      head = head->next;
		      b = b->next;
		    } 
	    }else{
		if(head ==NULL) {head = newNode(a->data);
				temp = head;
				a = a->next;
				}
                else{ head->next = newNode(a->data);
                      head = head->next;
                      a = a->next;
                    }  	
	    }
	}
	if(a->next!=NULL) head->next = a->next;
	else if(b->next!=NULL) head->next = b->next;
	return temp; 
} 

void print_list(listnode *head){
	while(head){
	   cout<<head->data<<" ";
	   head = head->next;
	}
	cout<<endl;
}



main(){
	listnode *d = NULL;
	listnode *p = NULL;
	listnode *h = NULL;
	int a[] = {5,6,7,34,12,23,89,4,343};
	int n   = sizeof(a)/sizeof(a[0]);
	int b[] = {15,16,17,134,112,123,819,14,1343};
	int m   = sizeof(b)/sizeof(b[0]);
	for(int i=0; i<n; i++) 
	     d = sorted_insert(d,a[i]);
	for(int i=0; i<m; i++) 
	     p = sorted_insert(p,b[i]);
	 print_list(d);
         print_list(p);
	 h =merge_sorted(h,d,p);
	 print_list(h);
}
