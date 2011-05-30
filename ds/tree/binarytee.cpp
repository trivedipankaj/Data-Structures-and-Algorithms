#include<iostream>
using namespace std;

struct node{
	int data;
        node *left;
        node *right;
};

node *newNode(int data){
	node *nn = new node;
        nn->data = data;
	nn->left = NULL;
        nn->right = NULL;
      return nn;		
}

node *insert(node *root, int data){
	if(root == NULL){
	    return newNode(data);
	}else{
	    if( data <= root->data)
		root->left = insert(root->left,data);
            else{
		root->right = insert(root->right,data);	
            }		
	return root;
	}
    
}
void inorder( node *root){
      if(root != NULL){
	   inorder(root->left);
           cout<<root->data<<" ";
           inorder(root->right);		
      }	
}

int sumNodes( node *root){
	if(root == NULL)
          return 0;
       else{
	 return root->data + sumNodes(root->left) + sumNodes(root->right);
	}
}

main(){
	node *root = NULL;
        root   = insert(root,45);			
        root   = insert(root,5);			
        root   = insert(root,15);			
        root   = insert(root,44);			
        root   = insert(root,35);			
        root   = insert(root,25);			
        root   = insert(root,85);			
        root   = insert(root,115);
        inorder(root);
        cout<<"Sum is=";
        cout<<sumNodes(root);			
}
