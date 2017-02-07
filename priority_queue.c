#include<stdio.h>
#include<stdlib.h>
struct node
{
	int priority;
	int data;
	struct node *link;
}*front=NULL;
void insertMax();
void insertMin();
void delete();
void Maxelement();
void Minelement();
void displayQueue();
int main()
{
	int choice;
	printf("1.For Maximum priority Queue\t 2.For Minimum Priority Queue\n");
	printf("Enter ur choice :\t");
	scanf("%d",&choice);
	if(choice==1)
		{
			while(1)
				{
				int option;
				printf("1)Insertion 2)Deletion 3)Max-element 4)Display 5)Exit\n");
				printf("Enter ur option :\t");
				scanf("%d",&option);
				if (option==1)
					insertMax();
				else if(option==2)
					delete();
				else if(option==3)
					Maxelement();
				else if(option==4)
					displayQueue();
				else if(option==5)
					break;
				else
					printf("Wrong Selection.Try again\n");
				}
			}
	else if (choice==2)
		{
			while(1)
				{
			int option;
			printf("1)Insertion 2)Deletion 3)Min-element 4)Display 5)Exit\n");
			printf("Enter ur option :\t");
			scanf("%d",&option);
			if(option==1)
				insertMin();
			else if(option==2)
				delete();
			else if(option==3)
				Minelement();
			else if(option==4)
				displayQueue();
			else if(option==5)
				break;
			else
				printf("Wrong Selection.Try again\n");
			}
		}
	else
		printf("Wrong Selection. Try again\n");
}
void insertMax()
{
	struct node *temp,*temp2;
	temp=(struct node*)malloc(sizeof(struct node));
	temp2=(struct node*)malloc(sizeof(struct node));
	int item,item_priority;
	printf("Enter ur data:\t");
	scanf("%d",&item);
	printf("Enter ur data priority:\t");
	scanf("%d",&item_priority);
	temp->data=item;
	temp->priority=item_priority;
	
	if(front==NULL)
		{
			
			temp->link=front;
			front=temp;
			
		}
	else if(item_priority>front->priority)
		{
			
			temp->link=front;
			front=temp;
			
			
		}
	else
		{
			temp2=front;
			while(temp2->link !=NULL && temp2->link->priority >= item_priority )
				temp2=temp2->link;
			temp->link=temp2->link;
			temp2->link=temp;
		}
}
void insertMin()
	{
		struct node *temp,*temp2;
		temp=(struct node*)malloc(sizeof(struct node));
		temp2=(struct node*)malloc(sizeof(struct node));
		int item,item_priority;
		printf("Enter ur data:\t");
		scanf("%d",&item);
		printf("Enter ur data priority:\t");
		scanf("%d",&item_priority);
		temp->data=item;
		temp->priority=item_priority;
		if(front==NULL || item_priority < front->priority)
			{
				temp->link=front;
				front=temp;
			}
		else
			{
				temp2=front;
				while(temp2->link !=NULL && temp2->link->priority <= item_priority )
					temp2=temp2->link;
				temp->link=temp2->link;
				temp2->link=temp;
			}
	}
void delete()
{
	struct node *temp;
	if (front ==NULL)
		{
			printf("\n\nQueue Underflow\n");
		}
	else if(front->link==NULL)
		{
			free(front);
			front=NULL;
		}
	else
		{
			temp=front;
			printf("\n\nDeleted data is %d\n",temp->data);
			front=front->link;
			free(temp);
		}
}
void Maxelement()
{
	printf("Maximum element in Priority Queue is:\t%d\n",front->data);
}
void Minelement()
{
	printf("Minimum element in Priority Queue is:\t%d\n",front->data);
}
void displayQueue()
{
	struct node *ptr;
	ptr=front;
	if (front ==NULL)
		printf("Queue is Empty\n");
	else
		{
			printf("\tPriority\t\tData\n\n");
			while(ptr!=NULL)
				{
					printf("\t%8d\t%8d\n",ptr->priority,ptr->data);
					ptr=ptr->link;
				}
		}
}
