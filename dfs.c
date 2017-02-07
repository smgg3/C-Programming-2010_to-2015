#include<stdio.h>
#include<stdlib.h>
int r;
void printArray(int a[][100],int n);
 
void AdjacencyMatrix(int a[][100], int n)
{
    int i,j,e;
    printf("enter the edges\n1-connection\n0-Not connection\n");
    for(i=0;i<n; i++)
    {
        for(j=0;j<n; j++)
        {
 	        printf("enter edge %d to %d:",i,j);
            scanf("%d",&e);
            a[i][j] = e;
            a[j][i] = e;
        }
    	a[i][i] = 0;
    }
    printArray(a,n);
}
 
void printArray(int a[][100],int n){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
 
void dfs(int a[][100],int n,int *s,int u,int *q){
 
    int v;
    s[u]=1;
    for(v=0;v<n;v++)
    {
        if(a[u][v] == 1 && s[v] == 0)
        {
            q[++r] = v;
            dfs(a,n,s,v,q);
        }
    }
}
void printdfs(int a[][100],int n,int *q){
    int i,sor,s[100];
    printf("Enter source less than %d: ",n);
    scanf("%d",&sor);
     
    for(i=0;i<n;i++)
    s[i]=0;
     
    q[0]=sor;
    dfs(a,n,s,sor,q);
     
    for(i=0;i<n;i++)
    {
        if(s[i]!=0)
        {
        printf(" -> %d ",q[i]);
        }
    }
}
 
int main()
{
    int a[100][100],n,*q;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    q = (int *)malloc(sizeof(int)*n);
    AdjacencyMatrix(a,n);
    printdfs(a,n,q);
    getch();
return 0;
}
