/**
@author Pankaj Trivedi
@desc printing a singly linked list in reverse order.
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

/**
iterative insertion
*/
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
/** 
recursive insertion
*/

node *rec_insert(node *head, int data){
        if(head == NULL){
                return newNode(data);
        }else{
              head->next = rec_insert(head->next,data);
        }
        return head;
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
/**
printing reverse linked list , beauty of recursion!
*/
void print_reverse(node *head){
     if(head == NULL) return;
     print_reverse(head->next);
     cout<<head->data<<" ";     
}


main(){
     node *head = NULL;
     head     =  rec_insert(head,23);	
     head     =  rec_insert(head,13);	
     head     =  rec_insert(head,43);	
     head     =  rec_insert(head,83);	
     head     =  rec_insert(head,53);	
     head     =  rec_insert(head,63);	
      print(head);
      print_reverse(head);
     system("pause");

}
