/****
@author Pankaj Trivedi 
@desc convert sorted singly linked list into a balanced binary search tree
@date July 07, 2011 00:13 IST
******/

#include<iostream>
using namespace std;

struct node{
       int data;
       node *left;
       node *right;       
};

struct listnode{
       int data;
       listnode *next;       
};

listnode *newLN(int data){
         listnode *nn = new listnode;
         nn->data      = data;
         nn->next      = NULL;         
}

node *newNode(int data){
         node *nn = new node;
         nn->data = data;
         nn->left = NULL;
         nn->right= NULL;
         return nn;     
}


node *list_to_bst(listnode *&list, int start,int end){
                    if(start>end) return NULL;
                    int mid = (start+end)/2;
                    node *left = list_to_bst(list,start,mid-1);
                    node *parent = newNode(list->data);
                    parent->left = left;
                    list = list->next;
                    parent->right = list_to_bst(list,mid+1,end);
                    return parent;
                    
}

listnode* make_list(listnode *head, int data){
            if(head ==NULL)
             return  newLN(data);
            else head->next = make_list(head->next,data);
            return head;        
}

void print_list(listnode *head){
       while(head->next !=NULL){
             cout<<head->data<<" ";
             head   = head->next;
       }
       cout<<head->data<<" ";     
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
       
       listnode *ln = NULL;
       for(int i=0; i<len;i++)
           ln = make_list(ln,a[i]);
       cout<<endl;
       print_list(ln);
       cout<<endl;
       node *t = list_to_bst(ln,0,len-1);
       inorder(t);    
       system("pause");
       }

