#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

int main(void)
{
	char string1[MAX_STRING];
	char string2[MAX_STRING];
	int i;

	FILE * fp;

	/* 문자열 저장 과정 */
	puts("------- 문자열 입력 및 저장 -------");
	fp = fopen("q40_1.txt","w");
	fputs("첫 번째 문자열 : ", stdout);
	fgets(string1, MAX_STRING, stdin);
	fwrite(string1, sizeof(char), strlen(string1), fp);

	fputs("두 번째 문자열 : ", stdout);
	fgets(string2, MAX_STRING, stdin);
	fwrite(string2, sizeof(char), strlen(string2), fp);
	fclose(fp);

	/* 문자열 출력 과정 */
	puts("------- 저장된 문자열 출력 -------");
	fp = fopen("q40_1.txt","r");
	
	i=0;
	while(1)
	{
		fread(string1+i, sizeof(char), 1, fp);

		if(string1[i]=='\n')
		{
			string1[i+1]=0;
			break;
		}
		i++;
	}
	fprintf(stdout, "첫 번째 문자열 : %s",string1);

	i=0;
	while(1)
	{
		fread(string2+i, sizeof(char), 1, fp);

		if(string2[i]=='\n')
		{
			string2[i+1]=0;
			break;
		}
		i++;
	}
	fprintf(stdout, "두 번째 문자열 : %s",string2);

	fclose(fp);
	return 0;
}
