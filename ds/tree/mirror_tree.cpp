/**
@author Pankaj Trivedi
@desc Mirror of a binary search tree. 
@created June 7th,2011 00:20 IST.
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

void mirrorTree(node *root){
      node *temp;
     if(root == NULL) return;
      
      mirrorTree(root->left);
      mirrorTree(root->right);
      
      temp                    = root->left;
      root->left              = root->right;
      root->right             = temp;
          
}

main(){
	node *root = NULL;
        root   = insert(root,45);			
        root   = insert(root,5);			
        root   = insert(root,15);			
        /*root   = insert(root,44);			
        root   = insert(root,35);			
        root   = insert(root,25);			
        root   = insert(root,85);			
        root   = insert(root,115);*/
        inorder(root);
        cout<<endl;
        mirrorTree(root);
        inorder(root);
        system("pause");			
}
