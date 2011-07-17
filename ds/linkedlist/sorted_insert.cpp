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

listnode *insert(listnode *head, int data){
	if(head ==NULL) return newNode(data);
	head->next = insert(head->next,data);
	return head;
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

void print_list(listnode *head){
	while(head){
	   cout<<head->data<<" ";
	   head = head->next;
	}
	cout<<endl;
}



main(){
	listnode *d = NULL;
	int a[] = {5,6,7,34,12,23,89,4,343};
	int n   = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<n; i++) 
	     d = sorted_insert(d,a[i]);
	 print_list(d);
}
