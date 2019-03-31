#include <stdio.h>

int main(void)
{
	int num1, num2;
	int max;
	fputs("두 개의 숫자를 입력하세요 : ", stdout);
	scanf("%d %d",&num1,&num2);

	max = num1>num2 ? num1 : num2;

	printf("큰 수는 %d\n",max);

	return 0;
}
