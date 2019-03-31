/* Name : game.c	ver 2.0
 * Content : 게임 관련 함수 정의
 * Implementation : PHS
 *
 * Last modified 2018/12/26
 */
#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

int ChoiceOfCom(void)
{
	srand((unsigned int)time(NULL));
	return rand()%3+1;
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
	/*
	if((com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
		puts("당신이 승자입니다!");
	else if(com==you)
		puts("비겼습니다.");
	else
		puts("컴퓨터가 승자이군요!");
	*/

	int outcome = you-com;

	IncreGameTimes();

	switch(outcome)
	{
		case 0:	/* 비길 경우 */
			puts("비겼습니다.");
			return;
			
		case 1: case -2:	/* 게이머가 이길 경우 */
			puts("당신이 승자입니다.");
			IncreYouWinTimes();
			GamerGetMoney();
			return;
	}

	puts("컴퓨터가 승자이군요!");
	ComGetMoney();
}

void ShowRSP(int rsp)
{
	switch(rsp)
	{
		case SCISSORS:
			fputs("가위", stdout);
			break;

		case ROCK:
			fputs("바위", stdout);
			break;

		case PAPER:
			fputs("보", stdout);
			break;
	}
}
/* end of file */
