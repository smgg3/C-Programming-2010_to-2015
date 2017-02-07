#include<stdio.h>
int palindrome(int num)
{
	int r=0,c,t;
	t=num;
	while(t!=0)
	{	c=t%10;t=t/10;
		r=r*10;
		r=r+c;
	}
	return r;
}
main()
{
	int num,r;
	printf("Enter a number :");scanf("%d",&num);
	r=palindrome(num);
	if (r==num)
		printf("Given number is palindrome\n");
	else
		printf("given number is not palindrome\n");
}
