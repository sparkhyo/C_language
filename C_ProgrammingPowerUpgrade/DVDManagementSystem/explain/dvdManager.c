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
#include "rentInfoAccess.h"
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

/*	함	수 : void RentDVD(void)
 *	기	능 : 고객이 DVD를 대여하는 과정 처리
 *	반	환 : void
 *
 */
void RentDVD(void)
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int registCus;
	int rentSte;

	char cusID[ID_LEN];		// 대여 고객 ID
	unsigned int rentDay;	// 대여일

	// 1. 대여할 DVD ISBN 입력 및 검증
	fputs("대여 DVD ISBN 입력 : ", stdout);
	fgets(ISBN,ISBN_LEN,stdin);

	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}

	// 2. 대여 가능한 상태인지 확인
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RENTED)
	{
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return;
	}

	// 3. 대여 절차 진행
	puts("대여가 가능합니다. 대여 과정을 진행합니다.");
	fputs("대여 고객 ID 입력 : ", stdout);
	fgets(cusID, ID_LEN, stdin);

	registCus=IsRegistID(cusID);
	if(registCus==0)
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}
	
	fputs("대여 날짜 입력 : ", stdout);
	scanf("%u", &rentDay);
	while(getchar()!='\n');

	SetDVDRented(ISBN);

	/* 대여 정보 추가 */
	AddRentList(ISBN, cusID, rentDay);

	puts("대여가 완료되었습니다.");
	getchar();
}

/*	함	수 : void ReturnDVD(void)
 *	기	능 : 고객이 DVD를 반납하는 과정 처리
 *	반	환 : void
 *
 */
void ReturnDVD()
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentSte;

	// 1. 반납할 DVD ISBN 입력 및 검증
	fputs("반납 DVD ISBN 입력 : ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}

	// 2. 반납이 가능한 대상인지 확인
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RETURNED)
	{
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return;
	}

	// 3. 반납 절차 진행
	SetDVDReturned(ISBN);
	puts("반납이 완료되었습니다.");
	getchar();
}

/*	함	수 : void ShowDVDRentAllCusInfo(void)
 *	기	능 : 특정 DVD 대여자 전체정보 출력
 *	반	환 : void
 *
 */
void ShowDVDRentAllCusInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * ptrDVDInfo;

	/* 찾을 대상의 ISBN 입력 */
	fputs("찾는 ISBN 입력 : ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	ptrDVDInfo = GetDVDPtrByISBN(ISBN);
	if(ptrDVDInfo==0)
	{
		puts("존재하지 않는 ISBN 입니다.");
		getchar();
		return;
	}
	
	PrintOutRentAllCusInfo(ISBN);
	
	puts("조회를 완료하였습니다.");
	getchar();
}

void ShowCusRentAllDVDInfo(void)
{
	char cusID[ID_LEN];
    unsigned int start;
    unsigned int end;
    cusInfo * ptrCusInfo;

    /* 찾을 대상의 ID 입력 */
    fputs("찾는 ID 입력: ", stdout);
    fgets(cusID, ID_LEN, stdin);

    ptrCusInfo = GetCusPtrByID(cusID);
    if(ptrCusInfo==0)
    {
        puts("가입되지 않는 ID 입니다.");
        getchar();
        return;
    }

    fputs("대여 기간 입력: ", stdout);
    scanf("%u %u", &start,&end);
    while(getchar()!='\n');

	if(start > end)
	{
		puts("기간 정보가 잘못 입력되었습니다.");
		getchar();
		return;
	}

    PrintOutCusAllRentInfo(cusID, start, end);

    puts("조회를 완료하였습니다.");
    getchar();
}
/* end of file */
