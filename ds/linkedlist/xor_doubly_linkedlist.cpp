/**
@author Pankaj Trivedi
@desc doubly linked list with single pointer. XOR linked list
@created 31-05-2011, 23:45 IST.
*/

#include<iostream>

using namespace std;
struct node{
       int data;
       node *next;
};
node *start = NULL;
node *end   = NULL;

/**
use this to go to the next element, either direction
**/
node *XOR(node *a, node *b){
     return (node *) ((long long) (a) ^ (long long) ( b));     
}

void insert( node *current, node *prev, int data){
     if(start == NULL){
           node *nn  = new node;
           nn->data  = data;
           nn->next  = XOR(current,prev);
           start     = nn;
           end       = nn;        
     }else if( XOR(prev,current->next) == NULL){
           node *nn     = new node;
           nn->data     = data;
           current->next = XOR(prev,nn);
           nn->next     = XOR(current,NULL);
           end           = nn;
     }else{
           insert(XOR(current->next,prev),current,data);      
     }   
}

void printForward(node *start, node *prev){
          if(start !=NULL){
             cout<<start->data<<" ";
             printForward(XOR(start->next,prev), start);     
          }
}

void printBackward(node *end, node *prev){
          if(start !=NULL){
             cout<<end->data<<" ";
             printForward(XOR(end->next,prev), end);     
          }
}

main(){
       node *prev    = NULL;
       node *current = NULL;
       insert(start,prev,23);
       insert(start,prev,43);
       insert(start,prev,234);
       insert(start,prev,63);
       printForward(start,NULL);
       cout<<endl;
       printBackward(end,NULL);
       system("pause");
}


