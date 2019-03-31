#include <stdio.h>

int main(void)
{
	int num1, num2, sum;
	int tmp;
	
	fputs("두 개의 정수 입력 : ", stdout);
	scanf("%d %d", &num1,&num2);
	
	if(num1 < num2)
	{
		sum = num2*(num2+1)/2 - (num1-1)*num1/2;
		printf("%d과 %d를 포함하여 그 사이에 있는 정수들의 합 : %d\n",num1,num2,sum);
	}
	else if(num1 > num2)
	{
		sum = num1*(num1+1)/2 - (num2-1)*num2/2;
		printf("%d과 %d를 포함하여 그 사이에 있는 정수들의 합 : %d\n",num1,num2,sum);
	}


	return 0;
}
