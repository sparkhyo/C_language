#include <stdio.h>

int main(void)
{
	int num, i;
	int ch;
	FILE * fp = fopen("character.txt","rt");
	if(fp==NULL)
	{
		puts("파일 'character.txt'가 열리지 않았습니다.");
		return -1;
	}

	puts("출력할 문자의 개수는? ");
	scanf("%d", &num);
	
	for(i=0; i<num*3; i++)
	{
		ch = fgetc(fp);
		if(ch==EOF)
		{	
			puts("");
			puts("파일의 끝에 도달하였거나 오류가 발생하였습니다.");
			return -1;
		}

		fputc(ch, stdout);
	}

	fclose(fp);
	puts("");
	puts("출력이 완료되었습니다.");

	return 0;
}
