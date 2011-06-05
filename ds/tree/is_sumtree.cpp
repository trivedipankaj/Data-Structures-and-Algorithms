/**
@author Pankaj Trivedi
@desc Finds if a given binary tree is a Sum Tree 
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


int isSumTree(node *root){
     /**empty tree is a sum tree*/
     if(root ==NULL){
          return 1;
     }
     /**just one node is a sum tree too**/
     else if(root->left == NULL && root->right == NULL)
         return 1;
     else{
         if(isSumTree(root->left) && isSumTree(root->right)){
           int ls,rs;
          if( root->left == NULL)
             ls =0;
          else ls = root->left->data;
          if(root->right == NULL)
             rs =0;
          else rs = root->right->data;
          
          if( root->data == (ls+rs))
             return 1;
          else return 0;
          
     }
     return 0;
     }
           
}

main(){
	node *root = newNode(5);;
       
       
       root->left = newNode(3);
       root->right = newNode(1);
       root->left->left = newNode(1);
       root->left->right = newNode(2);
        cout<<isSumTree(root);
        system("pause");			
}
