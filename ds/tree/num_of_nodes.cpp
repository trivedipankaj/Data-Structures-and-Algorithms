/**
@author Pankaj Trivedi
@desc Construction of a binary search tree. 
@created May 28th,2011 00:20 IST.
**/

#include<iostream>
using namespace std;

struct node{
       int data;
       node *left;
       node *right;
};
/**
a new binary tree node
*/
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
/**inorder traversal of a binary search tree */
void inorder( node *root){
     if(root != NULL){
	           inorder(root->left);
             cout<<root->data<<" ";
             inorder(root->right);		
      }	
}

/**preorder traversal of a binary search tree */
void preorder( node *root){
     if(root != NULL){
	           cout<<root->data<<" ";
             preorder(root->left);
             preorder(root->right);		
      }	
}

/**postorder traversal of a binary search tree */
void postorder( node *root){
     if(root != NULL){
	           postorder(root->left);
             postorder(root->right);
             cout<<root->data<<" ";		
      }	
}

/** number of all the nodes of the binary search tree */
int numNodes( node *root){
	if(root == NULL)
          return 0;
  else if( root->left == NULL && root->right == NULL )
       return 1;
  else{
	     return (1 + numNodes(root->left) + numNodes(root->right));
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
        cout<<endl;
        cout<<"Number of nodes=";
        cout<<numNodes(root);
        system("pause");			
}
