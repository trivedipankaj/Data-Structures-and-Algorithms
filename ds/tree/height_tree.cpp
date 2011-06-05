/**
@author Pankaj Trivedi
@desc Height of a binary search tree. 
@created June 6th,2011 00:20 IST.
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
/***height of the binary tree*/
int maxHeight(node *root){
    if(root == NULL)
      return 0;
    else{
         int h1 = maxHeight(root->left);
         int h2 = maxHeight(root->right);
         int max;
         if(h1 > h2)
           max=h1;
         else 
           max=h2;
         return (1+max);
         }
        
}

main(){
	node *root = NULL;
        /*root   = insert(root,45);			
        root   = insert(root,5);			
        root   = insert(root,15);			
        root   = insert(root,44);			
        root   = insert(root,35);	*/	
        root   = insert(root,2);			
        root   = insert(root,1);			
        root   = insert(root,3);
        inorder(root);
        cout<<maxHeight(root);
        system("pause");			
}
