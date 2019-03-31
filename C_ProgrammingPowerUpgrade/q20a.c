#include <stdio.h>
#define DIVIDE_BY_ZERO	-256

int DivInt(int, int, int*);

int main(void)
{
	int dd, ds;
	int result[2];

	while(1)
	{
		fputs("나눗셈 위한 두 정수 입력 : ", stdout);
		scanf("%d %d", &dd, &ds);

		if(DivInt(dd,ds,result) == DIVIDE_BY_ZERO)
		{
			printf("0으로 나누는 오류발생! 숫자 재 입력 \n\n");
			continue;
		}
		else
		{
			printf("몫 : %d, 나머지 : %d \n", result[0], result[1]);
			break;
		}
	}
	return 0;
}

int DivInt(int divid, int divisor, int * resultArr)
{
	if(divisor == 0)
		return DIVIDE_BY_ZERO;

	resultArr[0] = divid/divisor;
	resultArr[1] = divid%divisor;
	return 1;
}
