
/**
@author Pankaj Trivedi
@desc detecting a loop in a singly linked list
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

bool detect_loop( node *head){
     if(head != NULL){
             node *slow = head;
             node *fast = head;
             while( slow->next != NULL && fast->next->next != NULL && fast->next !=NULL){
                     slow   = slow->next;
                     fast   = fast->next->next;
                     if(slow == fast)
                      return true;        
             }
             return false;            
     }
     return false;
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
     /**lets have a loop*/
     head->next->next->next = head->next;
     if(detect_loop(head)){
          cout<<"There is a loop!";                      
      }else{
            cout<<"There is no loop found!";
      }
    
     
     system("pause");
}

