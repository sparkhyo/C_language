#include <stdio.h>
#include <string.h>
#define MAX_STRING	50

int main(void)
{
	int date, date_f;
	char district[MAX_STRING], district_f[MAX_STRING]; //지역 
	char time, time_f;
	char weather_f[MAX_STRING];

	FILE * fp = fopen("weatherInfo.txt","r");
	if(fp == NULL)
	{
		puts("파일 'weatherInfo.txt'가 열리지 않았습니다.");
		return -1;
	}
	
	fputs("검색할 날짜 및 지역 정보 입력 : ", stdout);
	scanf("%d %s %c", &date, district, &time);
	
	/* 교정을 위한 district의 교정 */
	sprintf(district, "%s\n", district);
	
	while(1)
	{
		fread(&date_f, sizeof(int), 1, fp);
		if(feof(fp) != 0)
			break;
		
		fgets(district_f, MAX_STRING, fp);

		time_f = fgetc(fp);
		
		fgets(weather_f, MAX_STRING, fp);
		
		if(date == date_f && !strcmp(district, district_f) && time == time_f)
		{
			fputs("날짜 : ", stdout);
			printf("%d\n", date_f);

			fputs("지역 : ", stdout);
			fputs(district_f, stdout);

			fputs("오전(A)/오후(P) : ", stdout);
			fputc(time_f, stdout);
			puts("");

			fputs("날씨 : ", stdout);
			fputs(weather_f, stdout);
			fclose(fp);
			puts("검색이 완료되었습니다.");
			return 0;
		}

		puts("");
	}	

	fclose(fp);
	puts("해당 날짜 및 지역의 데이터가 존재하지 않습니다.");
	return 0;

}
