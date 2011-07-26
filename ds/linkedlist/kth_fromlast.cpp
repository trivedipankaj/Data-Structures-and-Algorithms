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
listnode *kthfrom_last(listnode *head, int k){
	  if(head && k>0){
		listnode *ptr1 = head;
	        listnode *ptr2 = head;
                int cnt=0;
		while(cnt <k){
		  ptr1 = ptr1->next; cnt++;
		}
		while(ptr1!=NULL){
			ptr2 = ptr2->next; ptr1 = ptr1->next;
		}
	       return ptr2;
	  }
}


main(){
	listnode *d = NULL;
	int a[] = {5,6,7,34,12,23,89,4,343};
	int n   = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<n; i++) 
	     d = sorted_insert(d,a[i]);
	 print_list(d);
	listnode *temp = kthfrom_last(d,1);
	cout<<temp->data<<endl;
}
