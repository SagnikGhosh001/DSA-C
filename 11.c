#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data, item;
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
				printf(" %d ", t->data);
				t = t->next;
			}
		}
	}
}
void deleteNode(item)
{
	struct node *t, *node;
	printf("Enter the value of X:-");
	scanf("%d", &item);
	t = head;
	node=NULL;
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else 
	{
		while (t != NULL && t->data > item) 
		{
       		head = t->next;
       		free(t);
			t = head;
		}
		while (t != NULL)
		{
        	while (t != NULL && t->data <= item) 
			{
        	    node = t;
            	t = t->next;
        	}
        if(t==NULL)
        	return;
        node->next = t->next;
        free(t);
        t = node->next;
   		}
		
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("Enter your choise:-");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insertNode();
			break;
		case 2:
			deleteNode();
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
