#include <stdio.h>
#define MAX_STRING	50

int main(void)
{
	int date;
	char district[MAX_STRING]; //지역 
	char time;
	char weather[MAX_STRING];

	FILE * fp = fopen("weatherInfo.txt","r");
	if(fp == NULL)
	{
		puts("파일 'weatherInfo.txt'가 열리지 않았습니다.");
		return -1;
	}

	while(1)
	{
		fread(&date, sizeof(int), 1, fp);
		if(feof(fp) != 0)
			break;
		fputs("날짜 : ", stdout);
		printf("%d\n", date);

		fputs("지역 : ", stdout);
		fgets(district, MAX_STRING, fp);
		fputs(district, stdout);

		fputs("오전(A)/오후(P) : ", stdout);
		time = fgetc(fp);
		fputc(time, stdout);
		puts("");

		fputs("날씨 : ", stdout);
		fgets(weather, MAX_STRING, fp);
		fputs(weather, stdout);

		puts("");
	}	

	fclose(fp);
	puts("출력이 완료되었습니다.");
	return 0;
}
