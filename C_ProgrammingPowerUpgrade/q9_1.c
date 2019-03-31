#include <stdio.h>

int main(void)
{
	int num, sum;
	fputs("1 이상의 정수 입력 : ", stdout);
	scanf("%d",&num);

	if(num < 1)
	{
		while(num < 1)
		{
			fputs("1 이상의 정수를 입력해야 합니다.\n", stdout);
			fputs("1 이상의 정수 입력 : ", stdout);
			scanf("%d",&num);
		}
	}

	sum = num*(num+1)/2;

	printf("1부터 %d까지의 합은 %d.\n",num,sum);

	return 0;
}
