#include<stdio.h>
void main()
{
	int i,n,j,arr[5],key;
	printf("Enter the term:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the element:-");
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	for(i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
}
