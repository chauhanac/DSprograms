#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};


node* insert_beg(node* start,int data)
{
	
	node* ptr=new node;
	ptr->data=data;
	if(start==NULL)
	{
       ptr->prev=NULL;
       ptr->next=NULL;
       start=ptr;
	}
	else
	{
	start->prev=ptr;
	ptr->next=start;
	ptr->prev=NULL;
	start=ptr;
    }
	
	return start;
}

 node* display(node* start)
{

	node* ptr=new node;
	ptr=start;
	
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
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
	
	cout<<endl;
	start=display(start);
	
	return 0;
}
