#include "common.h"
#include "gameTimes.h"

void GameCount(int * gameCount)
{
	*gameCount += 1;
}

void YouWin(int com, int you, int * youWin)
{
	if((com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
		*youWin += 1;
	else
		*youWin = *youWin;
}

int WinRate(int * gameCount, int * youWin)
{	
	int winRate;
	winRate = (double) (*youWin) / (*gameCount) * 100;
	return winRate;
}
