#include <stdio.h>

int main(void)
{
	int input, i;
	int min=0, max=0;
	int sum=0;
	int num=7;
	double avg;

	fputs("정수형 데이터 입력 : ",stdout);
	scanf("%d",&input);
	max = input;
	min = input;
	sum = sum + input;

	for(i=0; i<num-1; i++)
	{
		fputs("정수형 데이터 입력 : ", stdout);
		scanf("%d",&input);
		if(max<input)
			max = input;
		if(min>input)
			min = input;
		sum = sum + input;
	}
	avg = (double)sum/(double)num;

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
	printf("전체합 : %d\n", sum);
	printf("평  균 : %lf\n", avg);

	return 0;
}
