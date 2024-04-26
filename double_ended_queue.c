#include<stdio.h>
#include<stdlib.h>
#define size 5
int rear=-1,front=-1,dqueue[size];
void insert_front(data)
{
	if((front==0 && rear==size-1)||(front==rear+1))
		printf("Queue is full");
	else if(rear==-1 && front==-1)
	{
		rear=front=0;
		dqueue[front]=data;
	}
	else if(front==0)
	{
		front=size-1;
		dqueue[front]=data;
	}
	else
	{
		front--;
		dqueue[front]=data;
	}
}
void insert_rear(data)
{
	if((front==0 && rear==size-1)||(front==rear+1))
		printf("Queue is full");
	else if(rear==-1 && front==-1)
	{
		rear=front=0;
		dqueue[rear]=data;
	}
	else if(rear=size-1)
	{
		rear=0;
		dqueue[rear]=data;
	}
	else
	{
		rear++;
		dqueue[rear]=data;
	}
}
void delete_front()
{
	if(rear==-1 && front==-1)
		printf("Queue is empty");
	else if(front==rear)
	{
		printf("%d is deleted eliment",dqueue[front]);
		front=rear=-1;
	}
	else if(front==size-1)
	{
		printf("%d is deleted eliment",dqueue[front]);
		front=0;
	}
	else
		printf("%d is deleted eliment",dqueue[front++]);
}
void delete_rear()
{
	if(rear==-1 && front==-1)
		printf("Queue is empty");
	else if(front==rear)
	{
		printf("%d is deleted eliment",dqueue[rear]);
		front=rear=-1;
	}
	else if(rear==0)
	{
		printf("%d is deleted eliment",dqueue[rear]);
		rear=size-1;
	}
	else
		printf("%d is deleted eliment",dqueue[rear--]);

}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
		printf(" %d",dqueue[i]);
}
void main()
{
	int ch,data;
	do{
	printf("\n1 for insert rear\n2 for insert front\n3 for delete front\n4 for delete rear\n5 display\n6 for exit\n");
	printf("choose:-");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("Enter the data:-");
			scanf("%d",&data);
			insert_rear(data);
			break;
		case 2:
			printf("Enter the data:-");
			scanf("%d",&data);
			insert_front(data);
			break;
		case 3:
			delete_front();
			break;
		case 4:
			delete_rear();
			break;
		case 5:
			printf("Display:-");
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("choose correct option\n");
	}
	}while(1);
}
