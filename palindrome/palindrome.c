#include<stdio.h>
main()
{
	int num,r=0,c,t;
	printf("Enter a number :");scanf("%d",&num);
	t=num;
	while(t!=0)
	{	c=t%10;t=t/10;
		r=r*10;
		r=r+c;
	}
	if (r==num)
		printf("Given number is palindrome\n");
	else
		printf("given number is not palindrome\n");
}
