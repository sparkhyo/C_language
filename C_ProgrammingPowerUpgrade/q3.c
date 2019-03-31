#include <stdio.h>

int main(void)
{
	int a,b;

	printf("두 수를 16진수로 입력 : ");
	scanf("%x %x",&a,&b);

	printf("연산 결과 8진수 : %o\n",a+b);
	printf("연산 결과 10진수 : %d\n",a+b);
	printf("연산 결과 16진수 : %x\n",a+b);

	return 0;
}
