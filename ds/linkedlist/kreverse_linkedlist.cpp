/**
@author Pankaj Trivedi
@desc Reverses alternate k nodes and
   returns the pointer to the new head node
@created 02-06-2011
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

node *kreverse(node *head, int k){
     if(head != NULL){
             int cnt =0;
             node *current = head;
             node *next;
             node *prev = NULL;
             /****reverse the first k nodes****/   
             while(current != NULL && cnt <k){
                       next           = current->next;
                       current->next  = prev;
                       prev           = current;
                       current        = next;
                       cnt++;
             }     
            
             head->next = current;
             /**skip the next k nodes***/
             cnt =0;
             while( cnt < k-1 && current != NULL){
                    current  = current->next;
                    cnt++;
             }
             if(current!=NULL){
                       current->next  =  kreverse(current->next,k);                 
             }
             
             return prev;
     }
     
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
      head  = kreverse(head,2);
      print(head);
     system("pause");

}
