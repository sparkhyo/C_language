#include <stdio.h>
#define MAX_STRING	100

void PrintAllString(FILE *);
void PrintString(int, FILE *);

int main(void)
{
	int num, i;
	int ch;

	FILE * fp = fopen("string.txt","r");
	if(fp==NULL)
	{
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	fputs("출력할 문자열 정보 입력(6이상은 전체 출력) : ", stdout);
	scanf("%d", &num);
	
	/*---------------*/
	if(num >= 6)
		PrintAllString(fp);

	else
		PrintString(num,fp);
	/*---------------*/
	  
	fclose(fp);
	puts("출력이 완료되었습니다.");

	return 0;
}
void PrintString(int n, FILE * fp)
{
	int i;
	char string[MAX_STRING];

	for(i=0; i<n-1; i++)
	{
		fgets(string, MAX_STRING, fp);
	}
	fgets(string, MAX_STRING, fp);
	fputs(string, stdout);
}
void PrintAllString(FILE * fp)
{
	int i;
	char string[MAX_STRING];
	for(i=0; i<5; i++)
	{
		fgets(string, MAX_STRING, fp);
		fputs(string, stdout);
	}
}
