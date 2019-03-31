/*	Name : rentInfoAccess.c		ver 1.0
 *	Content : DVD 대여 정보 저장/참조 함수들의 정의
 *	Implementation : PHS
 *
 *	Last modified 2019/01/22
 */

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN	100
#define RENDAT_FILE_NAME	"rentInfo.dat"

static dvdRentInfo rentList[RENT_LEN];
int numOfRentCus;

/*	함	수 : void AddRentList(char * ISBN, char * cusID, int rentDay)
 *	기	능 : 대여 정보를 저장
 *	반	환 : void
 *
 */
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;

	StoreRentListToFile();
}

/*	함	수 : void PrintOutRentAllCusInfo(char * ISBN)
 *	기	능 : 특정 ISBN의 DVD 대여 정보 전체 출력
 *	반	환 : void
 *
 */
void PrintOutRentAllCusInfo(char * ISBN)
{
	cusInfo * pCus;
	int i;

	for(i=0; i<numOfRentCus; i++)
	{
		if( !strcmp(rentList[i].ISBN, ISBN) )
		{
			pCus = GetCusPtrByID(rentList[i].cusID);
			printf("대여일: %d \n", rentList[i].rentDay);
			ShowCustomerInfoContinue(pCus);
		}
	}

}

/*	함	수 : void PrintOutCusAllRentInfo(char *, unsigned int, unsigned int)
 *	기	능 : 일정 기간 안에 이뤄진 특정 고객의 DVD 대여 정보 출력
 *	반	환 : void
 *
 */
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end)
{
	int i;

	for(i=0; i<numOfRentCus; i++)
	{
		if( !strcmp(rentList[i].cusID, ID) )
		{
			if(start <= rentList[i].rentDay && rentList[i].rentDay <= end)
				ShowDVDRentInfoContinue(rentList[i]);
		}
	}
}

void StoreRentListToFile(void)
{
	FILE * fp = fopen(RENDAT_FILE_NAME, "wb");
	if(fp==NULL)
		return;

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	fclose(fp);
}

void loadRentInfo(void)
{
	FILE * fp = fopen(RENDAT_FILE_NAME, "rb");
	if(fp == NULL)
		return;
	
	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	fclose(fp);
}
/* end of file */
