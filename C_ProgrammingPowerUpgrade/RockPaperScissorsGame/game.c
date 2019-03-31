/* Name : game.c	ver 2.0
 * Content : 게임 관련 함수 정의
 * Implementation : PHS
 *
 * Last modified 2018/12/26
 */
#include <time.h>
#include "common.h"
#include "game.h"

int ChoiceOfCom(void)
{
	int random;

	srand(time(NULL));
	random = rand()%3+1;

	return random;
}

int ChoiceOfMe(void)
{
	int choice;
	fputs("가위<1> 바위<2> 보<3> 종료<4> 선택? ", stdout);
	scanf("%d", &choice);
	
	return choice;
}

void WhoIsWinner(int com, int you)
{		
	if((com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
		puts("당신이 승자입니다!");
	else if(com==you)
		puts("비겼습니다.");
	else
		puts("컴퓨터가 승자이군요!");
}

/* end of file */
