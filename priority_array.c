#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
int r=-1,f=-1;

struct data
{
char job[10];
int priority;
};
typedef struct data data;
data q[max];

void add()
{
int i,j;
data t;
if(r==max-1)
{
printf("\n\n\n\n\t\tQueue is full. No more jobs can be added.");
return;
}
r++;
printf("\n\n\n\n\tEnter job name : ");
scanf("%s",q[r].job);
printf("\n\tEnter job priority : ");
scanf("%d",&q[r].priority);
if(f==-1)
f=0;
for(i=f;i<r;i++)
{
for(j=f;j<r;j++)
{
if(q[j].priority>q[j+1].priority)
{
t=q[j];
q[j]=q[j+1];
q[j+1]=t;
}
}
}
printf("\n\n\tJob successfully added.");
}

void display()
{
int i;
if(f==-1)
{
printf("\n\n\n\n\t\tQueue is empty.");
return;
}
printf("\n\n\n\n\t\t -------------------- ");
printf("\n\n\n\n\t\t JOB PRIORITY ");
printf("\n\n\n\n\t\t -------------------- ");
for(i=f;i<=r;i++)
{
printf("\n\n \t\t %s\t %d",q[i].job,q[i].priority);
}
}

void del()
{
if(f==-1)
{
printf("\n\n\n\n\t\tUNDERFLOW.");
return;
}
printf("\n\n\n\n\t\t Job deleted %s.",q[f].job);
if(f==r)
f=r=-1;
else
f++;
}

main()
{
char choice;
//clrscr();
do
{
printf("\n\n\n\n\t\t1 to add a job\n\n\t\t2 to delete a job\n\n\t\t3 to display all jobs\n\n\t\t4 to exit");
choice=getch();

switch(choice)
{
case '1':
add();break;
case '2':
del();break;
case '3':
display();break;
case '4':
exit(0);break;
}
getch();
//clrscr();
}
while(1);

getch();
}
