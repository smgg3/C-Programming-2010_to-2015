#include<stdio.h>
/* Node definition */ 
struct node
{
	int data;		// data part in the node
	struct node *next;	// reference to next element
};

void input (char *prompt, int *num);
void insert_last(struct node **head, int num);
void insert_first(struct node **head, int num);
void display(struct node *head);
void insert_desired(struct node **head,int src, int dest);
void delete_first(struct node **head);
void delete_last(struct node **head);


void delete_desired(struct node **head, int num);
void reverse(struct node **head);

/* main method */
main()
{
	struct node *head;	// node pointer to represent linked list
	head = NULL;		// empty linked list
	int choice, num, num1;	
	do
	{	
		printf("\n1. Inert at first");
		printf("\n2. Inert at last");
		printf("\n3. Inert at desire place");
		printf("\n4. Delete first");
		printf("\n5. Delete last");
		printf("\n6. Delete desire element");
		printf("\n7. Display List");
		printf("\n8. Reverse List");
		printf("\n9. Exit");
		printf("\n\n\t Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				input("Enter element to insert: ",&num);
				insert_first(&head,num);
				break;
			case 2:
				input("Enter element to insert: ",&num);
				insert_last(&head,num);
				break;
			case 3:
				input("Enter the source element: ",&num);
				input("Enter the element to insert: ",&num1);
				insert_desired(&head, num, num1);
				break;
			case 4:
				delete_first(&head);
				break;
			case 5:
				delete_last(&head);
				break;
			case 6:
				input("Enter element to delete: ",&num);
				delete_desired(&head,num);
				break;
			case 7:
				display(head);
				break;
			case 8:
				reverse(&head);
				break;
			case 9:
				exit(0);
		}
	}while(choice!=9);
}

void input (char *prompt, int *num)
{
	printf(prompt);
	scanf("%d",num);
}

void reverse(struct node **head)
{
	if(*head==NULL)
	{
		printf("Linked List is empty!!");
	}	
	else
	{
		struct node *p, *q, *r;
		p = *head;
		q = p->next;
		p->next = NULL;
		
		while(q!=NULL)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		*head = p;				
	}
}
void delete_last(struct node **head)
{
	if(*head==NULL)
	{
		printf("There are no elements in the list!!");
	}
	else
	{
		struct node *temp;
		temp = *head;
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
}

void delete_desired(struct node **head, int num)
{
	if(*head==NULL)
	{
		printf("There are no elements in the list!!");
	}
	else if((*head)->data == num)
	{
		*head = (*head)->next;
	}	
	else
	{
		struct node *temp;
		temp = malloc(sizeof(struct node));
		temp = *head;
		while(temp->next!=NULL && temp->next->data!=num)
		{
			temp = temp->next;
		}
		if(temp->next==NULL)
		{
			printf("There is no such element in the list");
		}
		else
		{
			temp->next = temp->next->next;
		}
	}
}

void delete_first(struct node **head)
{
	if(*head==NULL)
	{
		printf("There are no elements in the linked list!!");
	}
	else
	{
		*head = (*head)->next;
	}
}
void insert_desired(struct node **head,int src, int dest)
{
	struct node *link, *temp;
	link = (struct node *)malloc(sizeof(struct node));
	link->data = dest;
	link->next = NULL;
	temp = *head;	
	
	while(temp!=NULL)
	{
		if(temp->data==src)
		{
			break;
		}
		temp=temp->next;
	}
	
	if(temp==NULL)
	{
		printf("Sorry! Source element was not found in the list");
	}
	
	else
	{
		link->next = temp->next;		
		temp->next = link;
	}
}
/* function to insert element at last */
void insert_last(struct node **head, int num)
{
	struct node *link;
	link = (struct node *)malloc(sizeof(struct node));
	link->data = num;
	link->next = NULL;
	
	if(*head == NULL)
	{
		*head = link;
	}
	else
	{
		struct node *temp;
		temp = *head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = link;		
	}
}

/* function to insert element at first */
void insert_first(struct node **head, int num)
{
	struct node *link;
	link = (struct node *)malloc(sizeof(struct node));
	link->data = num;
	link->next = NULL;

	if(*head==NULL)
	{
		*head = link;
	}
	else
	{
		link->next = *head;
		*head = link;
	}
}

/* function to display list */
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}




