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

	fp = fopen("q40_1.txt","r");
	
	printf("%ld\n", strlen(string1));

	fclose(fp);
	return 0;
}
