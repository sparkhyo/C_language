#include <stdio.h>

int main(void)
{	
	char writeChar[] = "가나다라마바사아자차카타파하";
	int i;

	FILE * fp = fopen("character.txt", "wt");
	if(fp==NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}
	
	for(i=0; i<sizeof(writeChar)-1; i++)
		fputc(writeChar[i], fp);

	fclose(fp);
	puts("입력이 완료되었습니다.");

	return 0;
}
