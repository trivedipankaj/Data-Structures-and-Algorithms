#include<iostream>
using namespace std;
//node *tree_min(node *root);
struct node{
  int data;
  node *left;
  node *right;
  node *parent;     
};

node * newNode(int data){
     node *nn = new node;
     nn->data = data;     
     nn->left = NULL;
     nn->right= NULL;
     nn->parent = NULL;
     return nn;
}

node *insert(node *root, int data){
     node *temp = new node;
     if(root ==NULL)
        return newNode(data);
     else if(root->data < data){
          temp = insert(root->right,data);
          temp->parent = root;
          root->right = temp;
     }else{
          temp = insert(root->left,data);
          temp->parent = root;
          root->left = temp;
           }        
           return root;
}
void inorder(node *root){
     if(root!= NULL){
              inorder(root->left);
              cout<<root->data<<" ";
             // if(root->parent!=NULL) cout<<"parent of "<<root->data<<" "<<root->parent->data<<" ";
              inorder(root->right);           
     }     
}
node *tree_min(node *root){
     while(root->left !=NULL) root = root->left;     
     return root;
}

node *tree_max(node *root){
     while(root->right !=NULL) root = root->right;     
     return root;
}


node *successor(node *root){
     if(root->right != NULL){
            return tree_min(root->right);                                   
     }
     if(root->parent == NULL) {cout<<"Successor not found"<<endl; return NULL; }
     node *y = root->parent;
     while( (y != NULL) && (root = y->right)){
              root = y;
              y    = y->parent;       
     }
     return y;   
}

node *predecessor(node *root){
     if(root->left != NULL){
            return tree_max(root->left);                                   
     }
     if(root->parent == NULL) {cout<<"Successor not found"<<endl; return NULL; }
     node *y = root->parent;
     while( (y != NULL) && (root = y->left)){
              root = y;
              y    = y->parent;       
     }
     return y;   
}

void delete_node(node &head){
     node *root = &head;
     cout<<"Deleting"<<root->data;
     if(root->left ==NULL && root->right ==NULL){
            cout<<"There we go!";
            root->parent->left = NULL;              
     } 
}
int max(int a,int b){
    if(a>b) return a; else return b;    
}

int height(node *root){
    if(root == NULL) 
      return 0;
     else return (1+ max(height(root->left),height(root->right)));   
}

node *sum_tree(node *root){
     if(root != NULL && (root->left !=NULL || root->right!=NULL) ){
             sum_tree(root->left); 
             sum_tree(root->right);
             
            if(root->left !=NULL && root->right != NULL)
                   root->data += root->left->data + root->right->data;
            else if(root->left != NULL)
                   root->data +=root->left->data;
            else 
                   root->data +=root->right->data;               
                    
     }  return root;   
}

main(){
       node *d = NULL;
       int a[] = {23,56,3,4,2,24,331,5,67};
       int n    = sizeof(a)/sizeof(a[0]);
       for(int i=0; i<n; i++){
              d=  insert(d,a[i]);        
       }
      // delete_node(*d->right->right->left);
       cout<<"Inorder Traversal:"<<endl;
       inorder(d);
       cout<<endl;
       //node *p = successor(d->right->right);
      // cout<<p->data;
      //cout<<height(d);
      d  = sum_tree(d);
      inorder(d);
       system("pause");
       }

