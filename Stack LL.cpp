#include<iostream>
#include<stdlib.h>
using namespace std;


struct stk
{
	int data;
	stk *next;
};


stk* push(stk* top,int data)
{
	stk *ptr=new stk;
	ptr->data=data;
	
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	
	return top;
}

stk* display(stk* top)
{
	stk *ptr=new stk;
	ptr=top;
	
	if(ptr==NULL)
	cout<<"STACK EMPTY";
	else
	{
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	}
	return top;
	
}

stk* pop(stk* top)
{
	stk* ptr=new stk;
	ptr=top;
	
	if(top==NULL)
	cout<<"EMPTY STACK";
	else
	{
		while(ptr!=NULL)
		{
		
		top=top->next;
		cout<<"ELEMENT DELETED IS "<<top->data<<endl;
		free(ptr);
		ptr=top;
    	}
	}
	return top;
}

int main()
{
	int n,x;
	cin>>n;
	
	stk *top=NULL;
	
	while(n--)
	{
		cin>>x;
		top=push(top,x);
	}
	
	top=display(top);
	top=pop(top);
	top=display(top);
	
	return 0;	
		
}

