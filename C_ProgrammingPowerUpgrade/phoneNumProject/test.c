#include <stdio.h>

int main()
{
	char num[100];

	while(1)
	{
		fputs("번호 입력", stdout);
		scanf("%s",num);
		printf("%s",num);
	}
	return 0;
}
