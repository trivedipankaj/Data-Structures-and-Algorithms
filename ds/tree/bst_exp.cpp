#include<iostream>
using namespace std;

struct node{
       int data;
       node *left;
       node *right;
 };
 node * newNode(int data){
        node *nn = new node;
        nn->data   = data;
        nn->left   = NULL;
        nn->right  = NULL;
        return nn;
      }
 node *insert(int data, node *root){
       
       if(root == NULL){
               return newNode(data);                   
       }else if( root->data < data){
               root->right = insert(data,root->right);    
       }else{
             root->left  = insert(data,root->left);
             }
       return root;           
 }    
 void inorder(node *root){
      if(root != NULL){
              inorder(root->left);
              cout<<root->data<<" ";
              inorder(root->right);                
      }     
 } 
 void preorder(node *root){
      if(root != NULL){
              cout<<root->data<<" ";
              preorder(root->left); 
              preorder(root->right);        
      }     
 }
 
 void postorder(node *root){
        if(root != NULL){
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";        
        }
 }
 
 node *search(int data,node *root){
       
             if(root == NULL || root->data == data) 
                return root;                
             else if( data > root->data)
                   return search(data,root->right);
             else
                   return search(data,root->left);  
       
}

int find_level(int data, node *root, int level){
               if(root == NULL || root->data == data){
                       return level;
               }else if(data> root->data)
                   return find_level(data,root->right,level+1);
                else
                   return find_level(data,root->left,level+1);    
}

node *iter_search(int data, node *root){
           while(root != NULL && root->data != data){
                      if(root->data < data)
                         root = root->right;           
                      else
                         root = root->left;
           }
        return root;   
}
 
int minimum(node *root){
    if(root != NULL){
          while(root->left !=NULL) root= root->left;     
          return root->data;
    }    
}
int maximum(node *root){
    if(root != NULL){
          while(root->right !=NULL) root= root->right;     
          return root->data;
    }    
} 
int rec_max(node *root){
    if( root != NULL && root->right == NULL)
       return root->data;
     return rec_max(root->right);     
}

void print_k1k2( node *root, int k1, int k2){
      if(root !=NULL){
              print_k1k2(root->left,k1,k2);
              if(root->data >=k1 && root->data <=k2) cout<<root->data<< " ";        
              print_k1k2(root->right,k1,k2);
      }     
} 

void print_kth(node *root,int k){
     if(root !=NULL){
             if(k==0){
                      cout<<root->data<<" ";         
             }
        print_kth(root->left,k-1); print_kth(root->right,k-1);             
     }     
}
main(){
       node *d = NULL;
       int a[] = {3,23,331,5,67};
       int n    = sizeof(a)/sizeof(a[0]);
       for(int i=0; i<n; i++){
              d=  insert(a[i],d);        
       }
       cout<<"Inorder Traversal:"<<endl;
       inorder(d);
       cout<<endl;
       
       cout<<"Preorder Traversal:"<<endl;
       preorder(d);
       cout<<endl;
       
       cout<<"Postorder Traversal:"<<endl;
       postorder(d);
       cout<<endl;
       node *p = search(67,d);
       if(p!= NULL)
         cout<<p->data;
       else
        cout<<"NOT FOUND";
        cout<<"Minimum Value in the tree is:\n"; cout<<rec_max(d);cout<<endl;
        
        print_k1k2(d,4,30);cout<<endl;
        cout<<find_level(67,d,1); cout<<endl;
        print_kth(d,2);
       system("pause");   
       }

