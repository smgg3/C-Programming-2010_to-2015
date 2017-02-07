#include<stdio.h>
#include<stdlib.h>
int h=0;
main()
{
	struct abc
	{
		int n;
		int bit;
		struct abc *left;
		struct abc *right;
		struct abc *root;
		struct abc *left1;
		struct abc *right1;
	};
	typedef struct abc node;
	int m,s;
	printf("Enter no of elements:");
	scanf("%d",&m);
	node *head,*temp,*p,*temp1,*temp2,*k;
	int i=0;
	for(i=0;i<m;i++)
	{
		printf("Enter numbers:");
		scanf("%d",&s);
		p=(node*)malloc(sizeof(node));
		if(i==0)
		{
			head=p;
			temp=p;
			temp->n=s;
			p->root=NULL;
			temp->left=NULL;
			temp->right=NULL;
			temp->left1=NULL;
			temp->right1=NULL;
		}
		else
		{
			temp->right=p;
			p->left=temp;
			temp=temp->right;
			temp->n=s;
			temp->left1=NULL;
			temp->right1=NULL;
			temp->root=NULL;
			temp->right=NULL;}
		}
void linksort(node *temp)
{
	head=temp;
	temp=temp->right;
	temp1=temp;
	while(temp1!=NULL)
	{
		temp1=temp->right;
		p=temp->left;
		while(temp!=NULL && p->n>temp->n)
		{
			if(p->left==NULL && temp->right==NULL)
			{
				temp->left=NULL;
				p->right=NULL;
				temp->right=p;
				p->left=temp;
				head=temp;
				temp=NULL;
			}
			else if(p->left==NULL && temp->right!=NULL)
			{
				temp->left=NULL;
				p->right=temp->right;
				temp->right->left=p;
				p->left=temp;
				temp->right=p;
				head=temp;
				temp=NULL;
			}
			else if(p->left!=NULL && temp->right==NULL)
			{
				p->right=NULL;
				p->left->right=temp;
				temp->left=p->left;
				p->left=temp;
				temp->right=p;
				p=temp->left;
			}
			else if(p->left!=NULL && temp->right!=NULL)
			{
				temp->left=p->left;
				p->left->right=temp;
				p->right=temp->right;
				temp->right->left=p;
				p->left=temp;
				temp->right=p;
				p=temp->left;
			}
		}
	temp=temp1;}
}
linksort(head);
int c=1;
while(c==1)
{
	temp=head;
	temp1=temp->right;
	if(temp1->right==NULL)
		{c=0;}
	k=(node*)malloc(sizeof(node));
	k->n=temp->n+temp1->n;
	k->root=NULL;
	if(c!=0)
	{
		k->right=temp1->right;
		temp1->right->left=k;
	}
	else
	{	k->left=NULL;
		k->right=NULL;
	}
	k->left=NULL;
	k->left1=temp;
	temp->root=k;
	k->right1=temp1;
	temp->bit=0;
	temp1->root=k;
	temp1->bit=1;
	temp->left=NULL;
	temp1->left=NULL;                
	temp1->right=NULL;
	temp->right=NULL;
	if(c==1)
	{
		linksort(k);
	}
}
printf("***************\n");
printf("preorder of the haffman tree is\n");
int preor(struct abc *temp)
{
	if(temp->left1==NULL&&temp->right1==NULL)
	{
		printf("%d\n",temp->n);
		return 0;
	}
	else
	{
		printf("%d\n",temp->n);
	}
	if(temp->left1!=NULL)
	{
		preor(temp->left1);
	}
	if(temp->right1!=NULL)
	{
	preor(temp->right1);
	}
}
preor(k);
int f;
printf("***************\n");
printf("enter the haffman element:");
scanf("%d",&f);
printf("the haffman code for the given element ");
void find(node *temp,int f)
{
	if(temp->left1==NULL && temp->right1==NULL && temp->n==f)
	{
		h=1;
		temp2=temp;
	}
	else if(temp->left1!=NULL && temp->right1!=NULL)
	{
		if(h==0)
		{
			find(temp->left1,f);
		}
		if(h==0)
		{
			find(temp->right1,f);
		}
	}
}
find(k,f);
printf("%d is:\n",temp2->n);
int bit(node *temp)
{
	if(temp->root==NULL)
	{
		return 0;
	}
	else
	{
		bit(temp->root);
		printf("%d",temp->bit);
	}
}
bit(temp2);
printf("\n");
}

