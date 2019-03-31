/*	Name : dvdInfoAccess.c	ver 1.0
 *	Content : dvd 정보 저장 및 참조 함수들의 정의
 *	Implementation : PHS
 *
 *	Last modified 2019/01/17
 */
#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD		100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD=0;

/*	함	수 : int AddDVDInfo (char * ID, char * name, char * num)
 *	기	능 : cusInfo 할당 및 저장
 *	반	환 : 성공 시 '등록된 정보의 개수', 실패 시 0을 반환
 *
 */
int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if(numOfDVD >= MAX_DVD)
	{
		puts("메모리 공간이 부족합니다.");
		return 0;
	}

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	pDVD->rentState = RETURNED;
	pDVD->numOfRentCus = 0;
	dvdList[numOfDVD] = pDVD;

	numOfDVD++;

	return numOfDVD;
}

/*	함	수 : dvdInfo * GetDVDPtrByISNN(char * ISBN)
 *	기	능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터 반환
 *	반	환 : 등록 안된 ID의 경우 NULL 포인터 반환
 *
 */
dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	int i;

	for(i=0; i<numOfDVD; i++)
	{
		if( strcmp(dvdList[i]->ISBN, ISBN) == 0 )
			return dvdList[i];
	}

	return NULL;
}

/*	함	수 : int IsRegistISBN(char * ISBN)
 *	기	능 : 등록 된 ISBN인지 확인
 *	반	환 : 등록 되었으면 1, 아니면 0 반환
 *
 */
int IsRegistISBN(char * ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if(pDVD == NULL)
		return 0;
	else
		return 1;
}

/* end of file */
