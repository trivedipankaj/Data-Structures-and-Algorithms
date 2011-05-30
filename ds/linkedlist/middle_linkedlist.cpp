
/**
@author Pankaj Trivedi
@desc middle of a singly linked list
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
	}else{
        cout<<"The linked list is empty!";
        }
}

node *middle( node *head){
     if(head != NULL){
             node *slow = head;
             node *fast = head;
             while( fast->next != NULL && fast->next->next !=NULL){
                     slow   = slow->next;
                     fast   = fast->next->next;
                                     
             }
             return slow;            
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
     head     =  insert(head,87);	
     print(head);
     node *mid = middle(head);
    cout<<mid->data<<endl;
     system("pause");
}

