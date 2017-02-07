#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *link;
	struct node *lc;
	struct node *rc;
};
struct node1
{
	int data1,type,new;
	struct node1 *next;
};
int print2(struct node1 *p)
{
	int i=0;
	while(p!=NULL)
	{	printf("%d %d %d\n",p->data1,p->type,p->new);p=p->next;}
}
struct node *sort(struct node **p)
{	int i;
	struct node *temp=*p,*kemp,*r;
	while(temp!=NULL)
	{	kemp=*p;
		while(kemp!=NULL)
		{
			if((temp->data)<(kemp->data))
			{	i=temp->data;
				temp->data=kemp->data;
				kemp->data=i;
				r=temp->lc;
				temp->lc=kemp->lc;
				kemp->lc=r;
				r=temp->rc;
				temp->rc=kemp->rc;
				kemp->rc=r;}
			kemp=kemp->link;
		}
	temp=temp->link;
	}
}
struct node *insert(struct node **p,int m)
{
	struct node *t=*p;
	if(*p==NULL)
	{
		*p=(struct node *)malloc(sizeof(struct node));
		if(*p==NULL)
		{	printf("Error\n");exit(0);}
		(*p)->data=m;
		(*p)->left=NULL;
		(*p)->link=NULL;		
	}
	else
	{
		while(t->link!=NULL)
		t=t->link;
		t->link=(struct node *)malloc(sizeof(struct node));
		t->link->data=m;
		t->link->left=t;
		t->link->link=NULL;
	}
}
int print(struct node *p)
{	int l=0;
	while(p!=NULL)
	{	printf("%d\n",p->data);p=p->link;l++;}
	return l;
}
struct node *min(struct node **d)
{	struct node *t;
	if((*d)!=NULL)
	{	t=*d;(*d)=(*d)->link;}
	return t;
}
struct node1 *add(int min1,int type1,int new,struct node1 **k)
{
	int i;
	struct node1 *temp=*k;
	//i=print2(*k);
	if((*k)==NULL)
	{
		(*k)=(struct node1 *)malloc(sizeof(struct node1));
		(*k)->data1=min1;
		(*k)->type=type1;
		(*k)->new=new;
		(*k)->next=NULL;
	}
	else{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=(struct node1 *)malloc(sizeof(struct node1));
		temp->next->data1=min1;
		temp->next->type=type1;
		temp->next->new=new;
		temp->next->next=NULL;
	}//i=print2(*k);
}
struct node *creat(struct node **p,struct node1 **u)
{	int n,y,h;
	struct node *min1,*min2,*new=NULL,*temp=*p;
	min1=min(p);
	min2=min(p);
	n=min1->data+min2->data;
	add(min1->data,0,n,u);
	add(min2->data,1,n,u);
	printf("min1:%d\nmin2:%d\nnewnode:%d\n",min1->data,min2->data,n);
	new=(struct node *)malloc(sizeof(struct node));
	new->data=n;
	new->lc=min1;
	new->rc=min2;
	min1->left=min2->left=new;
	min1->link=min2->link=NULL;temp=*p;
	
	if(temp!=NULL)
	{
		while(temp->link!=NULL)temp=temp->link;
		temp->link=new;
	}
	else
		(*p)=new;
}
struct node *pprint(struct node *d)
{
	char s[100];int i=0;struct node *t=d;
	printf("Enter path to find the element:\n");
	gets(s);
	while(t!=NULL)
	{t=t->rc;
		}
	t=d;
	while(s[i]!='\0')
	{
		if(((int)s[i])=='0')
		{	if(d->lc!=NULL)
				d=d->lc;
			else {printf("Error:\nElement doesn't exists in this path\n");return;}}
		else if(((int)s[i])=='1')
		{	if(d->rc!=NULL)
				d=d->rc;
			else {printf("Error:\nElement doesn't exists in this path\n");return;}}
		i++;
	}printf("The element is:%d\n",d->data);d=t;return;
	
}
struct node1 *search(struct node1 *d,int i,int e)
{
	int l,j=0,k,c;struct node1 *t=d;char s[1];
	while(t->next!=NULL)t=t->next;l=t->data1;t=d;
	while((t->next!=NULL)&&(t->data1!=e))t=t->next;
	if((t->next==NULL)&&(t->data1!=e)){printf("(MAY BE IT IS ROOT)NUMBER DOESN'T EXIST:\n");return;}
	while(e!=l)
	{
		if(t->type==0){s[j]='0';j++;}
		else if(t->type==1){s[j]='1';j++;}
		e=t->new;
		while(t->data1!=e)t=t->next;
	}
	if(t->type==0){s[j]='0';j++;}else if(t->type==1){s[j]='1';j++;}
	for(i=0;s[i];i++);i=i-1;
	printf("The Path:");
	for(;i;--i)printf("%c",s[i-1]);
	printf("\n");
}
main()
{
	struct node *a=NULL;struct node1 *b=NULL,*temp;
	int i,n,m,l,g,k=1;
	char c;
	printf("Enter array length:");
	scanf("%d",&n);
	printf("Enter array:");
	for(i=0;i<n;i++){scanf("%d",&m);insert(&a,m);}
	sort(&a);
	printf("THE LIST:\n");
	l=print(a);
	while(l!=1)
	{	creat(&a,&b);sort(&a);printf("NEW LIST:\n");l=print(a);
	}
	c=getchar();
	temp=b;
	while(temp->next!=NULL)temp=temp->next;
	temp->next=(struct node1 *)malloc(sizeof(struct node1));
	temp->next->data1=temp->new;
	temp->next->next=NULL;
	i=print2(b);
	while(k){
		printf("Enter number u want to search:");
		scanf("%d",&g);
		search(b,i,g);
		printf("Enter '1' if u want to continue(To enter a number) else '0':\n");
		scanf("%d",&k);
		
	}k=1;
	while(k){pprint(a);
		printf("Enter '1' if u want to continue(To enter a path) else '0':\n");
		scanf("%d",&k);
		c=getchar();	
		}
	
}
