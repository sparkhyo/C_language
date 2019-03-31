#include <stdio.h>

int main(void)
{
	int num, i;
	int oddtotal=0;
	int eventotal=0;
	fputs("자연수 입력 : ", stdout);
	scanf("%d",&num);
	
	if(num<1)
	{
		while(num<1)
		{
			fputs("자연수를 입력해주세요.\n", stdout);
			scanf("%d",&num);
		}
	}
/*
	for(i=1; i<=num; i++)
	{
		if(i%2==0)
			continue;
		total+=i;
	}
	printf("%d 이하 홀수 합 : %d\n",num,total);
	total=0;

	for(i=1; i<=num; i++)
	{
		if(i==1 || i%2==1)
			continue;
		total+=i;
	}
	printf("%d 이하 짝수 합 : %d\n",num,total);
*/
	for(i=1; i<=num; i++)
	{
		if(i%2==0)
			eventotal+=i;
		else
			oddtotal+=i;
	}
	printf("%d 이하 홀수 합 : %d\n",num,oddtotal);
	printf("%d 이하 짝수 합 : %d\n",num,eventotal);
	return 0;
}
