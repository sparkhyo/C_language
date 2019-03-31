#include <stdio.h>
#define MAX_STRING	50

int main(void)
{
	int state;
	int date;
	char district[MAX_STRING]; //지역 
	char time;
	char weather[MAX_STRING];

	FILE * fp = fopen("weatherInfo.txt","w");
	if(fp == NULL)
	{
		puts("파일 'weatherInfo.txt'가 열리지 않았습니다.");
		return -1;
	}

	while(1)
	{
		puts("** 날씨 정보 입력 *******");

		fputs("날짜 : ", stdout);
		state = scanf("%d", &date);
		if(state==EOF)
			break;
		fwrite(&date, sizeof(int), 1, fp);
		while(getchar() != '\n');

		fputs("지역 : ", stdout);
		fgets(district, MAX_STRING, stdin);
		fputs(district, fp);
		
		fputs("오전(A)/오후(P) : ", stdout);
		//scanf("%c", &time);
		time = fgetc(stdin);
		fputc(time, fp);
		while(getchar() != '\n');

		fputs("날씨 : ", stdout);
		fgets(weather, MAX_STRING, stdin);
		fputs(weather, fp);

		while(getchar() != '\n');
		puts("");
	}	

	return 0;
}
