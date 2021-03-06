/**
@author Pankaj Trivedi
@desc Implementation of reversing a doubly linked list
@created Tuesday, 31-05-2011, 22:10
*/


#include<iostream>
using namespace std;

struct node{
       int data;
       node *prev;
       node *next;
       };
       
node *newNode(int data){
     node *nn = new node;
     nn->data = data;
     nn->prev = NULL;
     nn->next = NULL;
     } 
     
 node *insert(node *head,int data,node **end){
      if( head == NULL ){
          node *nn = newNode(data);
          *end     = nn;
          return nn;
      }else{
            node *hp     = head;
            node *p      = newNode(data);
            while(hp->next!=NULL) 
                hp = hp->next;
            hp->next     = p;
            p->prev      = hp;
            *end          = p;
      }
      return head;    
 }         

void printForward(node *head){
     if(head !=NULL){
             node *p = head;
             while( p !=NULL){
                    cout<<p->data<<" ";
                    p = p->next;       
             }
              cout<<endl;     
     }     
}

void printBackward(node *tail){
     if(tail !=NULL){
             node *p = tail;
             while( p!=NULL){
                    cout<<p->data<<" ";
                    p = p->prev;       
             }
             cout<<endl;        
     }else{
           cout<<"Invalid tail! Are you kidding me?";
     }     
}

node *reverse(node *head){
     if(head != NULL){
             node *current = head;
             node *temp    = NULL;
             while(current != NULL){
                      temp          = current->prev;
                      current->prev = current->next;
                      current->next = temp;
                      current       = current->prev;           
             }
             if(temp!=NULL){
                  return temp->prev;              
             }
     }     
}

node *myreverse(node *head){
	if(head){
		node *curr = head;
		node *temp = NULL;
		while(curr){
		 	temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr      =  curr->prev;	
		}
	   return temp->prev;	
	}
}

main(){
       node *start = NULL, *end = NULL;
       start  = insert(start,12,&end);
       start  = insert(start,21,&end);
       start  = insert(start,112,&end);
       start  = insert(start,312,&end);
       printForward(start);
       printBackward(end);
       start = myreverse(start);
       printForward(start);
       
       
       }
