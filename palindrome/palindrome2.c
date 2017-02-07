#include<stdio.h>
int palindrome()
{
	int num,r=0,c,t;
	printf("Enter a number :");scanf("%d",&num);
	t=num;
	while(t!=0)
	{	c=t%10;t=t/10;
		r=r*10;
		r=r+c;
	}
	printf("%ld\n",r);
	if(num==r)
		return 1;
	return 0;
}
main()
{
	int r;
	r=palindrome();
	if (r==1)
		printf("Given number is palindrome\n");
	else
		printf("given number is not palindrome\n");
}
