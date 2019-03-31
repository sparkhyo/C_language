#include "common.h"

static int gameNumOfTimes = 0;
static int youWinNumOfTimes = 0;

void IncreGameTimes()
{
	gameNumOfTimes++;
}

int GetGameTimes()
{
	return gameNumOfTimes;
}

void IncreYouWinTimes()
{
	youWinNumOfTimes++;
}

int GetYouWinTimes()
{
	return youWinNumOfTimes;
}

int GetPercenOfVictory()
{
	if(gameNumOfTimes==0)
		return 0;

	return (double)youWinNumOfTimes/gameNumOfTimes*100;
}

void SetGameNumOfTimes(int gameTimes)
{
	gameNumOfTimes = gameTimes;
}

void SetYouWinNumOfTimes(int youWinTimes)
{
	youWinNumOfTimes = youWinTimes;
}
