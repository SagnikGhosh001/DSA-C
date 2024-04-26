#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 3
int queue[size],front=-1,rear=-1;
void enqueue(int x)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else if((rear+1)%size==front)
	{
		printf("queue is full");
	}
	else
	{
		rear=(rear+1)%size;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1&& rear==-1)
	{
		printf("Queue is empty:");
		return;
	}
	else if(front==rear)//only one element
	{
		front=rear=-1;
	}
	else
	{
		printf("deleted element is: %d",queue[front]);
		front=(front+1)%size;
	}
}
void disp()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		while(i!=rear)
		{
			printf(" %d ",queue[i]);
			i=(i+1)%size;
		}
		printf("%d",queue[rear]);
	}
}
void main()
{
	int ch,x;
	do{
		printf("\nenter your choice: \n");
	printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter the data: ");
			scanf("%d",&x);
			enqueue(x);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			disp();
			break;
		case 4:
			exit(0);
		default:printf("choose correct option");
	}
	}while(1);
	

}
