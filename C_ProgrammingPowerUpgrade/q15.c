#include <stdio.h>

int main(void)
{
	char c;

	while(1)
	{
		c=getchar();

		if(c==EOF)
			break;

		else if(c>='a' && c <= 'z')
			fputs("입력하신 문자는 알파벳 소문자입니다.\n", stdout);

		else if(c>='A' && c <= 'Z')
			fputs("입력하신 문자는 알파벳 대문자입니다.\n", stdout);

		else if(c>='0' && c <= '9')
			fputs("입력하신 문자는 아라비아숫자입니다.\n", stdout);

		else
			fputs("특수문자를 입력하셨군요.\n", stdout);

		while(getchar() != '\n');
	}

	puts("프로그램을 종료합니다.");

	return 0;
}
