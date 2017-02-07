#include<stdio.h>//counting sort...................
main()
{
	int l;
	printf("Enter array length:");
	scanf("%d",&l);
	int a[l],b[l],i,max,k=l;
	printf("Enter array:\n");
	for(i=0;i<l;i++)scanf("%d",&a[i]);max=a[0];
	for(i=1;i<l;i++)if(max<a[i])max=a[i];
	int m[max+1],u[max];u[0]=0;
	for(i=0;i<(max+1);i++)m[i]=0;
	for(i=0;i<l;i++)m[a[i]]=m[a[i]]+1;m[-1]=0;
	for(i=1;i<=(max);i++)m[i]=m[i]+m[i-1];
	for(i=1;i<=max;i++)u[i]=m[i-1];
	while((--k)+1){b[u[a[k]]]=a[k];u[a[k]]=u[a[k]]+1;}
	printf("UR SORTED ARRAY:[ ");
	for(i=0;i<l;i++)printf("%d ",b[i]);
	printf("]\n");
}
