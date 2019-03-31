#include <stdio.h>
#define	STR_LEN		50
#define BOOK_INFO_NUM	3

typedef struct __bookInfo
{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
} bookInfo;

int main(void)
{
	int i;
	bookInfo BookInfo[BOOK_INFO_NUM];

	puts("********* 도서 정보 입력 *********");
	for(i=0; i<BOOK_INFO_NUM; i++)
	{
		printf("%d번째 도서 정보 입력. \n", (i+1));

		fputs("도서 제목 : ", stdout);
		fgets(BookInfo[i].bookTitle, STR_LEN, stdin);

		fputs("출판사 명 : ", stdout);
		fgets(BookInfo[i].bookPub, STR_LEN, stdin);

		fputs("도서 가격 : ", stdout);
		scanf("%d", &BookInfo[i].bookPrice);
		while(getchar()!='\n');

		printf("%d번째 입력 완료.......\n\n", (i+1));
	}

	puts("********* 도서 정보 출력 *********");
	for(i=0; i<BOOK_INFO_NUM; i++)
	{
		printf("%d번째 도서 정보 출력. \n", (i+1));
		printf("도서 제목 : %s \n", BookInfo[i].bookTitle);
		printf("출판사 명 : %s \n", BookInfo[i].bookPub);
		printf("도서 가격 : %d \n\n", BookInfo[i].bookPrice);
	}
	return 0;
}
