#include<stdio.h>
#include<stdlib.h>
#define size 5
int rear=-1,front=-1,queue[size];
void insert(data)
{
	if(rear==size-1)
		printf("Queue is full");
	else if(rear==-1 && front==-1)
	{
		rear=front=0;
		queue[rear]=data;
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}
void delete()
{
	if(rear==-1 && front==-1)
		printf("Queue is empty");
	else if(front==rear)
		front=rear=-1;
	else 
		printf("%d is delted eliment",queue[front++]);
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
		printf(" %d",queue[i]);
}
void main()
{
	int ch,data;
	do{
	printf("\n1 for insert\n2 for delete\n3 for display\n4 for exit\n");
	printf("choose:-");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("Enter the data:-");
			scanf("%d",&data);
			insert(data);
			break;
		case 2:
			delete();
			break;
		case 3:
			printf("Display:-");
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("choose correct option\n");
	}
	}while(1);
}
