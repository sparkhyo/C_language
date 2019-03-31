#include <stdio.h>
#include <string.h>

#define MAX_STRING	100
#define READ_CNT	100
int main(void)
{
	//int ch;
	int readCnt;

	char src[MAX_STRING];
	char dest[MAX_STRING];
	char dataBuff[READ_CNT];

	FILE * fp_src;
	FILE * fp_dest;

	fputs("원본 이름 : ", stdout);
	gets(src);	// 파일 이름이므로 fgets 불가!!

	fputs("복사본 이름 : ", stdout);
	gets(dest);

	fp_src = fopen(src, "rb");
	if(fp_src==NULL)
		puts("원본 파일을 열지 못했습니다.");

	fp_dest = fopen(dest, "wb");
	if(fp_dest==NULL)
		puts("복사본을 생성을 못했습니다.");

	//while((ch=fgetc(fp_src)) != EOF)
	//	fputc(ch, fp_dest);
	while(1)
	{
		readCnt=fread(dataBuff, 1, READ_CNT, fp_src);
		if(readCnt<READ_CNT)
		{
			if(feof(fp_src) != 0)
			{
				fwrite(dataBuff, 1, readCnt, fp_dest);
				break;
			}
			else
			{
				puts("오류 발생! 복사를 완료하지 못했습니다.");
				return -1;
			}
		}
		fwrite(dataBuff, 1, readCnt, fp_dest);
	}

	puts("복사가 완료되었습니다.");
	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}
