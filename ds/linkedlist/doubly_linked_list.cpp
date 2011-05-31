/**
@author Pankaj Trivedi
@desc Implementation of doubly linked list
@created Tuesday, 31-05-2011, 21:52
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
          return newNode(data);
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

main(){
       node *start = NULL, *end = NULL;
       start  = insert(start,12,&end);
       start  = insert(start,21,&end);
       start  = insert(start,112,&end);
       start  = insert(start,312,&end);
       printForward(start);
       printBackward(end);
       system("pause");
       
       }
