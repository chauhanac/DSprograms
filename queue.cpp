#include<iostream>
#include<stdlib.h>
using namespace std;


struct node
{
	int data;
	node *next;
};

struct queue
{
	node *front;
	node *rear;
};

queue* insert(queue* q,int data)
{
	node* ptr=new node;
	ptr->data=data;
	
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=NULL;
		q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
		
	}
	
	return q;
}

queue* display(queue *q)
{
	node *ptr=new node;
	ptr=q->front;
	
	if(ptr==NULL)
	cout<<"\nQUEUE IS EMPTY";
	else
	{
		while(ptr!=q->rear)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<ptr->data;
	}
	
	return q;
}

queue *delete_element(queue *q)
{
	node* ptr=new node;
	ptr=q->front;
	
	if(ptr==NULL)
	cout<<"\nUNDERFLOW";
	else
	{
	q->front=q->front->next;
	cout<<"\nThe data being deleted is "<<ptr->data;
	free(ptr);
	}
	
	return q;
}

int main()
{
	queue *q=new queue;
	q->front=NULL;
	q->rear=NULL;
	
	int n,x;
	cin>>n;
	
	while(n--)
	{
		cin>>x;
		q=insert(q,x);
	}
	
	q=display(q);
	
	q=delete_element(q);
	
	return 0;
	
}
