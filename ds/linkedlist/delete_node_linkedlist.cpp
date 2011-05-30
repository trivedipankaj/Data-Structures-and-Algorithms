
/**
@author Pankaj Trivedi
@desc Reverse a singly linked list
@created 23-05-2011
*/
#include<iostream>
using namespace std;

struct node{
       int data;
	node *next;
};
node *newNode(int data){
	node *nn = new node;
        nn->data = data;
        nn->next = NULL;
}

node *insert(node *head, int data){
	 if(head == NULL){
	  return newNode(data);
	}else{
	   node *p = new node;
           p  = head;
           while(p->next != NULL){
		p = p->next;
	   }
            p->next = newNode(data);
      	    return head;
	}
	
}

void print(node *head){
	if(head !=NULL){
	   node *p = new node;
          	 p = head;
            while(p->next != NULL){
                cout<<p->data<<" ";
                p = p->next;	
	   }
            cout<<p->data<<endl;
	}
}

node *delete_node(node *head, int n){
     if(head !=NULL){
            int cnt = 1;
            node *p   = head;
            node *curr = new node;
            while( p->next !=NULL && cnt < n-1){
                   p = p->next; cnt++;      
            }
            if(cnt < n-1){
                   cout<<"smaller list, invalid node number!";
            }else{
                  if(n == 1){
                       curr = head;
                       head = p->next;
                       
                  }else{
                        curr    = p->next;
                        p->next = p->next->next;
                        
                  }
                  free(curr);      
            }           
     return head;
     }
     
}
     
main(){
     node *head = NULL;
     head     =  insert(head,23);	
     head     =  insert(head,13);	
     head     =  insert(head,43);	
     head     =  insert(head,83);	
     head     =  insert(head,53);	
     head     =  insert(head,63);	
    
     print(head);
     head      = delete_node(head,6);
     print(head);
     
     system("pause");
}

