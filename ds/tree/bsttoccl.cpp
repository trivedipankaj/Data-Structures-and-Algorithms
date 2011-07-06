#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node{
       int data;
       bool visited;
       node *left;
       node *right;
};

node *newNode(int data){
     node *nn = new node;
     nn->data  = data;
     nn->left = NULL;
     nn->right = NULL;
     nn->visited = false;
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

void print_stack(){
     cout<<"Begin stack: ";
     while(!s.empty()){
            node *temp = s.top(); s.pop();
            cout<<temp->data<<" ";                 
     }
     cout<<"End of stack";    
}

/***iterative inorder traversal***/
void iter_inorder(node *root){
     if(root !=NULL){
             node *t = new node;
             t = root;
             s.push(t);
             while(!s.empty()){
                while(t->left !=NULL){
                  s.push(t->left);
                  t = t->left;
                }
                t = s.top(); s.pop();
                if(!t->visited){
                        cout<<t->data<<" ";
                        t->visited = true;
                }
                if(t->right!=NULL){
                    s.push(t->right);
                    t = t->right;                  
                }
             }  
          }
     
}

node* convert(node *root,node *&prev,node *&head){
         
         if(root ==NULL) return NULL;
          convert(root->left,prev,head);
          
          root->left  = prev;
          if(prev != NULL){
                  prev->right = root;
           else
                head  = root;
          
          node *right = root->right;
          head->left  = root;
          root->right = head;
          prev  = root;
          
          convert(right,prev,head);
          
}
int n=0;
void print_list(node *root){
       if(root!=NULL && n<10){
              cout<<root->data<<" ";
              n++;
              print_list(root->right);        
                                     
       }
     }

main(){
       node *d = NULL;
       int a[] = {30,33,14,3,5,78,9,32,1,54};
       int   n  = sizeof(a)/sizeof(a[0]);
       for(int i=0; i<n; i++){
               d = insert(d,a[i]);               
       }
      // inorder(d); cout<<endl;
       //level_order(d);
      // iter_inorder(d); cout<<endl;
      node *head = NULL;
      node *prev = NULL;
      node *ss= convert(d,prev,head);
      print_list(head);
      // iter_inorder(d); cout<<endl;
     //inorder(d);
       system("pause");
}

