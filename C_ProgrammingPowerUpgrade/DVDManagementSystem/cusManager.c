/*	Name : cusManager.c		ver 1.0
 *	Content : 고객 관련 업무 처리 함수들의 정의
 *	Implementation : PHS
 *
 *	Last modified 2019/01/14
 */
#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/*	함	수 : void RegistCustomer(void)
 *	기	능 : 신규 회원 가입
 *  반	환 : void
 *
 */
void RegistCustomer(void)
{
	cusInfo registCus;

	fputs("ID 입력: ", stdout);
	fgets(registCus.ID, ID_LEN, stdin);

	if(IsRegistID(registCus.ID))
	{
		puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.");
		getchar();
		return;
	}
	
	fputs("이름 입력: ", stdout);
	fgets(registCus.name, NAME_LEN, stdin);

	fputs("전화번호 입력: ", stdout);
	fgets(registCus.phoneNum, PHONE_LEN, stdin);

	if(!AddCusInfo(registCus.ID, registCus.name, registCus.phoneNum))
	{
		puts("정상적인 데이터 저장에 실패하였습니다.");
		getchar();
		return;
	}

	puts("가입이 완료되었습니다.");
	getchar();
}

/*	함	수 : void SearchCusInfo(void)
 *	기	능 : ID를 통한 회원 정보 검색
 *	반	환 : void
 *
 */
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * pCus;

	fputs("찾는 ID 입력:  ", stdout);
	fgets(ID, ID_LEN, stdin);

	pCus = GetCusPtrByID(ID);

	if(pCus == NULL)
	{
		puts("등록되지 않은 회원입니다.");
		getchar();
		return;
	}

	ShowCustomerInfo(pCus);
}

/* end of file */
