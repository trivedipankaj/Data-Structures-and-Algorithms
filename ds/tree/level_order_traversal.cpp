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
stack<node*> s;
queue<node*> q;
vector<node*> v;
/**BFS of a BST**/
void level_order(node *root){
     if(root !=NULL){
               q.push(root);
               while(!q.empty()){
                     node* temp = q.front();  q.pop();
                     cout<<temp->data<<" ";
                     if(temp->left != NULL)
                     q.push(temp->left);
                     if(temp->right !=NULL)
                     q.push(temp->right);
                           
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
       level_order(d);
             system("pause");
}

