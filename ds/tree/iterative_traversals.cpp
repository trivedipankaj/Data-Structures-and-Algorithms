#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node{
       int data;
       bool visited;
       node *left;
       node *right;
};

node *newNode(int data){
     node *nn = new node;
     nn->data  = data;
     nn->left = NULL;
     nn->right = NULL;
     nn->visited = false;
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

void inorder ( node *root){
     if(root != NULL){
             inorder(root->left);
             cout<<root->data<<" ";
             inorder(root->right);
     }     
}

void preorder ( node *root){
     if(root != NULL){
             cout<<root->data<<" ";
             preorder(root->left);
             preorder(root->right);
     }     
}
stack<node*> s;
queue<node*> q;
vector<node*> v;

/***iterative inorder traversal***/
void iter_inorder(node *t){
    
             while(!s.empty() || t!=NULL){
                if(t!=NULL){
                            s.push(t);
                            t = t->left;
                }else{
                t = s.top(); s.pop();
                cout<<t->data<<" ";
                t = t->right;          
             }  
             }
     
}

void iter_preorder(node *t){
        while(!s.empty() || t!=NULL){
                if(t!=NULL){
                     cout<<t->data<<" ";
                     s.push(t);
                     t =t->left;       
                }else{
                      t = s.top(); s.pop();
                      t = t->right;     
                }                 
        }     
}

main(){
       node *d = NULL;
       int a[] = {30,33,14,3,5,78,9,32,1,54};
       int   n  = sizeof(a)/sizeof(a[0]);
       for(int i=0; i<n; i++){
               d = insert(d,a[i]);               
       }
       inorder(d); cout<<endl;
       //level_order(d);
      iter_inorder(d); cout<<endl;
      /*node *head = NULL;
      node *prev = NULL;
      node *ss= convert(d,prev,head);
      print_list(head);*/
      // iter_inorder(d); cout<<endl;
     //inorder(d);
     preorder(d);
     cout<<endl; 
     iter_preorder(d);
     
       system("pause");
}

