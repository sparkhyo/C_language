#include <stdio.h>
#define ARRNUM	10

int main(void)
{
	int num, i;
	int arr[ARRNUM];

	fputs("10진수 정수 입력 : ", stdout);
	scanf("%d",&num);
	printf("%d를 2진수로 변환하면 : ",num);

	for(i=0; i<ARRNUM; i++)
	{	
		if(num == 0)
			break;
		arr[i] = num % 2;
		num = num / 2;
	}

	for(i=ARRNUM-1; i>-1; i--)
	{
		printf("%d",arr[i]);
	}
	fputs("\n",stdout);
	return 0;
}
