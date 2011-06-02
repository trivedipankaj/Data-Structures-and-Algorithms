/**
@author Pankaj Trivedi
@desc separate the even and odd nodes of a linked list.
@created 01-06-2011, 22:24 IST
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

void even_odd( node **head){
     if(head ==NULL) return;
     node *p         = *head;
     node *current   = *head;
     node *prev      = NULL;  
     /** go to the end of the list*/
     while(p->next != NULL){
            p = p->next;
     }
     node *end    = p; 
     /**get the first even node**/
     while(current->data % 2 !=0 && current != p ){
                         end->next                   = current;
                         current                     = current->next;
                         end->next->next             = NULL;
                         end                         = end->next;
                             
                        
     } 
     /**first even node found, take all odd nodes to the end, just move on in case of even**/
     if(current->data % 2 == 0){
             *head   = current;
             while(current != p){
                   if(current->data % 2 == 0){
                          prev      = current;
                          current   = current->next;
                          
                   }else{
                         prev->next  = current->next;
                         current->next = NULL;
                         end->next     = current;
                         end           = current;
                         current       = prev->next;
                         
                   }                     
             }         
     /**no even node***/
     }else{
         prev = current;
     }
     /**check last node in the original list***/
     if(p->data %2 !=0){
                  prev->next = p->next;
                  p->next    = NULL;
                  end->next->next = p;
     }
      
}


main(){
     node *head = NULL;
     head     =  rec_insert(head,23);	
     head     =  rec_insert(head,12);	
     head     =  rec_insert(head,43);	
     head     =  rec_insert(head,84);	
     head     =  rec_insert(head,53);	
     head     =  rec_insert(head,66);	
      print(head);
      even_odd(&head);
      print(head);
      
     system("pause");

}
