#include<stdio.h>
void main()
{
	int i,n,j,arr[5],min,temp;
	printf("Enter the term:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the element:-");
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
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	for(i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
}
