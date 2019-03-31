#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

int main(void)
{
	int com;
	int you;
	int setYouMoney;
	int setBetMoney;
	int gameData;
	int yesNo;
	int buf[4];

	FILE * fp = fopen("game.dat","rb");
	gameData = fread(buf, sizeof(int), 4, fp);
	fclose(fp);

	if( gameData>0 && buf[0]>0 && buf[1]>0 )
	{
		fputs("게임을 이어서 하시겠습니까? <Yes 1, No 0>: ", stdout);
		scanf("%d", &yesNo);

		if(yesNo == 1)
		{ 
			LoadData();
			printf("당신의 게임 머니: %d\n", GetGamerMoney() );
			printf("컴퓨터 게임 머니: %d\n\n", GetComMoney() );
		}
		else
		{
			puts("자! 게임을 시작합니다.");
			puts(""), puts("");
			fputs("# 당신의 머니를 입력하세요: ", stdout);
			scanf("%d", &setYouMoney);
			SetGamerMoney(setYouMoney);
			fputs("당신의 게임 머니: ", stdout);
			ShowGamerMoney();
			fputs("컴퓨터 게임 머니: ", stdout);
			ShowComMoney();
			puts(""), puts("");
		}
	}
	else
	{
		puts("자! 게임을 시작합니다.");
		puts(""), puts("");
		fputs("# 당신의 머니를 입력하세요: ", stdout);
		scanf("%d", &setYouMoney);
		SetGamerMoney(setYouMoney);
		fputs("당신의 게임 머니: ", stdout);
		ShowGamerMoney();
		fputs("컴퓨터 게임 머니: ", stdout);
		ShowComMoney();
		puts(""), puts("");
	}

	while(1)
	{
		while(1)
		{
			puts("& 판돈을 설정합니다! &");
			fputs("판돈 입력: ", stdout);
			scanf("%d", &setBetMoney);
			SetBetMoney(setBetMoney);
			puts("");
			
			if( setBetMoney <= GetGamerMoney() && setBetMoney <= GetComMoney())
				break;
		}


		puts("###### 대결! ######!!");
		com=ChoiceOfCom();
		you=ChoiceOfMe();
		puts("");
		
		if(you == EXIT)
			break;
		
		puts("###### 결과! ######!!");
		WhoIsWinner(com, you);

		fputs("컴퓨터의 선택 : ", stdout);
		ShowRSP(com);
		puts("");

		fputs("당신의 선택 : ", stdout);
		ShowRSP(you);
		puts("");

		printf("승률: %d %% \n\n", GetPercenOfVictory());

		printf("게이머 머니: %d \n", GetGamerMoney());
		printf("컴퓨터 머니: %d \n\n", GetComMoney());

		if( GetGamerMoney() <= 0 || GetComMoney() <= 0 )
		{
			SaveData();
			break;
		}
	}

	puts("###### 최종 결과 ######");
	printf("최종 승률: %d %% \n", GetPercenOfVictory());
	fputs("게임 내용을 저장하시겠습니까? <Yes 1, No 0>: ", stdout);
	scanf("%d", &yesNo);
	if(yesNo == 1){ SaveData(); }

	puts("이용해 주셔서 고마워요~");
	
	return 0;
}
