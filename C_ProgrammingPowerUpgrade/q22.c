#include <stdio.h>
#include <string.h>
#define STRING_LENGTH	100

int CharacterCompare(char*,char);

int main(void)
{
	char String[STRING_LENGTH];
	char character;
	int num;

	fputs("대상 문자열 입력 : ", stdout);
	fgets(String,STRING_LENGTH,stdin);

	fputs("세어 볼 문자 입력 : ", stdout);
	scanf("%c", &character);
	
	num = CharacterCompare(String,character);

	printf("%c의 개수 : %d\n",character,num);

	return 0;
}

int CharacterCompare(char* pString, char character)
{
	char c;
	int num = 0;
	int i = 0;
	
	while(1)
	{
		if(pString[i] == '\n')
			break;

		else if(pString[i] == character)
		{
			num++;
		}
		i++;
	}
	

	return num;
}
