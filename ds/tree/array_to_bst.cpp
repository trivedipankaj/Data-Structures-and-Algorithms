/****
@author Pankaj Trivedi 
@desc convert sorted array into a balanced binary search tree
@date July 07, 2011 00:13 IST
******/

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
         nn->right= NULL;
         return nn;     
}

node *array_to_bst(int a[],int start,int end){
                 if(start >end)   return NULL;
                 int mid = (start+end)/2;
                 node *n = newNode(a[mid]);
                 n->left = array_to_bst(a,start,mid-1);
                 n->right = array_to_bst(a,mid+1,end);     
                 return n;
}

void inorder(node *root){
     if(root!=NULL){
                    inorder(root->left);
                    cout<<root->data<<" ";
                    inorder(root->right);               
     }     
}
main(){
       int a[] = {3,4,56,78,89,123,456,678};
       int len  = sizeof(a)/sizeof(a[0]);
       node *d = array_to_bst(a,0,len-1);
       inorder(d);
       system("pause");
       }

