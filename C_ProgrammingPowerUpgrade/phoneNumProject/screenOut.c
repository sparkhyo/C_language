/* Name: screenOut.c  ver 1.3
 * Content:
 * Implementation: PHS
 * 
 * Last modified 2018/11/20
 */

#include "common.h"
#include "phoneData.h"

void ShowMenu(void)
{
    system("clear");   //stdlib.h
    
    printf("-------메뉴-------\n");
    printf(" 1. 전화번호 입력 \n");
    printf(" 2. 전체 정보 출력 \n");
	printf(" 3. 전화번호 검색 \n");
	printf(" 4. 전화번호 삭제 \n");
	printf(" 5. 전화번호 변경 \n");
    printf(" 6. 종료 \n");
    printf("------------------\n");
    printf("선택> ");
}

void ShowPhoneInfo(phoneData phone)
{    
    printf("---------------------------\n"   );
    printf("| > 이름 : %s \n", phone.name           );
    printf("| > 전화번호 : %s \n", phone.phoneNum   );
    printf("---------------------------\n\n" );
}

void ShowPhoneInfoByPtr(const phoneData * pPhone)
{
    printf("---------------------------\n"   );
    printf("| > 이름 : %s \n", pPhone->name           );
    printf("| > 전화번호 : %s \n", pPhone->phoneNum   );
    printf("---------------------------\n\n" );
}

/* end of file */
