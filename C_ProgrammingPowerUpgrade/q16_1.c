#include <stdio.h>
#include <string.h>
#define	STR_LEN	256

int main(void)
{
	char str[STR_LEN];
	int strLen=0;
	int i;

	int diff='A'-'a';	// 대문자와 소문자의 차를 계산

	fputs("문자열 입력 : ", stdout);
	gets(str);
	strLen=strlen(str);	// 입력된 문자열의 길이 계산
	
	for(i=0; i<strLen; i++)
	{
		if('a'<=str[i] && str[i]<='z')
			str[i]+=diff;

		else if('A'<=str[i] && str[i]<='Z')
			str[i]-=diff;

		else
			;
	}

	printf("%s",str);
	return 0;
}
