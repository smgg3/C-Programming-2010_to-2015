#include<stdio.h>
#include<stdlib.h>
void insert();
void del();
void display();
struct node
{
int priority;
int info;
struct node *link;
}*front = NULL;

main()
{
int choice;
//clrscr();
printf("\n\n PRIORITY QUEUE USING LINKED LIST \n\n");
while(1)
{
printf("\n\n--------------------------- MAIN MENU -------------------------------------\n\n");
printf("1.Insert.\n\n");
printf("2.Delete.\n\n");
printf("3.Display.\n\n");
printf("4.Quit.\n\n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
del();
break;
case 3:
display();
break;
case 4:
exit(1);
default :
printf("INVALID CHOICE TRY AGAIN!!!!!!1\n");
}
}
}

void insert()
{
struct node *tmp,*q;
int added_item,item_priority;
tmp = (struct node *)malloc(sizeof(struct node));
printf("\n------------------------------------------------------------------------------\n");
printf("\nInput the data to be added in the queue : ");
scanf("%d",&added_item);
printf("\n\nEnter its priority : ");
scanf("%d",&item_priority);
printf("\n\n------------------------------------------------------------------------------\n");
tmp->info = added_item;
tmp->priority = item_priority;
if( front == NULL || item_priority < front->priority )
{
tmp->link = front;
front = tmp;
}
else
{
q = front;
while( q->link != NULL && q->link->priority <= item_priority ) q=q->link;
tmp->link = q->link;
q->link = tmp;
}
}
void del()
{
struct node *tmp;
if(front == NULL)
{
printf("\n--------------------------------------------------------------------");
printf("\n\nQueue Underflow\n");
printf("\n------------------------------------------------------------------------");
}
else
{
tmp = front;
printf("\n----------------------------------------------------------------------------\n");
printf("\n\nDeleted data is %d\n",tmp->info);
printf("\n-----------------------------------------------------------------------------\n\n");
front = front->link;
free(tmp);
}
}

void display()
{
struct node *ptr;
ptr = front;
if(front == NULL)
{
printf("\n-----------------------------------------------------------------------");
printf("\n\nQueue is empty\n");
printf("\n--------------------------------------------------------------------------");
}
else
{
printf("\n\n---------------------- Queue --------------------------------\n\n");
printf("Priority\tData\n\n");
while(ptr != NULL)
{
printf("%d \t\t%d\n\n",ptr->priority,ptr->info);
ptr = ptr->link;
}
}
}
