#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define max 10

void insert(int arr[max],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter element: ");
		scanf("%d",&arr[i]);
	}
}

void display(int arr[max],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void buildheap(int arr[max],int root,int n)
{
	int child,temp;
	while((root*2+1)<=n)
	{
		child=root*2+1;
		if((child+1)<=n && arr[child]<arr[child+1])
		{
			child=child+1;
		}
		if(arr[root]<arr[child])
		{
			temp=arr[root];
			arr[root]=arr[child];
			arr[child]=temp;
			root=child;
		}
		else
		{
			return;
		}
	}
}

void heapsort(int arr[max],int n)
{
	int temp,i;
	for(i=(n/2)-1;i>=0;i--)
	{
		buildheap(arr,i,n-1);
	}
	for(i=n-1;i>=1;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		buildheap(arr,0,i-1);
	}
}

void main()
{
	int arr[max],n,ch;
	clrscr();
	printf("\nEnter number of elements you want to enter: ");
	scanf("%d",&n);
	printf("\nEnter elements of the array: ");
	insert(arr,n);
	printf("\nArray before sorting:");
	display(arr,n);
	heapsort(arr,n);
	printf("\nArray after sorting:");
	display(arr,n);
	getch();
}
