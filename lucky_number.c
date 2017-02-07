//Don't printf() anything except output
#include<stdio.h>
int main()
{
	int A,B,i,j,k=0,l=0,m,n=0;
	scanf("%d%d",&A,&B);
	if(B>=10^10)
		exit(0);
	for(i=A;A>=1&&i<=B&&i<=10^18;i++)
		{	j=i;
			int k=0,l=0;
			while(j!=0)
				{k=k+j%10;
				l=l+((j%10)*(j%10));
				j=j/10;
				}
			int c=0,d=0;	
			for(m=1;m<=k;m++)
				if(k%m==0)
					{c++;
					if(c>2)
						m=k+1;}
			for(m=1;m<=l;m++)
				if(l%m==0)
					{d++;
					if(d>2)
						m=l+1;}
			if(c==2&&d==2)
				n++;
				
		}
	printf("%d",n);
	return 0;
}
