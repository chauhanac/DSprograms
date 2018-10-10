#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};


	node *root=NULL;

node* getnewnode(int data)
{
	node *newnode= new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

node* insert(node* root,int data)
{
	if(root==NULL)
	  root=getnewnode(data);
	  else
	  if(data<=root->data)
	    root->left=insert(root->left,data);
	    else
	    root->right=insert(root->right,data);
	    
	    return root;
}

void inOrder(struct node *ptr)
{
	if(root==NULL)
	{
		cout<<"TREE IS EMPTY";
		return;
	}
	
	if(ptr!=NULL)
	{
		inOrder(ptr->left);
		cout<<ptr->data<<" ";
		inOrder(ptr->right);
	}

} 

int main()
{
	int n,x;
	
	cin>>n;
	
	while(n--)
	{
		cin>>x;
		root=insert(root,x);
	}
	
	inOrder(root);
	
}
