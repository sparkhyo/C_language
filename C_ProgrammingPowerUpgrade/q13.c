#include <stdio.h>

int main(void)
{
	int num;
	int i;
	int ret;
	while(1)
	{
		fputs("1 이상의 정수 입력 : ", stdout);
		ret = scanf("%d", &num);

		if(ret==EOF)
			continue;
		else if(num<1)
			fputs("1 이상의 입력을 필요로 합니다. 다시 입력하세요.\n", stdout);
		else
		{
			printf("%d의 약수들\n", num);
			for(i=1; i<=num; i++)
			{
				if(num%i==0)
				{
					printf("%d ",i);
				}		
			}
			puts("");
		}
	}
	return 0;
}
