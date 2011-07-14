#include<iostream>
using namespace std;
struct node{
	int data;
	bool rthread;
	bool lthread;
	node *left;
	node *right;

};

node *newNode( int data){
	node *nn = new node;
	nn->data = data;
	nn->left =NULL;
        nn->right=NULL;
	nn->rthread = true;
	nn->lthread = true;
	return nn;
}

node *head = newNode(0);
node *insert(node *r, int data){
	if(r ==NULL){ 
		node *t = newNode(data);
		t->left    = head;
		t->right   = head;
		return t;
	}
	node *root = r;
	bool found = false;
 	while(!found){
		if(root->data > data){ 
              		if(root->left && !root->lthread)
				root = root->left;
		         else{
			 	node *t   = newNode(data);
				t->left   = root->left;
				t->right  = root;
				root->left = t;
				root->lthread = false; 
	                        found = true;
			 }   
		}else{
			if(root->right && !root->rthread)
		 	  root = root->right;
	                else{
				node *t = newNode(data);
				t->right = root->right;
				t->left  = root;
				root->right = t;
				root->rthread = false;
	                        found=true;
			}
	        }
	}
	return r;
}

int minimum( node *root){
	if(root !=NULL){
	  while(!root->lthread){
		root = root->left;
	  }
	return root->data;
	}
}

int maximum(node *root){
	if(root!=NULL){
		while(!root->rthread){
			root =root->right;		
		}
	return root->data;
	}
}

node *getMinNode(node *root){
	if(root !=NULL){
          while(!root->lthread){
                root = root->left;
          }
        return root;
        }
	
}

node *successor(node *n){
	if(n==NULL) return n;
	if(n->rthread) return n->right;
        n = n->right;
	while(!n->lthread) n=n->left;
	return n;
}

void inorder(node *root){
	node *t = getMinNode(root);
	while(t!=head){
	     cout<<t->data<<" ";
	     t = successor(t);
	}
}

main(){
            node *root =NULL;
	    int a[] = {3,45,12,56,2,98,40};
	    int n  = sizeof(a)/sizeof(a[0]);
            for(int i=0; i<n; i++)
	       root =	insert(root,a[i]);

	    cout<<"Minimum is :"<<minimum(root); cout<<endl;
	    cout<<"Maximum is :"<<maximum(root); cout<<endl;	
	  	 inorder(root);
	    /* node *p = successor(root);
	        cout<<root->data; cout<<endl;
		cout<<p->data;*/
}						
