#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* insert_beg(node* start,int data)
{
	node* ptr=new node;
	ptr->data=data;
	ptr->next=start;
	start=ptr;
	
	return start;
}

node* insert_end(node* start,int data)
{
	node* temp;
	node* ptr=new node;
	ptr->data=data;
	ptr->next=NULL;
	
	temp=start;
	
	if(temp==NULL)
	{
		temp->next=ptr;
	}
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=ptr;
	
	return start;
}


node* insert_before(node* start,int data,int key)
{
	node *temp,*pretemp;
	node *ptr=new node;
	ptr->data=data;
	temp=start;
	
	if(temp->data==key)
	{
		ptr->next=temp;
		start=ptr;
		return start;
	}
	
	while(temp->data!=key)
	{
		pretemp=temp;
		temp=temp->next;
	}
	
	pretemp->next=ptr;
	ptr->next=temp;
	
	return start;
}

node* del_element(node* start,int data)
{
	node* ptr=new node;
	node* preptr;
	
	ptr=start;
	
	if(ptr->data==data)
	{
		start=ptr->next;
		free(ptr);
		return start;
	}
	
	while(ptr->data!=data)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	
	preptr->next=ptr->next;
	free(ptr);
	
	return start;
}

node* sort_list(node* start)
{
	node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	
	return start;
}


node* display(node* start )
{
	node* ptr=new node;
	ptr=start;
	
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}
	
	return start;
}

int main()
{
	node* start=NULL;
	int n,x;
	cin>>n;
	
	while(n--)
	{
		cin>>x;
		start=insert_beg(start,x);
	}
	
	cout<<endl<<endl;
	start=display(start);
	
	int key;
	
	cout<<"\nEnter data to enter and  && The node before which to enter\n";
	
	cin>>x;
	cin>>key;
	
	start=insert_before(start,x,key);
	
	cout<<endl<<endl;
	start=display(start);
	
	cout<<"\nEnter data to delete\n";
	
	cin>>key;
	start=del_element(start,key);
	
	cout<<endl<<endl;
	start=display(start);
	
	cout<<"\nSorted List\n";
	start=sort_list(start);
	
	cout<<endl<<endl;
	start=display(start);
	
	
}
