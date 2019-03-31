/* Name : main.c	ver 2.0
 * Content : 게임 main 함수
 * Implementation : PHS
 * 
 * Last modified 2018/1/6
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

int main(void)
{
	int com;
	int you;
	int gameCount = 0;
	int youWin = 0;
	int winRate = 0;
	int gamerMoney = 1000;
	int computerMoney = 1000;
	int winMoney = 200;
	int yesno;
	int data;
	char * RPS[3] = {"가위", "바위", "보"};
	int *gamedata[4] = {&gamerMoney, &computerMoney, &gameCount, &youWin};
	int buffer[4];

	FILE * fp;
	fp = fopen("game.dat", "rb");
	data = fread(buffer, sizeof(int), 4, fp);
	fclose(fp);

	if( (data>0) && (buffer[0]>0) && (buffer[1]>0) )
	{
		AskContinueGame();
		scanf("%d", &yesno);

		if(yesno == 1)
		{
			ContinueGame(gamedata);
		}
		else if(yesno == 0)
	    {
			puts("자! 게임을 시작합니다.");
			puts("");
			fputs("# 당신의 머니를 입력하세요: ", stdout);
			scanf("%d", &gamerMoney);
			puts("");
		}		
	}
	else
	{
		puts("자! 게임을 시작합니다.");
		puts("");
		fputs("# 당신의 머니를 입력하세요: ", stdout);
		scanf("%d", &gamerMoney);
		puts("");	
	}
		

	printf("당신의 게임 머니: %d \n", gamerMoney);
	printf("컴퓨터 게임 머니: %d \n", computerMoney);
	puts("");

	while(1)
	{
		puts("$ 판돈 설정합니다! $");
		fputs("판돈 입력: ", stdout);
		SetWinMoney(&winMoney, &gamerMoney, &computerMoney);
		puts("");
		
		puts("####### 대결! #######!!");
		com=ChoiceOfCom();
		you=ChoiceOfMe();
		puts("");
		
		if(you==EXIT)
			break;

		GameCount(&gameCount);
		YouWin(com, you, &youWin);

		puts("####### 결과! #######!!");
		WhoIsWinner(com, you);

		printf("@ 컴퓨터의 선택: %s \n", RPS[com-1]);
		printf("@ 당신의 선택: %s \n", RPS[you-1]);

		fputs("승률: ", stdout);
		winRate = WinRate(&gameCount, &youWin);
		printf("%d %% \n", winRate);

		WinnerGetMoney(com, you, &computerMoney, &gamerMoney, winMoney);
		printf("게이머 머니: %d \n", gamerMoney);
		printf("컴퓨터 머니: %d \n", computerMoney);
		

		if(computerMoney==0 || gamerMoney==0)
		{
			SaveGame(gamedata);
			break;
		}
		puts("");
	}
	
	puts("$$$$$ 최종 결과 $$$$$");
	fputs("최종 승률: ",stdout);
	printf("%d %%", winRate);
	puts("");
	
	if(you==EXIT)
	{
		AskSaveGame();
		scanf("%d", &yesno);

		if(yesno == 1)
		{
			SaveGame(gamedata);	
		}
	}

	puts("이용해 주셔서 고마워요~");

	return 0;
}
