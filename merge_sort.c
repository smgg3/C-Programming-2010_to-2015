/*
OBJECTIVE:To write a program for mergesort algorithm
*/
#include<stdio.h>
void divide(int arrary[],int low,int high);
void merge(int arrary[],int low,int mid,int high);
int main()
	{
		int length,i;
		printf("Enter the length of the list:\t");
		scanf("%d",&length);
		int array[length];
		printf("Enter the elements to the list:\n");
		for(i=0;i<length;i++)
			scanf("%d",&array[i]);
		printf("********************************\n");
		divide(array,0,length-1);
		printf("The sorted array is :\n");
		for (i=0;i<length;i++)
			printf("%d ",array[i]);
		printf("\n********************************\n");
		return 0;
	}
void divide(int array[],int low,int high)
	{
		int mid,k;
		if (low<high)
			{
			mid=(low+high)/2;
			divide (array,low,mid);
			divide (array,mid+1,high);
			merge(array,low,mid,high);
			
			}
	}
void merge(int array[],int low,int mid,int high)
	{
		int i=low,j=mid+1,k=low,l;
		int temp[high+1];
		while((i<=mid)&&(j<=high))
			{
			if (array[i]<=array[j])
				temp[k++]=array[i++];
			else
				temp[k++]=array[j++];
			}
		if (i>mid)
			for (l=j;l<=high;l++)
				temp[k++]=array[l];
		else
			for (l=i;l<=mid;l++)
				temp[k++]=array[l];
		for(l=low;l<=high;l++)
			array[l]=temp[l];	

	}
