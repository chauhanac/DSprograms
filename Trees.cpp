# include <iostream>
# include <stdlib.h>
# include <queue> 
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;
 
class BST
{
    public:
        void insert(node *, node *);
        void postorder(node *);
        void inOrder(node *);
        void display(node *, int);
        node* findsmallest(node *);
        node* findlargest(node *);
        bool iterativeSearch(node *, int );
        BST()
        {
            root = NULL;
        }
};

int main()
{
    int choice, num,key;
    BST bst;
    node *temp;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Postorder Traversal"<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Smallest Element"<<endl;
        cout<<"6.Largest Element"<<endl;
        cout<<"7.Search an element"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
            cin>>temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inOrder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 5:
        	cout<<"Display smallest element"<<endl;
        	temp=bst.findsmallest(root);
        	cout<<temp->info<<endl;
        	break;
        case 6:	
            cout<<"Display largest element"<<endl;
            temp=bst.findlargest(root);
            cout<<temp->info<<endl;
            break;
        case 7:
		    cout<<"Search an element"<<endl;
			cout<<"Enter element to be searched: ";
			cin>>key;    
			bool inp;
			inp=bst.iterativeSearch(root,key);
			if(inp)
			cout<<"Element found"<<endl;
			else
			cout<<"Element not found"<<endl;
			break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 
 
/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }
    }
}
 
/*
 * Postorder Traversal
 */
void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}

void BST::inOrder(node *ptr)
{
	if(root==NULL)
	{
		cout<<"TREE IS EMPTY";
		return;
	}
	
	if(ptr!=NULL)
	{
		inOrder(ptr->left);
		cout<<ptr->info<<" ";
		inOrder(ptr->right);
	}

} 

 
/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

node* BST::findsmallest(node* root)
{
	if((root==NULL) || (root->left==NULL))
	return root;
	else
	return findsmallest(root->left);
}

node* BST::findlargest(node* root)
{
	if((root==NULL) || (root->right==NULL))
	return root;
	else
	return findlargest(root->right);
}


// An iterative process to search an element x in a given binary tree 
bool BST::iterativeSearch(node *root, int x) 
{ 
    // Base Case 
    if (root == NULL) 
        return false; 
  
    // Create an empty queue for level order traversal 
    queue<node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    // Queue based level order traversal 
    while (q.empty() == false) 
    { 
        // See if current node is same as x 
        node *ptr = q.front(); 
        if (ptr->info == x) 
            return true; 
  
        // Remove current node and enqueue its children 
        q.pop(); 
        if (ptr->left != NULL) 
            q.push(ptr->left); 
        if (ptr->right != NULL) 
            q.push(ptr->right); 
    } 
  
    return false; 
} 
