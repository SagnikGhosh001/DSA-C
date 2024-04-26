#include<stdio.h>

void insertionSort(int n)
{
	int i,j,arr[10];
		for(i=0;i<n;i++)
	{
		printf("Enter the element at position %d: ",i);
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		int key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
		 arr[j+1]=arr[j];
		 j--;
		}
		arr[j+1]=key;
	}
	for(i=0;i<n;i++)
	{
	printf(" %d ",arr[i]);
	}
}
void selectionSort(n)
{
	int i,j,min,arr[10];
	for(i=0;i<n;i++)
	{
		printf("Enter the element at position %d: ",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	for(i=0;i<n;i++)
	{
	printf(" %d ",arr[i]);
	}
}
int main()
{
	int n,opt,arr[10];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Note - 1.Insertion Sort\n2.Selection Sort\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			insertionSort(n);
			break;
		case 2:
			selectionSort(n);
			break;
	}
}
