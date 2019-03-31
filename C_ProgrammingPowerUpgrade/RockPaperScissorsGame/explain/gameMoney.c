#include "common.h"

static int gamerMoney = 1000;
static int comMoney = 1000;
static int betMoney;

void GamerGetMoney()
{
	gamerMoney += betMoney;
	comMoney -= betMoney;
}

void ComGetMoney()
{
	gamerMoney -= betMoney;
	comMoney += betMoney;
}

int GetGamerMoney()
{
	return gamerMoney;
}

int GetComMoney()
{
	return comMoney;
}

void SetGamerMoney(int setMoney)
{
	gamerMoney = setMoney;
}

void SetComMoney(int setMoney)
{
	comMoney = setMoney;
}

void SetBetMoney(int setMoney)
{
	if(setMoney > gamerMoney)
	{
		puts("소유하고 있는 금액 내에서 거세요!");
		fputs("당신의 현재 게임 머니: ", stdout);
		printf("%d", gamerMoney);
		puts("");
		return;
	}
	else if(setMoney > comMoney)
	{	
		puts("컴퓨터 소유 금액 초과입니다!");
		fputs("컴퓨터의 현재 게임 머니: ", stdout);
		printf("%d", comMoney);
		puts("");
		return;
	}
	betMoney = setMoney;
}

void ShowGamerMoney()
{
	printf("%d\n", gamerMoney);
}

void ShowComMoney()
{
	printf("%d\n", comMoney);
}
