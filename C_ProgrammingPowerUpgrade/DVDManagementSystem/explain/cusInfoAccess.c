/*	Name : cusInfoAccess.c	ver 1.0
 *	Content : 고객 정보 저장 및 참조 함수들의 정의
 *	Implementation : PHS
 *
 *	Last modified 2019/01/16
 */
#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"

#define MAX_CUSTOMER	100
#define CUSDAT_FILE_NAME	"cusInfo.dat"

static cusInfo * cusList[MAX_CUSTOMER];
int numOfCustomer=0;

void StoreCusListToFile(void)
{
	int i;
	FILE * fp = fopen(CUSDAT_FILE_NAME, "wb");
	if(fp==NULL)
		return;

	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for(i=0; i<numOfCustomer; i++)
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);

	fclose(fp);
}


/*	함	수 : int AddCusInfo (char * ID, char * name, char * num)
 *	기	능 : cusInfo 할당 및 저장
 *	반	환 : 성공 시 '등록된 정보의 개수', 실패 시 0을 반환
 *
 */
int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo * pCus;

	if(numOfCustomer >= MAX_CUSTOMER)
	{
		puts("메모리 공간이 부족합니다.");
		return 0;
	}

	pCus = (cusInfo *)malloc(sizeof(cusInfo));

	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);

	cusList[numOfCustomer++] = pCus;
	
	StoreCusListToFile();

	return numOfCustomer;
}

/*	함	수 : cusInfo * GetCusPtrByID(char * ID)
 *	기	능 : 해당 ID의 정보를 담고 있는 변수의 포인터 반환
 *	반	환 : 등록 안된 ID의 경우 NULL 포인터 반환
 *
 */
cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for(i=0; i<numOfCustomer; i++)
	{
		if( strcmp(cusList[i]->ID, ID) == 0 )
			return cusList[i];
	}

	return NULL;
}

/*	함	수 : int IsRegistID(char * ID)
 *	기	능 : 가입 된 ID인지 확인
 *	반	환 : 가입 되었으면 1, 아니면 0 반환
 *
 */
int IsRegistID(char * ID)
{
	cusInfo * pCus = GetCusPtrByID(ID);

	if(pCus == NULL)
		return 0;
	else
		return 1;
}

void loadCusInfo(void)
{
	int i;
	FILE * fp = fopen(CUSDAT_FILE_NAME, "rb");

	if(fp==NULL)
		return;

	fread(&numOfCustomer, sizeof(int), 1, fp);

	for(i=0; i<numOfCustomer; i++)
	{
		cusList[i]=(cusInfo *)malloc(sizeof(cusInfo));
		fread(cusList[i], sizeof(cusInfo), 1, fp);
	}
	fclose(fp);
}

/* end of file */
