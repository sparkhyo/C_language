#include <stdio.h>

int main(void)
{
	int num;
	int i,j,k;
	int sum = 0;

	fputs("정수 입력 : ", stdout);
	scanf("%d",&num);

	for(i=0; i<=100; i++)
	{
		for(j=0; j<=100; j++)
		{
			for(k=0; k<=100; k++)
			{
				sum = i*j-k;
				if(num==sum)
				{
					printf("(%d) x (%d) - (%d) = (%d)\n",i,j,k,sum);
				}
			}
		}
	}

	return 0;
}
