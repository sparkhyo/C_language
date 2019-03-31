#include <stdio.h>

int main(void)
{
	int num;
	int i,j;

	while(1)
	{
		fputs("홀수 단(1), 짝수 단(2) : ", stdout);
		scanf("%d",&num);

		if(num==1 || num==2)
			break;
		else
			puts("잘못된 입력입니다. 1또는 2만 입력하세요.");
	}

	for(i=2; i<10; i++)
	{	
		if(num==1 && i%2==0)
			continue;
		else if(num==2 && i%2==1)
			continue;

		for(j=1; j<10; j++)
		{
			printf("%d x %d = %d\n",i,j,i*j);
		}
	}

	return 0;
}
