#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head = NULL;
struct node *createNode()
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node));
	return n;
}
void insertNode()
{
	struct node *temp, *t;
	temp = createNode();
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	temp->prev= NULL;
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
		temp->prev= t;
	}
}
void insertNodeBeg()
{
	struct node *temp;
	temp = createNode();
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->next = head;
	temp->prev=NULL;
	head->prev = temp;
	head=temp;
}
void insertNodeIn()
{
	struct node *temp, *t, *ptr ;
	int index,count=0;
	temp=createNode();
	printf("Enter the index:-");
	scanf("%d", &index);
	printf("Enter the data:-");
	scanf("%d", &temp->data);
	temp->next = NULL;
	temp->prev=NULL;
	t = head;
	if(head==NULL)
		printf("list is empty\n");
	else if(count==index)	
	{
		temp->next = head;
		temp->prev=NULL;
		head->prev = temp;
		head=temp;
	}
	else
	{
		while (t != NULL &&  (count+1)!= index)
		{
			t = t->next;
			count++;
		}
		if (t == NULL)
		{
			printf("out of index\n");
		}
		else if(t->next==NULL)
		{
			t->next=temp;
			temp->prev=t;
		}
		else
		{
			ptr=t->next;
			ptr->prev=temp;
			temp->next=ptr;
			temp->prev=t;
			t->next=temp;
		}
	}
}
void insertNodeAf(item)
{
	struct node *t,*temp, *ptr;;
	temp=createNode();
	printf("Enter the item after which next node to be inserted:-");
	scanf("%d",&item);
	printf("Enter the data:-");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	t=head;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		while(t!=NULL && t->data!=item)
		{
			t=t->next;
		}
		if(t->next==NULL)
		{
			t->next=temp;
			temp->prev=t;
		}
		else if(t->next==NULL)
		{
			t->next=temp;
			temp->next=t;
		}
		else
		{
			ptr=t->next;
			ptr->prev=temp;
			temp->next=ptr;
			temp->prev=t;
			t->next=temp;
		}
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
		while (t->next != NULL)
		{
			node = t;
			t = t->next;
		}
		node->next = NULL;
		free(t);
	}
}
void deleteNodeBeg()
{
	struct node *node;
	node = head;
	if (head == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		head = head->next;
		head->prev=NULL;
		free(node);
	}
}
void deleteNodeAf(item)
{
	struct node *t, *node, *ptr;
	printf("Enter the item after which the next node is deleted:-");
	scanf("%d", &item);
	t = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else if (t->data == item && t->next == NULL && t->prev==NULL)
	{
		printf("Deletion not possible");
	}
	else
	{
		while (t != NULL && t->data != item)
		{
			t = t->next;
		}
		if(t->next==NULL)
		{
			printf("delition not possible last node");
		}
		else if(t->next->next==NULL)
		{
			node=t;
			t=t->next;
			node->next=NULL;
			free(t);
		}
		else
		{
			node = t;
			t = t->next;
			ptr=t->next;
			node->next = ptr;
			ptr->prev=node;
			free(t);
		}
	}
}
void deleteNodeIn()
{
	struct node *t, *node, *ptr ;
	int index,count=0;
	printf("Enter the index:-");
	scanf("%d", &index);
	t = head;
	node=head;
	if(head==NULL)
		printf("list is empty\n");
	else if (count==index && t->next == NULL && t->prev==NULL)
	{
		head=NULL;
	}
	else if (count==index && t->prev==NULL)
	{
		head = head->next;
		head->prev=NULL;
		free(node);
	}
	else
	{
		while (t != NULL &&  (count+1)!= index)
		{
			t = t->next;
			count++;
		}
		if (t == NULL)
		{
			printf("out of index\n");
		}
		else if(t->next->next==NULL)
		{
			t=t->next;
			node=t->prev;
			node->next=NULL;
			free(t);
		}
		else
		{
			t=t->next;
			node = t->prev;
			ptr=t->next;
			ptr->prev=node;
			node->next=ptr;
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
		{
			while (t != NULL)
			{
				printf(" %d ", t->data);
				t = t->next;
			}
		}
	}
}
void reverse()
{
	struct node *t;
	if(head==NULL)
		printf("List is empty");
	else
	{
		t=head;
		while(t->next!=NULL)
			t=t->next;
		while(t!=NULL)
		{
			printf(" %d ",t->data);
			t=t->prev;
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.insert at begining\n3.insert given index\n4.insert after a given node\n5.delete\n6.delete begining\n7.delete given index\n8.delete after a given node\n9.display\n10.reverse\n11.exit\n");
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
			insertNodeIn();
			break;
		case 4:
			insertNodeAf();
			break;
		case 5:
			deleteNode();
			break;
		case 6:
			deleteNodeBeg();
			break;
		case 7:
			deleteNodeIn();
			break;
		case 8:
			deleteNodeAf();
			break;
		case 9:
			display();
			break;
		case 10:
			reverse();
			break;
		case 11:
			exit(0);
			break;
		default:
			printf("Invalid Input\n");
		}
	} while (1);
}
