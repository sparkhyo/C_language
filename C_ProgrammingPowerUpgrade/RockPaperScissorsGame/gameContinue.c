#include "common.h"
#include "gameContinue.h"

void AskContinueGame(void)
{
	fputs("게임을 이어서 하시겠습니까? (Yes 1, No 0): ", stdout);
}

void AskSaveGame(void)
{
	fputs("게임 내용을 저장하시겠습니까? (Yes 1, No 0): ", stdout);
}

void ContinueGame(int * gamedata[4])
{
	/**/
	printf("%p\n", gamedata);
	/**/
	int buf[4];
	int i;

	FILE * fp = fopen("game.dat", "rb");
	
	fread(buf, sizeof(int), 4, fp);
	
	for(i=0; i<4; i++)
	{
		*gamedata[i] = buf[i];
	}

	for(i=0; i<4; i++)
	{
		printf("%d ", *gamedata[i]);
	}
	puts("");

	fclose(fp);
}

void SaveGame(int * gamedata[4])
{
	int buf[4];
	int i;

	FILE * fp = fopen("game.dat", "wb");
	
	for(i=0; i<4; i++)
	{
		buf[i] = *gamedata[i];
	}

	fwrite(buf, sizeof(int), 4, fp);

	for(i=0; i<4; i++)
	{
		printf("%d ", buf[i]);
	}
	puts("");

	fclose(fp);
}
