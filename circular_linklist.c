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
		temp->next=head;
	}
	else
	{
		t = head;
		while (t->next != head)
		{
			t = t->next;
		}
		t->next = temp;
		temp->next=head;
	}
}
void insertNodeBeg()
{
	struct node *temp,*ptr;
	temp = createNode();
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	ptr=head;
	temp->next = head;
	while(ptr->next != head)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	head=temp;
}
void insertNodeAf(item)
{
	struct node *temp, *t;
	temp=createNode();
	printf("Enter the item after which the node to be inserted:-");
	scanf("%d", &item);
	printf("Enter the data:-");
	scanf("%d", &temp->data);
	temp->next = NULL;
	t = head;
	while (t->next != head && t->data != item)
	{
		t = t->next;
	}
	if (t == head)
	{
		printf("Item not found\n");
	}
	else
	{
		temp->next = t->next;
		t->next = temp;
	}
}
void deleteNode()
{
	struct node *t, *node;
	t = head;
	node = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		while (t->next != head)
		{
			node = t;
			t = t->next;
		}
		node->next = head;
		free(t);
	}
}
void deleteNodeBeg()
{
	struct node *node,*t;
	node = head;
	t=head;
	if (head == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		while(node->next!=head)
		{
			node=node->next;
		}
		head=t->next;
		node->next=head;
		free(t);
	}
}
void deleteNodeAf(item)
{
	struct node *t, *node;
	printf("Enter the item after which the next node is deleted:-");
	scanf("%d", &item);
	t = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else if (t->data == item && t->next == head)
	{
		printf("This is the single node,deletion can't possible\n");
	}
	else
	{
		while ( t->data!=item  && t!=head)
		{
			t = t->next;
		}
		if (t== head)
		{
			printf("Item not found");
		}
		else if(t->next==head)
		{
			t->next=head->next;
			node=head;
			head=head->next;
			free(node);
		}
		else
		{
			node = t;
			t = t->next;
			node->next = t->next;
			free(t);
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
		do
		{
			printf(" %d ", t->data);
			t = t->next;
		}while(t != head);
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.insert at begining\n3.insert after a given node\n4.delete\n5.delete begining\n6.delete after a given node\n7.display\n8.exit\n");
		printf("Enter your choise:-");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insertNode();
			break;
		case 2:
			insertNodeBeg();
			break;
		case 3:
			insertNodeAf();
			break;
		case 4:
			deleteNode();
			break;
		case 5:
			deleteNodeBeg();
			break;
		case 6:
			deleteNodeAf();
			break;
		case 7:
			display();
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("Invalid Input\n");
		}
	} while (1);
}
