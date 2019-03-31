#include <stdio.h>
#include <string.h>
#define STR_LEN		50
int main(void)
{
	char bookName1[STR_LEN];
	char pubName1[STR_LEN];
	int bookPrice1;

	char bookName2[STR_LEN];
	char pubName2[STR_LEN];
	int bookPrice2;

	char bookName3[STR_LEN];
	char pubName3[STR_LEN];
	int bookPrice3;

	puts("********* 도서 정보 입력 *********");
	puts("1번째 도서 정보 입력.");
	fputs("도서 제목 : ", stdout);
	fgets(bookName1, STR_LEN, stdin);
	fputs("출판사 명 : ", stdout);
	fgets(pubName1, STR_LEN, stdin);
	fputs("도서 가격 : ", stdout);
	scanf("%d", &bookPrice1);
	while(getchar()!='\n');
	puts("1번째 입력 완료.......");
	puts("");


	puts("2번째 도서 정보 입력.");
	fputs("도서 제목 : ", stdout);
	fgets(bookName2, STR_LEN, stdin);
	fputs("출판사 명 : ", stdout);
	fgets(pubName2, STR_LEN, stdin);
	fputs("도서 가격 : ", stdout);
	scanf("%d", &bookPrice2);
	while(getchar()!='\n');
	puts("2번째 입력 완료.......");
	puts("");

	puts("3번째 도서 정보 입력.");
	fputs("도서 제목 : ", stdout);
	fgets(bookName3, STR_LEN, stdin);
	fputs("출판사 명 : ", stdout);
	fgets(pubName3, STR_LEN, stdin);
	fputs("도서 가격 : ", stdout);
	scanf("%d", &bookPrice3);
	while(getchar()!='\n');
	puts("3번째 입력 완료.......");
	puts("");

	puts("********* 도서 정보 출력 *********");
	puts("1번째 도서 정보 출력.");
	printf("도서 제목 : %s",bookName1);
	printf("출판사 명 : %s",pubName1);
	printf("도서 가격 : %d\n\n",bookPrice1);

	puts("2번째 도서 정보 출력.");
	printf("도서 제목 : %s",bookName2);
	printf("출판사 명 : %s",pubName2);
	printf("도서 가격 : %d\n\n",bookPrice2);

	puts("3번째 도서 정보 출력.");
	printf("도서 제목 : %s",bookName3);
	printf("출판사 명 : %s",pubName3);
	printf("도서 가격 : %d\n\n",bookPrice3);

	return 0;
}
