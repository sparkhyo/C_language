#include "common.h"
#include "gameMoney.h"
#include "gameTimes.h"

static int gamerMoney;
static int comMoney;
static int gameNumOfTimes;
static int youWinNumOfTimes;


void SaveData(void)
{
	gamerMoney = GetGamerMoney();
	comMoney = GetComMoney();
	gameNumOfTimes = GetGameTimes();
	youWinNumOfTimes = GetYouWinTimes();

	FILE * fp = fopen("game.dat", "wb");

	fwrite(&gamerMoney, sizeof(int), 1, fp);
	fwrite(&comMoney, sizeof(int), 1, fp);
	fwrite(&gameNumOfTimes, sizeof(int), 1, fp);
	fwrite(&youWinNumOfTimes, sizeof(int), 1, fp);

	fclose(fp);
}

void LoadData(void)
{
	FILE * fp = fopen("game.dat", "rb");

	fread(&gamerMoney, sizeof(int), 1, fp);
	fread(&comMoney, sizeof(int), 1, fp);
	fread(&gameNumOfTimes, sizeof(int), 1, fp);
	fread(&youWinNumOfTimes, sizeof(int), 1, fp);

	fclose(fp);

	SetGamerMoney(gamerMoney);
	SetComMoney(comMoney);
	SetGameNumOfTimes(gameNumOfTimes);
	SetYouWinNumOfTimes(youWinNumOfTimes);
}
