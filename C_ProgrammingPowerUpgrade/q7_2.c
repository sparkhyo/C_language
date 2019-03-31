#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	int max;
	fputs("세 개의 숫자를 입력하세요 : ", stdout);
	scanf("%d %d %d",&num1,&num2,&num3);

	max = num1>num2 ? 
		num1>num3 ?
		num1 : num3
		: 
		num2>num3 ?
		num2 : num3
		;

	printf("큰 수는 %d\n",max);

	return 0;
}
