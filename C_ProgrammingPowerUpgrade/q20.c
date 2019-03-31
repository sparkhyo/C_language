#include <stdio.h>
#define	DONT_DIV	-256

int DivInt(int * pnum1, int * pnum2)
{
	int num;
	num = *pnum1;

	if(*pnum2 == 0)
		return DONT_DIV;

	else
	{
		*pnum1 = num / *pnum2;
		*pnum2 = num % *pnum2;

		return 1;
	}
}

int main(void)
{
	int num1,num2,ret;

	while(1)
	{
		fputs("나눗셈 위한 두 정수 입력 : ", stdout);
		scanf("%d %d", &num1, &num2);
		
		ret = DivInt(&num1,&num2);

		if (ret == DONT_DIV)
			fputs("0으로 나누는 오류발생! 숫자 재 입력\n", stdout);

		else
			break;
	}
	
	printf("몫 : %d, 나머지 : %d\n",num1,num2);
	
	return 0;
}
