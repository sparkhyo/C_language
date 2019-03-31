#include <stdio.h>

int main(void)
{
	char n1;
	int num = 0;

	fputs("Data input (Ctrl+Z to exit) : ", stdout);

	while((n1 = getchar()) != EOF)
	{
		num = num + 1;
	}

	printf("입력 된 문자의 수 : %d", num);

	return 0;
}
