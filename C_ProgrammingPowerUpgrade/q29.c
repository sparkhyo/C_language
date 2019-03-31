#include <stdio.h>
#include <string.h>
#define	STR_LEN		50
#define BOOK_INFO_NUM	3

typedef struct __bookInfo
{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
} bookInfo;

int numOfData = 0;
bookInfo bookInfoList[BOOK_INFO_NUM];
bookInfo * bookInfoListPointer[BOOK_INFO_NUM];

int InsertList(bookInfo* bookPtr);
void BookTitleSort();
void BookPubSort();
void BookPriceSort();

int main(void)
{
	int i, num, sortMethod;
	bookInfo book;
	
	puts("********* 도서 정보 입력 *********");
	for(i=0; i<BOOK_INFO_NUM; i++)
	{
		printf("%d번째 도서 정보 입력. \n", (i+1));

		fputs("도서 제목 : ", stdout);
		fgets(book.bookTitle, STR_LEN, stdin);

		fputs("출판사 명 : ", stdout);
		fgets(book.bookPub, STR_LEN, stdin);

		fputs("도서 가격 : ", stdout);
		scanf("%d", &book.bookPrice);
		while(getchar()!='\n');
		
		num = InsertList(&book);
		if(num==-1)
			printf("입력에 실패하였습니다. \n");
		else
			printf("%d번째 입력 완료.......\n\n", num);
	}
	
	for(i=0; i < BOOK_INFO_NUM; i++)
		bookInfoListPointer[i] = &bookInfoList[i];

	while(1)
	{
		puts("********* 도서 정보 출력 *********");
		puts("정렬 방식 선택.......");
		puts("1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료");
		fputs("그대의 선택은?", stdout);
		scanf("%d",&sortMethod);
		
		if(sortMethod == 1)
		{
			BookTitleSort();
			for(i=0; i<BOOK_INFO_NUM; i++)
			{
				printf("%d번째 도서 정보 출력. \n", (i+1));
				printf("도서 제목 : %s \n", bookInfoListPointer[i]->bookTitle);
				printf("출판사 명 : %s \n", bookInfoListPointer[i]->bookPub);
				printf("도서 가격 : %d \n\n", bookInfoListPointer[i]->bookPrice);
			}
		}

		else if(sortMethod == 2)
		{
			BookPubSort();
			for(i=0; i<BOOK_INFO_NUM; i++)
			{
				printf("%d번째 도서 정보 출력. \n", (i+1));
				printf("도서 제목 : %s \n", bookInfoListPointer[i]->bookTitle);
				printf("출판사 명 : %s \n", bookInfoListPointer[i]->bookPub);
				printf("도서 가격 : %d \n\n", bookInfoListPointer[i]->bookPrice);
			}
		}

		else if(sortMethod == 3)
		{
			BookPriceSort();
			for(i=0; i<BOOK_INFO_NUM; i++)
			{
				printf("%d번째 도서 정보 출력. \n", (i+1));
				printf("도서 제목 : %s \n", bookInfoListPointer[i]->bookTitle);
				printf("출판사 명 : %s \n", bookInfoListPointer[i]->bookPub);
				printf("도서 가격 : %d \n\n", bookInfoListPointer[i]->bookPrice);
			}
		}

		else if(sortMethod == 4)
			break;

		else
		{
			puts("정렬 방식을 다시 선택 해주세요.\n");
			continue;
		}

	}
	return 0;
}

int InsertList(bookInfo * bookPtr)
{
	int idx;
	int inputIdx=numOfData;

	if(numOfData >= BOOK_INFO_NUM)
		return -1;

	/** 입력 위치 찾기 **/
	for(idx = 0; idx < numOfData; idx++)
	{
		if(strcmp(bookInfoList[idx].bookTitle, bookPtr->bookTitle) > 0)
		{
			inputIdx=idx;
			break;
		}
	}

	/** 입력이 가능하도록 자리를 마련 **/
	for(idx = numOfData; idx > inputIdx; idx--)
		bookInfoList[idx]=bookInfoList[idx-1];

	/** 새로운 데이터 입력 **/
	bookInfoList[inputIdx] = (*bookPtr);
	
	/** 입력 성공 시 입력된 데이터 개수 반환 **/
	return ++numOfData;
}

void BookTitleSort()
{
	bookInfo * temp;
	int i,j;

	for(i=0; i<BOOK_INFO_NUM-1; i++)
	{
		for(j=0; j<(BOOK_INFO_NUM-i)-1; j++)
		{
			if(strcmp(bookInfoListPointer[j] -> bookTitle, bookInfoListPointer[j+1] -> bookTitle) > 0)
			{
				temp = bookInfoListPointer[j];
				bookInfoListPointer[j] = bookInfoListPointer[j+1];
				bookInfoListPointer[j+1] = temp;
			}
		}
	}
}

void BookPubSort()
{
	bookInfo * temp;
	int i,j;

	for(i=0; i<BOOK_INFO_NUM-1; i++)
	{
		for(j=0; j<(BOOK_INFO_NUM-i)-1; j++)
		{
			if(strcmp(bookInfoListPointer[j] -> bookPub, bookInfoListPointer[j+1] -> bookPub) > 0)
			{
				temp = bookInfoListPointer[j];
				bookInfoListPointer[j] = bookInfoListPointer[j+1];
				bookInfoListPointer[j+1] = temp;
			}
		}
	}
}

void BookPriceSort()
{
	bookInfo * temp;
	int i,j;

	for(i=0; i<BOOK_INFO_NUM-1; i++)
	{
		for(j=0; j<(BOOK_INFO_NUM-i)-1; j++)
		{
			if(bookInfoListPointer[j] -> bookPrice > bookInfoListPointer[j+1] -> bookPrice)
			{
				temp = bookInfoListPointer[j];
				bookInfoListPointer[j] = bookInfoListPointer[j+1];
				bookInfoListPointer[j+1] = temp;
			}
		}
	}
}
