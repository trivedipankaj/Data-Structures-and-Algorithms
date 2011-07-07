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

void mirror_tree(node *root){
          if(root !=NULL){
                  mirror_tree(root->left); 
                  mirror_tree(root->right);
                  
                  node *temp = root->left;
                  root->left = root->right;
                  root->right  = temp; 
        
          }             
          
}

void print_at_k(node *root, int k){
      if(root ==NULL) return;
      if(k ==0){
        cout<<root->data<<" ";
        return;
      }else{
            print_at_k(root->left,k-1);
            print_at_k(root->right,k-1); 
      }
}

main(){
       node *d = NULL;
       node *p =NULL;
       int a[] = {30,33,14,3,5,78,9,32,1,54};
       int b[] = {30,33,14,3,5,78,32,1,54};
       int   n1  = sizeof(a)/sizeof(a[0]);
       int n2 = sizeof(b)/sizeof(b[0]);
       for(int i=0; i<n1; i++){
               d = insert(d,a[i]);               
       }
       for(int i=0; i<n2; i++){
               p = insert(p,b[i]);               
       }
       print_at_k(d,2);
      // inorder(d); cout<<endl;
       // mirror_tree(d);
      // inorder(d); cout<<endl;
             system("pause");
}

