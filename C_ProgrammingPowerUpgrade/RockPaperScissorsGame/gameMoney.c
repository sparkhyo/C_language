#include "common.h"
#include "gameMoney.h"

void WinnerGetMoney(int com, int you, int *computerMoney, int * gamerMoney, int winMoney)
{
	if((com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
	{
		*computerMoney -= winMoney;
		*gamerMoney += winMoney;
	}
	else if((you==1 && com==2) || (you==2 && com==3) || (you==3 && com==1))
	{
		*computerMoney += winMoney;
		*gamerMoney -= winMoney;
	}
	else
		return;
}

void SetWinMoney(int *winMoney, int *gamerMoney, int *computerMoney)
{
	while(1)
	{
		scanf("%d", winMoney);
		
		if(*winMoney > *gamerMoney)
		{
			puts("소유하고 있는 금액 내에서 거세요!");
			printf("당신의 현재 게임 머니: %d \n", *gamerMoney);
			puts("$ 판돈 설정합니다! $");
         	fputs("판돈 입력: ", stdout);
		}
		else if(*winMoney > *computerMoney)
		{
			puts("컴퓨터 소유 금액 초과입니다!");
			printf("컴퓨터의 현재 게임 머니: %d \n", *computerMoney);
			puts("$ 판돈 설정합니다! $");
         	fputs("판돈 입력: ", stdout);
		}
		else
			return;
	}
}
