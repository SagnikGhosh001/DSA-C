#include<stdio.h>
void main()
{
	int i,n,j,arr[20],min;
	printf("Enter the term:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element at position %d: ",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
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
