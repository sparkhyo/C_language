#include <stdio.h>
#define MAX_STRING	100

int main(void)
{	
	int i;
	char str[MAX_STRING];
	
	FILE * fp = fopen("string.txt", "w");
	if(fp==NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}
	
	for(i=0; i<5; i++)
	{
		printf("%d 번째 문자열 입력 : ", i+1);
		fgets(str, MAX_STRING, stdin);
		fputs(str, fp);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");

	return 0;
}
