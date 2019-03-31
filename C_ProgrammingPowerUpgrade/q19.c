#include <stdio.h>

int Factorial(int num)
{	
	if(num == 0)
		return 1;
	else
		return  num * Factorial(num-1);
	
}

int main(void)
{	
	int num;

	while(1)
	{
		fputs("숫자 입력(1이상) : ", stdout);
		scanf("%d",&num);

		if(num < 1)
			fputs("입력이 잘못되어 예상치 못한 결과를 얻었습니다.\n", stdout);
		else
			break;
	}
	
	printf("%d! = %d\n",num,Factorial(num));

	return 0;
}
