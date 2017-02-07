#include<stdio.h>
palindrome(int num)
{
	int r=0,c,t;
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
main()
{
	int num;
	printf("Enter a number :");scanf("%d",&num);
	palindrome(num);
}
