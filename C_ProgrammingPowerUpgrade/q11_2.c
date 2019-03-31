#include <stdio.h>

int main(void)
{
	int num,i;
	int total=0;
	
	while(1)
	{
		fputs("2이상 입력 : ", stdout);
		scanf("%d",&num);

		if(num>2)
			break;
		else
			puts("2이상의 수가 아닙니다. 다시 입력 해주세요.");
	}

	for(i=1; i<=num; i++)
	{
		total+=i;
		if(total>num)
		{
			printf("%d를 더할 때 처음 %d를 넘기 시작한다.\n",i,num);
			printf("%d를 넘기 이전의 합 : %d\n", num, total-i);
			printf("%d를 넘기 이후의 합 : %d\n", num, total);
			break;
		}
	}

	return 0;
}
