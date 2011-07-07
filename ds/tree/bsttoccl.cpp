/***
@author Pankaj Trivedi
@desc changing binary search tree into circular doubly linked list
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node{
       int data;
       node *left;
       node *right;
};

node *newNode(int data){
     node *nn = new node;
     nn->data  = data;
     nn->left = NULL;
     nn->right = NULL;
     
     return nn;
     }

node *insert(node *root, int data){
     if(root ==NULL)
        return newNode(data);
     else if( root->data >= data)
         root->left  = insert(root->left,data);           
     else root->right = insert(root->right,data);
     return root;
}

stack<node*> s;
queue<node*> q;



node* convert(node *root,node *&prev,node *&head){
         
         if(root ==NULL) return NULL;
          convert(root->left,prev,head);
          
          root->left  = prev;
          if(prev != NULL)
                  prev->right = root;
           else
                head  = root;
          
          node *right = root->right;
          head->left  = root;
          root->right = head;
          prev  = root;
          
          convert(right,prev,head);
          
}
int n=0;
void print_list(node *root){
       if(root!=NULL && n<10){
              cout<<root->data<<" ";
              n++;
              print_list(root->right);        
                                     
       }
     }

main(){
       node *d = NULL;
       int a[] = {30,33,14,3,5,78,9,32,1,54};
       int   n  = sizeof(a)/sizeof(a[0]);
       for(int i=0; i<n; i++){
               d = insert(d,a[i]);               
       }
       
      node *head = NULL;
      node *prev = NULL;
      node *ss= convert(d,prev,head);
      print_list(head);
      
       system("pause");
}

