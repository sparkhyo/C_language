/*	Name : dvdManager.c		ver 1.0
 *	Content : 고객 관련 업무 처리 함수들의 정의
 *	Implementation : PHS
 *
 *	Last modified 2019/01/17
 */
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/*	함	수 : void RegistDVD(void)
 *	기	능 : 신규 회원 가입
 *  반	환 : void
 *
 */
void RegistDVD(void)
{
	dvdInfo registDVD;
	int inputGenre = 0;

	fputs("ISBN 입력: ", stdout);
	fgets(registDVD.ISBN, ISBN_LEN, stdin);

	if(IsRegistISBN(registDVD.ISBN))
	{
		puts("해당 ISBN은 이미 등록되었습니다.");
		getchar();
		return;
	}
	
	fputs("제목 입력: ", stdout);
	fgets(registDVD.title, TITLE_LEN, stdin);

	fputs("장르 입력: <액션 1, 코믹 2, SF 3, 로맨틱 4>: ", stdout);
	scanf("%d", &inputGenre);
	while(getchar() != '\n');

	registDVD.genre = inputGenre;

	if(!AddDVDInfo(registDVD.ISBN, registDVD.title, registDVD.genre))
	{
		puts("정상적인 데이터 저장에 실패하였습니다.");
		getchar();
		return;
	}

	puts("등록이 완료되었습니다.");
	getchar();
}

/*	함	수 : void SearchDVDInfo(void)
 *	기	능 : ISBN를 통한 DVD 정보 검색
 *	반	환 : void
 *
 */
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * pDVD;

	fputs("찾는 ISBN 입력:  ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	pDVD = GetDVDPtrByISBN(ISBN);

	if(pDVD == NULL)
	{
		puts("등록되지 않은 DVD입니다.");
		getchar();
		return;
	}

	ShowDVDInfo(pDVD);
}

void RentDVD(void)
{
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	unsigned int rentDay;
	dvdInfo * pDVD;

	fputs("대여 DVD ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);
	
	pDVD = GetDVDPtrByISBN(ISBN);

	if((pDVD != NULL) && (pDVD->rentState == RETURNED) )
		puts("대여가 가능합니다. 대여 과정을 진행합니다.");

	else if((pDVD != NULL) && (pDVD->rentState == RENTED))
	{
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return;
	}
	else if(pDVD == NULL)
	{
		puts("등록되지 않은 DVD입니다.");
		getchar();
		return;
	}
	
	fputs("대여 고객 ID 입력: ", stdout);
	fgets(ID, ID_LEN, stdin);

	if( !IsRegistID(ID) )
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}

	fputs("대여 날짜 입력: ", stdout);
	scanf("%d", &rentDay);
	while(getchar() != '\n');

	strcpy(pDVD->rentList[pDVD->numOfRentCus].cusID, ID);
	pDVD->rentList[pDVD->numOfRentCus].rentDay = rentDay;
	pDVD->rentState = RENTED;
	pDVD->numOfRentCus++;

	puts("대여가 완료되었습니다.");
	getchar();
	return;
}

void ReturnDVD()
{
	char ISBN[ISBN_LEN];
	dvdInfo * pDVD;

	fputs("반납 DVD ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	pDVD = GetDVDPtrByISBN(ISBN);

	if(pDVD == NULL)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}
	else if(pDVD->rentState == RETURNED)
	{
		puts("대여되지 않은 DVD입니다.");
		getchar();
		return;
	}
	
	pDVD->rentState = RETURNED;
	puts("반납이 완료되었습니다.");
	getchar();
}

void ViewDVD()
{
	int i;
	char ISBN[ISBN_LEN];
	dvdInfo * pDVD;
	cusInfo * pCus;

	fputs("찾는 ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	pDVD = GetDVDPtrByISBN(ISBN);
	
	if(pDVD == NULL)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}

	for(i=0; i<pDVD->numOfRentCus; i++)
	{
		printf("대여일: %d\n", pDVD->rentList[i].rentDay);
		pCus = GetCusPtrByID(pDVD->rentList[i].cusID);
		ShowRentCustomerInfo(pCus);
	}

	puts("조회를 완료하였습니다.");
	getchar();
}

/* end of file */
