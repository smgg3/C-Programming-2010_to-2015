/*
Aim : To write an program for counting sort.

Input : An array which is to be sorted.

Output : Return an array which is sorted.

*/
#include <stdio.h>
void counting_sort(int arr1[],int max,int len);
void counting_sort(int arr1[],int max,int len1)
	{
		int i,j,k;
		int arr2[max+1],arr3[len1];
		for(i=0;i<=max;i++)
			{
				arr2[i]=0;
			}
		for(j=0;j<len1;j++)
			{
				arr2[arr1[j]]++;
			}
		for(i=1;i<=max;i++)
			{
				arr2[i]=arr2[i]+arr2[i-1];
			}
		for(k=0;k<len1;k++)
			{
				arr3[arr2[arr1[k]]-1]=arr1[k];
				arr2[arr1[k]]--;
			}
		for(i=0;i<len1;i++)
			arr1[i]=arr3[i];

	}
int main()
	{
		int l,i,j;
		printf("Enter the length of ur array:\t");
		scanf("%d",&l);
		int arr[l];
		for (i=0;i<l;i++)
			{
				printf("Enter the %d element of the arrary:\t",i);
				scanf("%d",&arr[i]);
			}
		int max=arr[0];
		for (j=0;j<l;j++)
			{
				if (max<arr[j])
					max=arr[j];
			}
		printf("The maximum element in the array is :\t%d",max);
		printf("\nBefor count sort the array is :\n\t");
		for (i=0;i<l;i++)
			printf("%d\t",arr[i]);
		printf("\n");
		counting_sort(arr,max,l);
		printf("\nAfter count sort the array is :\n\t");
		for (i=0;i<l;i++)
			printf("%d\t",arr[i]);
		printf("\n");
		return 0;
	}
