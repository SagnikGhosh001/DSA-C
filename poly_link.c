#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data,exp, item;
	struct node *next;
};
struct node *head = NULL;
struct node *createNode()
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node *));
	return n;
}
void insertNode()
{
	struct node *temp, *t;
	temp = createNode();
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	printf("Enter the exp: ");
	scanf("%d", &temp->exp);
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		t = head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
}
void sum()
{
	struct node *t,*n,*temp;
	int sum;
	sum=0;
	t=head;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
	while (t->exp != 0)
	{
		t=t->next;
	}
	n=t->next;
	temp=n;
	while(n != NULL)
	{
		t=head;
		while(t != temp)
		{
			if(t->exp==n->exp)
			{
				sum=t->data+n->data;
				printf(" sum:-%d exp-X^%d",sum,t->exp);
				t=t->next;
			}
			else
				t=t->next;
		}
		n=n->next;
	}
	}
}
void display()
{
	struct node *t;
	if (head == NULL)
		printf("list is empty\n");
	else
	{
		t = head;
		{
			while (t != NULL)
			{
				printf("data:- %d ", t->data);
				printf("exp:- X^%d ", t->exp);
				t = t->next;
			}
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.sum\n3.display\n4.exit\n");
		printf("Enter your choise:-");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insertNode();
			break;
		case 2:
			sum();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid Input\n");
		}
	} while (1);
}
