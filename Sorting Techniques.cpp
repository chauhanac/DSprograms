#include<iostream>
using namespace std;


void bubble_sort(int arr[],int n)
{
	int i,j,temp,flag=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			
		}
	}
	
	if(flag==0)
	{
		cout<<"\nArray Sorted ";
		return;
	}
	else
	{
		cout<<"\nSorted Array:"<<endl;
		for(i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	}
}


void insertion_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		
		while((temp<arr[j]) && (j>=0))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	
	cout<<"\nSorted Array:"<<endl;
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
}

void selection_sort(int arr[],int n)
{
	int i,j,temp;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	cout<<"\nSorted Array:"<<endl;
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	
}

int main()
{
	int n;
	cout<<"\nEnter size of array:";
	cin>>n;
	int arr[n],i;
	
	cout<<"\n Enter the elements:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"\nOriginal Array\n";
	
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	
	
	cout<<"\n\n MENU\n";
	cout<<"1.BUBBLE SORT";
	cout<<"\n2.INSERTION SORT";
	cout<<"\n3.SELECTION SORT";
	cout<<"\n\nEnter Choice:  ";
	
	int choice;
	cin>>choice;
	
	switch(choice)
	{
		case 1: bubble_sort(arr,n);
		break;
		case 2: insertion_sort(arr,n);
		break;
		case 3: selection_sort(arr,n);
		break;
		default: cout<<"\nWRONG INPUT";
	}
	
	
	return 0;
}
