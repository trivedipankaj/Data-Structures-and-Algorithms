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

void print_list(listnode *head){
	while(head){
	   cout<<head->data<<" ";
	   head = head->next;
	}
	cout<<endl;
}

listnode *reverse_list(listnode *head){
	if(head){
	     listnode *prev =NULL;
	     listnode *curr = head;
	     listnode *temp;
	     while(curr){
		temp = curr->next;
		curr->next= prev;
		prev      = curr;
		curr      = temp;
	     }
	return prev;
	}
}

listnode *recur_reverse(listnode *head,listnode *prev){
	   if(head){
	     listnode *temp = head->next;
	      head->next    = prev;
	      return recur_reverse(temp,head);	
	   }else
	    return prev;

}

listnode *highest_first(listnode *head){
	/***identify the maximum element****/
	if(head){
	        listnode *t  = head;
		listnode *maxnode=t;
	 	int max = t->data;
		
		while(t){
		    if(t->data >max){
			max     = t->data;
			maxnode = t;
		    }
		    t= t->next;	
		}
	        if(t==head) return head; /*max element is still at first***/ 
		t = head;
	        while(t->next!=maxnode){
		     t= t->next;
		}
                t->next = t->next->next;
	        maxnode->next = head;
		return maxnode;
	}
}
/***************
incomplete: works only when the nodes are not consecutive and do not envolve head
******************/
listnode *swap(listnode *head, listnode *a, listnode *b){
		if(head){
		       listnode *preva=head, *prevb=head;
		       if(head !=a && head !=b){
			  while( preva->next!=NULL && preva->next !=a)
                                 preva = preva->next;
			  while(prevb->next !=NULL && prevb->next!=b)
				 prevb = prevb->next;
		       }
		       listnode *t1,*t2;
		       t1= a->next; t2=b->next;
		       preva->next = b; b->next=t1;
		       prevb->next = a; a->next=t2;	
	        return head;
		}
}

main(){
	listnode *d = NULL;
	int a[] = {5,6,7,34,12,23,89,4,343};
	int n   = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<n; i++) 
	     d = insert(d,a[i]);
         print_list(d);
	 //d =reverse_list(d);
	 cout<<endl;
	 print_list(d);
         //d = recur_reverse(d,NULL);
	//d =highest_first(d);
	    d = swap(d,d->next,d->next->next->next); 
	print_list(d);
}
